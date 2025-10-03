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
int height(Node * root)
{
    if(root==NULL)
    {
        return 0;  //bec empty node of tree is zero
    }
    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;

}

bool isBalancedBST(Node *root)
{
    if(root==NULL)
    {
        return true;
    }
    if(isBalancedBST(root->left)==false)
    {
        return false;
    }

    if(isBalancedBST(root->right)==false)
    {
        return false;
    }
    
    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else
    {
        false;
    }

}




int main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->left->left=new Node(5);
    root->right=new Node(4);

    if(isBalancedBST(root))
    {
        cout<<"HEIGHT BALANCED TREE";
    }
    else
    {
        cout<<"NOT HEIGHT BALANCED TREE";
    }

    return 0;
}