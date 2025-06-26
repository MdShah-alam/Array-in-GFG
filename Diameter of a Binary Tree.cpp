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
        this->data = data;
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

int maxdiameter = 0;

int height(Node *root)
{
    if(root==NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    maxdiameter = max(maxdiameter , left+right+1);

    return max(left,right)+1;
}
int diameter(Node *root)
{
    maxdiameter = 0;
    height(root);
    return maxdiameter;
}

int main()
{
    int a;
    cin>>a;
    Node *root = new Node(a);
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL, *n2=NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        present->left = n1;
        present->right = n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    print(root);
    cout<<endl;
    cout<<diameter(root)<<endl;
    //cout<<maxdiameter<<endl;
    return 0;
}
/**

1
2 4
3 6 5 -1
-1 -1 -1 -1 -1 8
-1 -1

*/
