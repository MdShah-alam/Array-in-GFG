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
    if(!root) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

vector<int>bottomView(Node *root)
{
    vector<int>ans;
    if(root==NULL) return ans;
    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int x = it.second;
        mp[x]=node->data;

        if(node->left)
            q.push({node->left,x-1});
        if(node->right)
            q.push({node->right,x+1});
    }
    for(auto x : mp){
        ans.push_back(x.second);
    }
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

        int x, y;
        cin>>x>>y;

        Node *n1=NULL, *n2=NULL;

        if(x!=-1) n1 = new Node(x);
        if(y!=-1) n2 = new Node(y);

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);

        present->left = n1;
        present->right = n2;
    }

    print(root);
    cout<<endl;

    vector<int> v = bottomView(root);

    for(int x : v)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
/**

5
2 7
1 4 -1 9
-1 -1 3 -1 8 -1
-1 -1 -1 -1

*/
