#include<iostream>
using namespace std;
class Node{
    private :
        int data;
        Node* next;
    public:
        Node(int val);
        void SetData(int val);
        void SetNext(Node *adr);
        int GetData();
        Node* GetNext();
};
Node::Node(int val){
    data = val;
    next = nullptr;
}
void Node::SetData(int val){
    data = val;
}
void Node::SetNext(Node* adr){
    next = adr;
}
int Node::GetData(){
    return data;
}
Node* Node::GetNext(){
    return next;
}
class LinkedList{
    private :
        Node *head;
        Node *tail;
    public :
        LinkedList();
        void InsertAtBegining(int val);
        void InsertAtEnd(int val);
        void InsertAtNthPosition(int val,int position);
        int MaximumInList();
        int MinimumInList();
        void Print();
        bool SearchInList(int val);
        void AscendList();
        void DescendLIst();
        void InsertInAscending(int val);
        ~LinkedList();
};
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList(){
    Node *current = head;
    Node *next;
    while(current!= nullptr){
        next = current->GetNext();
        delete current;
        current = next;
    }
}
void LinkedList::InsertAtBegining(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->SetNext(head);
        head = newNode;
    }
}
void LinkedList::InsertAtEnd(int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void LinkedList::InsertAtNthPosition(int val, int position){
    if(position <= 0){
        cout << "Invalid Position. Please enter a position greater than zero" << endl;
        return;
    }
    Node* newNode = new Node(val);
    if(position == 1){
        newNode->SetNext(head);
        head = newNode;
        if(tail == nullptr){
            tail = newNode;
        }
        return;
    }
    Node* current = head;
    for(int i=1; i<position - 1 && current!=nullptr; i++){
        current = current->GetNext();
    }
    if(current == nullptr){
        cout << "List is not such long!!!" << endl;
        return;
    }
    newNode->SetNext(current->GetNext());
    current->SetNext(newNode);
    if(newNode == nullptr){
        tail = newNode;
    }
}
void LinkedList::InsertInAscending(int val){
    Node* newNode = new Node(val);
    if(head == nullptr || val <= head->GetData()){
        newNode->SetNext(head);
        head = newNode;
        if(tail == nullptr){
            tail = newNode;
        }
        return;
    }
    Node* current = head;
    while(current->GetNext()!=nullptr && current->GetNext()->GetData() < val){
        current = current->GetNext();
    }
    newNode->SetNext(current->GetNext());
    current->SetNext(newNode);
    if(newNode == nullptr){
        tail = newNode;
    }
}
void LinkedList::Print(){
    Node* current = head;
    while(current != nullptr){
        cout << current->GetData() << " " ;
        current = current->GetNext();
    }
    cout << endl;
}
int LinkedList::MaximumInList(){
    Node *current = head;
    int max = 0;
    while(current!=nullptr){
        if(max < current->GetData()){
            max = current->GetData();
        }
        current = current->GetNext();
    }
    return max;
}
int LinkedList::MinimumInList(){
    Node *current = head;
    int min = current->GetData();
    while(current!=nullptr){
        if(min > current->GetData()){
            min = current->GetData();
        }
        current = current->GetNext();
    }
    return min;
}
bool LinkedList::SearchInList(int val){
    Node *current = head;
    bool found = false;
    while(current!= nullptr){
        if(val == current->GetData()){
            found = true;
            return found;
        }
        current = current->GetNext();
    }
    return found;
}
void LinkedList::AscendList(){
    Node* current = head;
    Node* index;
    if(current == nullptr || current->GetNext() == nullptr){
        return;
    }
    else{
        while(current!= nullptr){
            index = current->GetNext();
            while(index!=nullptr){
                if(current->GetData() > index->GetData()){
                    int temp = current->GetData();
                    current->SetData(index->GetData());
                    index->SetData(temp);
                }
                index = index->GetNext();
            }
            current = current->GetNext();
        }
    }
}
void LinkedList::DescendLIst(){
    Node* current = head;
    Node* index;
    if(current == nullptr || current->GetNext() == nullptr){
        return;
    }
    else{
        while(current!= nullptr){
            index = current->GetNext();
            while(index!=nullptr){
                if(current->GetData() < index->GetData()){
                    int temp = current->GetData();
                    current->SetData(index->GetData());
                    index->SetData(temp);
                }
                index = index->GetNext();
            }
            current = current->GetNext();
        }
    }
}
int main(){
    LinkedList list;
    list.InsertAtBegining(1);
    list.InsertAtEnd(45);
    list.InsertAtEnd(13);
    list.InsertAtNthPosition(8,3);
    list.InsertAtBegining(45);
    list.Print();
    cout << "Maximum number in the list is : " << list.MaximumInList() << endl;
    cout << "Minimum number in the list is : " << list.MinimumInList() << endl;
    if(list.SearchInList(15)){
        cout << "Value exist in the list" << endl;
    }
    else{        
        cout << "Value does not exist in the list" << endl;
    }
    cout << "List after ascending order" << endl;
    list.AscendList();
    list.Print();
    cout << "List after descending order" << endl;
    list.DescendLIst();
    list.Print();
    cout << "2nd List inserting in ascending order" << endl;
    LinkedList list2;
    list2.InsertInAscending(5);
    list2.InsertInAscending(10);
    list2.InsertInAscending(2);
    list2.InsertInAscending(8);
    list2.Print();
}