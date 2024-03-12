#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
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
int main(){
    Node node1,node2;
    node1.SetData(1);
    node1.SetNext(&node2);
    node2.SetData(2);
    node2.SetNext(nullptr);
    cout << "The value in the node is : " << node1.GetData() << endl;
    cout << "The address in the node is : " << node1.GetNext() << endl;
    cout << "The address in the node is : " << &node2 << endl;
}