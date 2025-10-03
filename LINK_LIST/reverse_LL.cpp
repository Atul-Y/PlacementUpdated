#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }

};


void Dispaly(Node *head)
{
    Node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void insertAttail(Node* &head,int val) //by reference i.e we reflect changes 
{
    Node *n=new Node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }

    Node *temp=head;
    while(temp->next!=NULL){
         temp=temp->next;
    }
    temp->next=n;

}

Node* reverseLL(Node* &head)
{
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;

}


int main()
{
    Node *head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);

    Dispaly(head);
    cout<<endl;

    Node* newhead=reverseLL(head);

    Dispaly(newhead);

  
}