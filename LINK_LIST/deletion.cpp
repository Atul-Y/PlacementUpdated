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

void delete(Node *head,int key){

    Node*temp=head;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    Node *todelete=temp->next;
    temp->next=temp->next-next;
    delete todelete;
}

int main()
{
    Node *head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
 
    return 0;
}