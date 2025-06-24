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

vector<int> topView(Node *root)
{
    vector<int>res;
    if(root==NULL) return res;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end()) mp[line] = node->val;
        if(node->left!=NULL) q.push({node->left,line-1});
        if(node->right!=NULL) q.push({node->right,line+1});
    }
    for(auto it : mp)
        res.push_back(it.second);
    return res;
}

int main()
{
    int n;
    cin>>n;
    queue<Node*>q;
    Node *root = new Node(n);
    q.push(root);
    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node *n1=NULL,*n2=NULL;
        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);
        present->left = n1;
        present->right = n2;
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }
    print(root);
    cout<<endl;

    vector<int>v = topView(root);
    for(int x : v)
        cout<<x<<" ";
    cout<<endl;
}
/**

10
20 30
40 50 60 70
-1 -1 -1 -1 -1 -1 -1 -1

*/
