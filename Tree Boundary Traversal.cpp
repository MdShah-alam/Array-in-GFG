#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void print(Node *root)
{
    if(root==NULL) return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

vector<int>v;
    void leftboundary(Node* rot)
    {
        if(rot==NULL) return ;
        if(rot->left==NULL && rot->right==NULL) return ;
        v.push_back(rot->data);
        leftboundary(rot->left);
        if(rot->left==NULL && rot->right!=NULL)
            leftboundary(rot->right);
    }
    void leafNode(Node *root)
    {
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL) v.push_back(root->data);
        leafNode(root->left);
        leafNode(root->right);
    }
    void rightboundary(Node *root)
    {
        if(root==NULL)return ;
        if(root->left==NULL && root->right==NULL) return ;
        rightboundary(root->right);
        if(root->right==NULL && root->left!=NULL)
            rightboundary(root->left);
        v.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            return v;
        }

        v.push_back(root->data);

        leftboundary(root->left);
        leafNode(root);
        rightboundary(root->right);
        return v;
    }

int main()
{
    Node *root=NULL;
    int n;
    cin>>n;
    root=new Node(n);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node *present=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;
        Node *n1=NULL, *n2=NULL;
        if(x!=-1) n1=new Node(x);
        if(y!=-1) n2=new Node(y);

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);

        present->left=n1;
        present->right=n2;
    }
    print(root);
    cout<<endl;
    vector<int>v1=boundary(root);
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;

    return 0;
}
/**

1
2 3
4 5 6 7
-1 -1 8 9 -1 -1 -1 -1
-1 -1 -1 -1

4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
4 10 5 6 8 11 3 5 8 8 6 11 11
4 10 5 6 8 11 3 5 8 8 6 11 11

4 10 5 5 8 8 6 11 11

4
10 -1
5 5
-1 6 7 -1
8 8 -1 8
11 -1 3 4 -1 1
3 -1 8 6 -1 11
11 -1 5 8 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1

*/
