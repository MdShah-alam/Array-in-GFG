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

int helper(Node *root, int &maxi)
{
    if(!root) return 0;
    int leftsum = helper(root->left,maxi);
    int rightsum = helper(root->right ,maxi);
    maxi = max(maxi, leftsum+rightsum+root->data);
    return root->data + max(leftsum, rightsum);
}
int maxPath(Node *root)
{
    int x=0;
    int ans = helper(root,x);
    return max(ans,x);
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
    cout<<maxPath(root)<<endl;
}

/**

3
4 1
-10 4 -1 -1
-1 -1 -1 -1

*/
