#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void print(Node *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

Node *lca(Node *root, int a, int b)
{
    if(!root) return NULL;
    if(root->val==a || root->val==b) return root;

    Node *Llca = lca(root->left,a,b);
    Node *Rlca = lca(root->right,a,b);

    if(Llca!=NULL && Rlca!=NULL) return root;
    else if(Llca) return Llca;
    return Rlca;
}
int height(Node *root, int x)
{
    if(!root) return 1e9;
    if(root->val == x) return 0;
    return 1+min(height(root->left,x),height(root->right,x));
}
int findDist(Node* root, int a, int b)
{
    if(!root) return 0;
    Node *ancestor = lca(root,a,b);
    int h1 = height(ancestor,a);
    int h2 = height(ancestor,b);
    return h1+h2;
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
    print(root);
    cout<<endl;

    int a,b;
    cin>>a>>b;
    cout<<findDist(root,a,b)<<endl;
    return 0;
}
/**

1
2 3
4 5 -1 6
7 -1 10 -1 -1 11
15 -1 -1 -1 -1 20
-1 -1 -1 -1

4
2 6
1 3 -1 -1
-1 -1 -1 -1
1 2

*/

