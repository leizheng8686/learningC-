#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;

#define M 4
#define N 4


class Trie
{
private:
	class Node
	{
	public:
		char val;
		bool isword;
		vector<Node*> children;

		Node(){
			val=' ';
			isword=false;
		}
		~Node(){}

		Node* findchild(char c)
		{
			for(int i=0;i<children.size();i++)
			{
				Node* p=children.at(i);
				if(p->val==c)
					return p;
			}
			return NULL;
		}
	};
	Node* root;
public:
	Trie(){
		root =  new Node();
	}

	~Trie(){}

	void add(string a){
		Node* p=root;
		if(a.length()==0)
		{
			p->isword=true;
			return;
		}
		for(int i=0;i<a.length();i++)
		{
			Node* temp=p->findchild(a[i]);
			if(temp!=NULL)
			{
				p=temp;
			}
			else
			{
				Node* temp2=new Node();
				temp2->val=a[i];
				p->children.push_back(temp2);
				p=temp2;
			}
			if(i==a.length()-1)
				p->isword=true;
		}
	}

	bool search(string a){
		Node* p=root;
		for(int i=0;i<a.length();i++)
		{
			Node* temp=p->findchild(a[i]);
			if(temp!=NULL)
			{
				p=temp;
			}
			else
			{
				return false;
			}
			if(i==a.length()-1)
			{
				if(p->isword==true)
					return true;
				else
					return false;
			}
		}
	}

	bool containprefix(string a)
	{
		Node* p=root;
		for(int i=0;i<a.length();i++)
		{
			Node* temp = p->findchild(a[i]);
			if(temp==NULL)
			{
				return false;
			}
			else
			{
				p=temp;
			}
			if(i==a.length()-1)
				return true;
		}
	}

};

void findunit(char a[M][N], bool b[M][N], Trie dict,int i,int j,string& str)
{
	b[i][j]=true;
	str=str+a[i][j];

	if(dict.containprefix(str))
	{
		if(dict.search(str))
		{
			if(str.length()>=3)
				cout<<str<<'\t';
		}
		for(int row=i-1;row<=i+1&&row<M;row++)
		{
			for(int col=j-1;col<=j+1&&col<N;col++)
			{
				if(row==i&&col==j)
					continue;
				if(col>=0&&row>=0&&b[col][row]==0)
				{
					findunit(a,b,dict,row,col,str);
				}
			}
		}
	}

	str.erase(str.length()-1);
	b[i][j]=false;
	
	
}

void findtotal(char a[M][N],Trie dict)
{
	string str="";
	bool b[M][N]={{false}};
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			findunit(a,b,dict,i,j,str);

}



int main()
{
	Trie dict1;
	ifstream f("dictionary.txt");
	string a;
	while(getline(f,a))
	{
		dict1.add(a);
	}
	f.close();


	ifstream x("boggle.dat");
	int dimension;
	x>>dimension;

	char boggle[4][4];

	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			x>>boggle[i][j];

	x.close();

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<boggle[i][j]<<' ';
		cout<<endl;
	}

    findtotal(boggle,dict1);
}