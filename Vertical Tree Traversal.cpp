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

vector<vector<int>>verticalOrder(Node *root)
{
    if(root==NULL) return {};
    map<int,vector<int>>nodes;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto present = q.front();
        q.pop();
        Node *node = present.first;
        int x = present.second;
        nodes[x].push_back(node->val);
        if(node->left) q.push({node->left,x-1});
        if(node->right) q.push({node->right,x+1});
    }
    vector<vector<int>>ans;
    for(auto entry : nodes)
        ans.push_back(entry.second);
    return ans;
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
    vector<vector<int>>v = verticalOrder(root);
    for(vector<int>k : v){
        for(int x : k)
            cout<<x<<" ";
        cout<<endl;
    }
}
/**

1
2 3
4 5 -1 6
7 -1 10 -1 -1 11
15 -1 -1 -1 -1 20
-1 -1 -1 -1

*/
