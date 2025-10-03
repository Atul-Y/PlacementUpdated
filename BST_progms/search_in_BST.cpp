#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;

    Node(int  val)
    {
    data=val;
    left=right=NULL;  
    }
};

Node* searchInBST(Node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return searchInBST(root->left,key);
    }
    else
    {
        return searchInBST(root->right,key);
    }
}

int main()
{
    Node *root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(3);

    if(searchInBST(root,3)!=NULL)
    {
        cout<<" found"<<endl;
    }
    else{
        cout<<" Not found";
    }
}

