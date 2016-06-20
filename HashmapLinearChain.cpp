#include <iostream>
#include <cstdint>
#include <string>
#include <math.h>
#include <random>
#include <fstream>
using namespace std;

class HashMapLinearChaining {
private:
	uint32_t size;
	class Node {
        public:
		string  val;
		Node* next;
		Node(string val, Node* next) : val(val), next(next) {}
	};
	Node **table;

    uint32_t hash(string str)
    {
        uint16_t seed = 131; // 31 131 1313 13131 131313 etc..
        uint16_t hash1 = 0;
        for(size_t i = 0; i < str.length(); i++)
        {
            hash1 = (hash1 * seed) + str[i];
        }
        return hash1 ;
    }


public:


	HashMapLinearChaining(size_t initialSize)
		: size(initialSize) {
		//size = 4294967296;
		table = new Node*[size];
		for (uint32_t i = 0; i < size; i++)
			table[i] = nullptr;
	}
	~HashMapLinearChaining() {
		delete[] table;
	}
	// put in a new key with corresponding value, return true
	// if key is already there replace the value, return false
	uint32_t add(string value) {
	    uint32_t count = 0;
		uint32_t i = hash(value);
		if (table[i] == nullptr) {
			table[i] = new Node(value, nullptr);
			return 1;
		}
		else {
                count=1;
			Node * list = table[i];
			while (list->next != nullptr && list->val != value)
			{
			    list = list->next;
			    count++;
			}

			if (list->val == value)
				   return 0;
			if (list->next == nullptr) {
				list->next = new Node(value, nullptr);
				return count;
			}
		}
	}
	// find value,return tries times
	bool find(string value) {
		uint32_t i = hash(value);
		if(table[i]==nullptr)
            return false;
        else
        {
            Node* list=table[i];
            while(list->val!=value)
            {
                list=list->next;
                if(list==nullptr)
                    return false;
            }
            return true;
        }

	}



	void displayHistogram() {
		int histogram[52] = {};
		for (uint32_t i = 0; i < size; i++) {
			if (table[i] == nullptr) {
				histogram[0]++;
			}
			else {
				Node *entry = table[i];
				while (entry != nullptr) {
					int count = find(entry->val);
					if (count > 50)
						histogram[51]++;
					else
						histogram[count]++;
					entry = entry->next;
				}
			}
		}
		for (int j = 0; j < 52; j++) {
			if (j == 51) {
				cout << ">50  " << histogram[j] << endl;
			}
			else
				cout << j << "  " << histogram[j] << endl;
		}
	}


};


int main() {
	HashMapLinearChaining m(100000);

    ifstream f("dict.txt");
    string a;
    uint32_t count[50];
    for(uint32_t i=0;i<50;i++)
    {
        f>>a;
        count[i]=m.add(a);
    }

    while(getline(f,a))
    {
        m.add(a);
    }


	ifstream x("hw8.dat");
    string b;
    while(getline(x,b))
    {
        if(m.find(b))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }

    f.close();
    ifstream f2("dict.txt");
/*
    cout<<endl<<"insert"<<'\t'<<"count"<<'\t'<<endl;

    for(uint32_t i=0;i<210000;i++)
    {
        f2>>a;
        cout<<a<<'\t'<<'\t'<<count[i]<<'\t'<<endl;
    }
*/
    f2.close();
    x.close();


    m.displayHistogram();

	return 0;
}
