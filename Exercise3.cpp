#include<iostream>
using namespace std;
class Node{
    private :
        int data;
        Node *next;
    public :
        int GetData();
        Node* GetNext();
        void SetData(int value);
        void SetNext(Node *adr);
};
void Node::SetData(int val){
    data = val;
}
void Node::SetNext(Node *adr){
    next = adr;
}
int Node::GetData(){
    return data;
}
Node* Node::GetNext(){
    return next;
}

class List{
    private:
        Node *head;
        Node *tail;
    public:
        List();
        void Print();
        void Insert(int val);
        void Delete(int val);
        void AddBetween(int position);
        ~List();
};
List::List(){
    head = nullptr;
    tail = nullptr;
}
void List:: Insert(int val){
    Node *newNode = new Node;
    newNode->SetData(val);
    newNode->SetNext(nullptr);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void List::AddBetween(int position){
    static int i= 22;
    Node* newNode = new Node;
    newNode->SetData(i);
    newNode->SetNext(nullptr);
    i=+ 7;
    if(position <= 0){
        cout << "Invalid positon!! Please enter a position greater than zero" << endl;
        return;
    }
    if(position == 1){
        newNode->SetNext(head);
        head = newNode;
        if(tail == nullptr){
            tail = newNode;
        }
    }
    Node *current = head;
    for(int i=1; i<position - 1 && current != nullptr; i++){
        current = current->GetNext();
    }
    if(current == nullptr){
        cout << "List is not such long enough invalid position!!" << endl;
        return;
    }
    newNode->SetNext(current->GetNext());
    current->SetNext(newNode);
    if(newNode->GetNext() == nullptr){
        tail = newNode;
    }
}
void List::Delete(int val){
    Node* tempNode = head;
    Node *previous;
    if(tempNode == nullptr){
        return;
    }
    else if(tempNode->GetNext() == nullptr){
        delete tempNode;
        head = nullptr;
    }
    else{
        while(tempNode != nullptr){
            if(tempNode->GetData() == val){
                break;
            }
            previous = tempNode;
            tempNode = tempNode->GetNext();
        }
    }
    previous->SetNext(tempNode->GetNext());
    delete tempNode;
    tempNode = nullptr;
}
List::~List(){
    Node *next;
    while(head!=nullptr){
        next = head->GetNext();
        delete head;
        head = next;
    }
}
void List::Print(){
    Node *current = head;
    while(current != nullptr){
        cout << current->GetData() << " ";
        current = current->GetNext();
    }
}
int main(){
    List list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(35);
    list.Delete(2);
    list.AddBetween(2);
    list.AddBetween(2);
    list.Print();
}