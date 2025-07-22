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
Node *findLeft(Node *root)
{
    if(root->right==NULL) return root;
    findLeft(root->right);
}
Node *helper(Node *root)
{
    if(root->right==NULL) return root->left;
    if(root->left==NULL) return root->right;
    Node * rightchild = root->right;
    Node *lastRightchld = findLeft(root->left);
    lastRightchld->right = rightchild;
    Node *temp = root->left;
    delete(root);
    return temp;
}
Node *deleteVal(Node *root, int x)
{
    if(!root) return NULL;
    if(root->data == x){
        return helper(root);
    }
    Node *dummy = root;
    while(root!=NULL){
        if(root->data > x){
            if(root->left != NULL && root->left->data == x){
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else{
            if(root->right != NULL && root->right->data == x){
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
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
        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    int x;
    cin>>x;
    Node *root1 = deleteVal(root,x);
    print(root1);
    cout<<endl;


    return 0;
}
/**

4
2 6
1 3 5 7
-1 -1 -1 -1 -1 -1 -1 -1
2

*/

