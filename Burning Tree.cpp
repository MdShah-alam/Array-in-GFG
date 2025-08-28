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

Node *buildParentMapping(Node *root, int target, unordered_map<Node*,Node*>&parent)
{
    Node *targetNode=NULL;
    queue<Node*>q;
    q.push(root);
    parent[root]=NULL;

    while(!q.empty()){
        Node *present = q.front();
        q.pop();
        if(present->data==target) targetNode=present;
        if(present->left){
            q.push(present->left);
            parent[present->left] = present;
        }
        if(present->right){
            q.push(present->right);
            parent[present->right] = present;
        }
    }
    return targetNode;
}

int burnTree(Node *targetNode, unordered_map<Node*,Node*>&parent)
{
    unordered_map<Node*,bool>visited;
    queue<Node*>q;
    q.push(targetNode);
    visited[targetNode]=true;

    int time=0;

    while(!q.empty()){
        int size_ = q.size();
        bool burn = false;

        for(int i=0;i<size_;i++){
            Node *curr = q.front();
            q.pop();

            //left child
            if(curr->left && !visited[curr->left]){
                burn=true;
                q.push(curr->left);
                visited[curr->left] = true;
            }

            //right child
            if(curr->right && !visited[curr->right]){
                burn=true;
                q.push(curr->right);
                visited[curr->right] = true;
            }

            //right child
            if(parent[curr] && !visited[parent[curr]]){
                burn=true;
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
        if(burn)
            time++;
    }
    return time;
}

int minTime(Node *root, int target)
{
    unordered_map<Node*,Node*>parent;
    Node *targetNode = buildParentMapping(root,target,parent);
    return burnTree(targetNode,parent);
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
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    int target;
    cin>>target;
    cout<<minTime(root,target)<<endl;
    return 0;
}
/**

1
2 3
4 5 -1 7
8 -1 10 -1 -1 -1
-1 -1 -1 -1
10

*/
