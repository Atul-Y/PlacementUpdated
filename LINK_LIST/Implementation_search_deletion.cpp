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

bool search(Node *head,int key)
{
    if(head->data==key){
        return true;
    }
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deletion(Node* &head,int key){

    Node*temp=head;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    Node *todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void deleteAtHead(Node* &head)
{
    Node *todelete=head;
    head=head->next;

    delete todelete;
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

    // deletion(head,3);
    // cout<<endl;

    deleteAtHead(head);
    
    Dispaly(head);
    cout<<endl;

    if(search(head,5)){
        cout<<"FOUND";
    }
    else{
        cout<<"NOT FOUND";
    }
    
    return 0;
}