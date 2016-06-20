#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


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
};

int main()
{
	Trie dict1;
	ifstream f("dict.txt");
	string a;
	while(getline(f,a))
	{
		dict1.add(a);
	}
	f.close();
	ifstream f2("hw7.dat");
	string b;
	while(getline(f2,b))
	{
		if(dict1.search(b))
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
	f2.close();
}