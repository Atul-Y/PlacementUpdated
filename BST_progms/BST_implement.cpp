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
void print_inorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);

}

Node *insertBST(Node *root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }

    if(val < root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

int main()
{
    Node*root=NULL;
    root=insertBST(root,1);
    insertBST(root,2);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,6);
    insertBST(root,5);
    
    print_inorder(root);

    return 0;
}