#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}
void insertNodeAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void deleteFromBeginning(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;

    }
    else
    {
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
            
        }
        delete temp->next;
        temp->next = nullptr;
        
    }
}

void insertAfterValue(Node*& head, int target, int value){
    Node* temp = head;
    
    while(temp != nullptr){
        if(temp->data == target){
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;

    }

   
}
 void reverseLL(Node* &head){
           Node* pre= nullptr;
           Node*next= nullptr;
           Node*curr = head;
           while(curr != nullptr){
            next = curr->next;
            curr ->next = pre;
            pre = curr;
            curr = next;
           }
           head = pre;
           Node* temp = head;
           while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
           }
           cout<<"Null"<<endl;

    }

int main()
{
    Node *head = new Node(20);
    Node *second = new Node(30);
    head->next = second;
    Node *third = new Node(40);
    second->next = third;
    Node *fourth = new Node(50);
    third->next = fourth;
    Node *fifth = new Node(60);
    fourth->next = fifth;

    // insertNodeAtBeginning(head, 5);
    // insertAtEnd(head, 65);
    // insertAfterValue(head, 30, 35);
    print(head);
    reverseLL(head);

    return 0;
}