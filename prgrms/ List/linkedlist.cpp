#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* head = nullptr;

void insertAtEnd(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->link != nullptr){
        temp = temp->link;
    }
    temp->link = newNode;
}

void insertAtFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}


void display() {
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<endl;
        temp = temp->link;
    }
}



int main() {
    insertAtEnd(1);
    insertAtEnd(4);
    display();

    cout<< endl;

    insertAtFront(345);
    display();
    cout<<endl;
 
    insertAtEnd(35);
    display();
    return 0;
}