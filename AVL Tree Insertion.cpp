#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        data = val;
        this->left = NULL;
        this->right = NULL;
        height = 1;
    }
};

void print(Node *root)
{
    if(!root) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int getHeight(Node *root)
{
    return root ? root->height : 0 ;
}

int getBalance(Node *root)
{
    return root ? getHeight(root->left) - getHeight(root->right) : 0 ;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left) , getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left) , getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertToAVL(Node* node, int val)
{
    if(!node) return new Node(val);

    if(val < node->data)
        node->left = insertToAVL(node->left , val);
    else if(val > node->data)
        node->right = insertToAVL(node->right, val);
    else return node;

    node->height = 1 + max(getHeight(node->left) , getHeight(node->right));

    int balance = getBalance(node);

    if(balance > 1 && val<node->left->data) // LL
        return rightRotate(node);

    if(balance < -1 && val > node->right->data) // RR
        return leftRotate(node);

    if(balance > 1 && val > node->left->data){
        //LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if(balance < -1 && val<node->right->data){
        //RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    Node *root = NULL;
    for(int x : v){
        root = insertToAVL(root, x);
    }
    cout<<endl;
    print(root);
    cout<<endl;

    return 0;
}
/**

7
21 26 30 9 4 14 28

*/
