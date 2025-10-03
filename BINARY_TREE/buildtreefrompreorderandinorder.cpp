#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int inorder[], int start, int end, int curr)
{
    for (int i = 0; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[], int inorder[], int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    node *node1 = new node(curr);
    if (start == end)
    {
        return node1;
    }
    int pos = search(inorder, start, end, curr);
    node1->left = buildTree(preorder, inorder, start, pos - 1);
    node1->right = buildTree(preorder, inorder, pos + 1,end);
    return node1;
}
void inorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data<<" ";
    inorderprint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 3, 5};

    node *root = buildTree(preorder, inorder, 0, 4);
    inorderprint(root);
    return 0;
}