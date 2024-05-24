#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int height(Node* node)
{
    if(node==NULL) return 0;
    queue<Node*>q;
    q.push(node);
    int k=0;

    while(!q.empty()){
        int n=q.size();
        k++;
        for(int i=0;i<n;i++){
            Node *rot=q.front();
            q.pop();
            if(rot->left!=NULL) q.push(rot->left);
            if(rot->right!=NULL) q.push(rot->right);
        }
    }
    return k;
}

void print(Node *root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *node=q.front();
            q.pop();
            cout<<node->data<<" ";
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    Node *root=new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *node=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        Node *n1=NULL;
        Node *n2=NULL;
        if(x!=-1) n1=new Node(x);
        if(y!=-1) n2=new Node(y);

        node->left=n1;
        node->right=n2;
        if(n1!=NULL)q.push(n1);
        if(n2!=NULL)q.push(n2);
    }
    cout<<endl;
    print(root);
    cout<<endl<<height(root)<<endl;

    return 0;
}/**

1
2 3
4 -1 -1 -1
-1 -1

*/
