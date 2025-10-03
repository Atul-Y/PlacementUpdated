#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node*left,*right;

    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
void buildTree(Node *root,int k)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty())
    {
        Node *node=q.front();
        q.pop();

        if(node!=NULL)
        {
            if(level==k)
            {
                sum=sum+node->data;
            }

            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }

        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    cout<<sum;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(7);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    int k=2;

    buildTree(root,k);
    return 0;
}