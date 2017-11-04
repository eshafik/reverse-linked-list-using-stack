#include<iostream>
#include<stack>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head =NULL;
//create linked list
void insertNode(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void print(){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//reverse linked list using stack
void Reverse (){
    stack<struct node*>S;
    node* temp = head;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp= S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL; // next address of last node is will be NULL


}


int main(){
    insertNode(5);
    print();
    insertNode(6);
    print();
    insertNode(9);
    print();
    Reverse();
    print();

    return 0;
}

