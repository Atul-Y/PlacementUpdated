#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;


    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

int height(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}


int main()
{
    Node *root=new Node(1);
    root->right=new Node(2);
    root->left=new Node(3);
    root->left->left=new Node(4);

    cout<<height(root);

    return 0;
}