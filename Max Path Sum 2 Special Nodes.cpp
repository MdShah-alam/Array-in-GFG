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
        data = val;
        left = NULL;
        right = NULL;
    }
};

void print(Node *root)
{
    if(!root) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int res = INT_MIN;
int helper(Node *root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;

    int l = helper(root->left);
    int r = helper(root->right);

    if(root->left && root->right){
        res = max(res, l+r+root->data);
        return root->data+max(l,r);
    }
    return root->data + (root->left ? l : r);
}
int maxPathSum(Node *root)
{
    res = INT_MIN;
    int ans = helper(root);
    return res==INT_MIN ? ans : res;
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
        Node *n1=NULL, *n2=NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    cout<<maxPathSum(root)<<endl;
}

/**

3
4 1
-10 4 -1 -1
-1 -1 -1 -1

*/

