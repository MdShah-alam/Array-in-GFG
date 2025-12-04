#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert_a_node(Node *root, int val)
{
    if(!root) return new Node(val);
    else if(root->val>val) root->left = insert_a_node(root->left, val);
    else root->right = insert_a_node(root->right, val);
    return root;
}
void print(Node *root)
{
    if(!root) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int minVal(Node *root)
{
    if(!root->left) return root->val;
    return minVal(root->left);
}
Node *delete_node(Node *root, int data)
{
    if(!root) return root;
    else if(root->val>data)
        root->left = delete_node(root->left,data);
    else if(root->val<data)
        root->right = delete_node(root->right,data);
    else{
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        root->val = minVal(root->right);
        root->right=delete_node(root->right,root->val);
    }
    return root;
}
int main()
{
    int n;
    cin>>n;
    Node *root;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root = insert_a_node(root, x);
    }
    print(root);
    cout<<endl;
    Node *rot = delete_node(root, 8);
    print(rot);
}
/**
7
10
15
7
5
9
8
13

*/
