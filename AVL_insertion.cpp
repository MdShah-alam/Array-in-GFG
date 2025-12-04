#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int getHeight(Node *root)
{
    return root ? root->height : 0;
}
int getBalance(Node *root)
{
    return root ? getHeight(root->left)-getHeight(root->right):0;
}
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *t1 = x->left;
    x->left = y;
    y->right = t1;
    y->height = max(getHeight(y->left),getHeight(y->right))+1;
    x->height = max(getHeight(x->left),getHeight(x->right))+1;
    return x;
}
Node* insert_a_node(Node* root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insert_a_node(root->left, val);
    else if (val > root->data)
        root->right = insert_a_node(root->right, val);
    else
        return root;  // no duplicates

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && val < root->left->data)
        return rightRotate(root);

    // RR
    if (balance < -1 && val > root->right->data)
        return leftRotate(root);

    // LR
    if (balance > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;  // no rotation needed
}

void print(Node *rot)
{
    if(!rot) return ;
    cout<<rot->data<<" ";
    print(rot->left);
    print(rot->right);
}
int main()
{
    int n;
    cin>>n;
    Node *root = NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        root = insert_a_node(root, a);
    }
    print(root);
}
