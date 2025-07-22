#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void print(Node *root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

bool isSameTree(Node *t, Node *s)
{
    if(!t && !s) return true;
    if(!t || !s) return false;
    if(t->data != s->data) return false;
    return isSameTree(t->left, s->left) && isSameTree(t->right, s->right);
}
bool isSubTree(Node* t, Node* s)
{
    if(!s) return true;
    if(!t) return false;

    if(isSameTree(t,s)) return true;

    return isSubTree(t->left, s) || isSubTree(t->right, s);
}

int main()
{
    int n;
    cin>>n;
    Node *root = new Node(n);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL,*n2=NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    cout<<endl;
    print(root);
    cout<<endl;
    int x;
    cin>>x;
    Node *root2 = new Node(x);
    q.push(root2);
    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL,*n2=NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        present->left = n1;
        present->right = n2;
    }

    cout<<endl;
    print(root2);
    cout<<endl;

    cout<<isSubTree(root,root2)<<endl;
    return 0;
}
/**

1
2 3
-1 -1 4 -1
-1 -1

3
4 -1
-1 -1

*/

