#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
    int data;
    Node* next;
    Node* prev;
   

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node* next, Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
}
};
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){

        cout<<temp->data<<"->";
       
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    print(head);
    return 0;
}