
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T val;
        Node* next;
        Node* prev;
        Node(const T& v, Node* next, Node* prev)
            : val(v), next(next), prev(prev) {}
    };
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
    }
    ~LinkedList() {
        Node* q;
        for (Node* p = head; p!= nullptr; p=q) {
            q = p->next;
            delete p;
        }
        // or
#if 0
        for (Node* p = head; p!= nullptr; ) {
            Node* q = p;
            p = p->next;
            delete q;
        }
#endif
    }
    //copy constructor
    LinkedList(const LinkedList& orig) {
#if 0
        //BAAAAAAD
        for (int i = 0; i < orig.size(); i++)
            addEnd(orig.get(i));
#endif
        if (orig.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new Node(orig.head->val, nullptr, nullptr);

        Node*q = head;
        for (Node* p = orig.head->next; p!= nullptr; p = p->next) {
            q->next = new Node(p->val, nullptr, q);

        }
    }
    void addStart(const T& v) {
        if (head == nullptr) {
            head = new Node(v, head, nullptr);
            return;
        }
        head = new Node(v, head, nullptr);
        head->next->prev = head;
    }

    void addEnd(const T& v) {
        if (head == nullptr) {
            head = new Node(v, nullptr, nullptr);
            return;
        }
        Node* p;
    for (p = head; p->next != nullptr; p = p->next)
            ;
    p->next = new Node(v, nullptr, p);
    }
    void add(const T&  v) { addStart(v); }

    void removeStart(int n){
        if(head == nullptr)
            return;
        for(int i = 0; i<n; i++){
            Node *q = head;
            head = head->next;
            head->prev = nullptr;
            delete q;
        }
    }

    void removeEnd(int n){
        if(head == nullptr)
            return;
        for(int i = 0; i<n; i++){
            Node *q = tail;
        }
    }

    void insert(const T& v, int pos) {
        Node* p = head;
        for (int i = 0; i < pos; i++)
            p = p->next;
        Node* temp = new Node(v, p->next, p);
        p->next = temp; // break the link with the node before us
        temp->next->prev = temp;
    }
    class Iterator {
    private:
        Node* p;
    public:
        Iterator(Node* p) : p(p) {}
        Iterator(const LinkedList<T>& list) {
            p = list.head;
        }
        bool notEnd() const {
            return p != nullptr;
        }
        void operator++() {
            p = p->next;
        }
        void operator--() {
            p = p->prev;
        }
        T val() const {
            return p->val;
        }
    };
    Iterator end() const {
        if (head == nullptr) {
            return Iterator(nullptr);
        }
        Node* p = head;
        for ( ; p->next != nullptr; p = p->next)
            ;
    return Iterator(p);
    }

};

int main() {
    ifstream f("C:\\Users\\86\\Documents\\GitHub\\learningC-\\DoubleLinkedlist\\HW4b.txt");
//    readfile(f);
    LinkedList<int> a;
    string func;
    int num,count=0;
    f >> func;
    while(!f.eof()){
        if(func == "ADD_FRONT"){
            f >> func;
            int fnum[20],fno=0;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                fnum[fno]=num;
                fno++;
                count++;
                f >> func;
            }
            for(int i = fno; i>0 ; i--)
                a.addStart(fnum[i-1]);
        }
        else if(func == "ADD_BACK"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count++;
                a.addEnd(num);
                f >> func;
            }
        }
        else if(func == "REMOVE_FRONT"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count -= num;
                a.removeStart(num);
                f >> func;
            }
        }
        else if(func == "REMOVE_BACK"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count -= num;
                a.removeEnd(num);
                f >> func;
            }
        }
        if(func == "OUTPUT"){
            for(int i = 0; i < count; i++)
                cout <<a.get(i)<<" ";
            cout << '\n';
            f >> func;
        }
    }
#if 1

#endif

#if 0
    int n=999;
    char fun[256];
    f >> func;
    cout << func << '\n';
    if(func == "ADD_FRONT"){
        f >> func;
    if ((func[0]<='9') && (func[0]>='0') )
        n = atoi(func.c_str());
    cout << n << '\n';
//    for (int j = 0; j < count; j++)
//        cout << a.get(j) <<'\n';
    }
#endif
}

