#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void print(TreeNode *root)
{
    if(!root) return;
    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

void help(TreeNode *root,int val,int depth)
{
    if(depth==2){
        TreeNode *node = new TreeNode(val);
        if(root->left){
          TreeNode *l = root->left;
          root->left = node;
          node->left = l;
        }
        if(root->right){
            TreeNode *r = root->right;
            root->right = node;
            node->right = r;
        }
        return ;
    }
    if(root->left) help(root->left,val , depth-1);
    if(root->right) help(root->right,val,depth-1);
}
TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    if(!root) return root;
    if(depth==1){
        TreeNode *node = new TreeNode(val);
        node->left = root;
        return node;
    }
    help(root,val,depth);
    return root;
}

int main()
{
    int n;
    cin>>n;
    TreeNode *root = new TreeNode(n);
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode *present = q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        TreeNode *n1=NULL , *n2 = NULL;
        if(x!=-1) n1 = new TreeNode(x);
        if(y!=-1) n2 = new TreeNode(y);
        if(n1) q.push(n1);
        if(n2) q.push(n2);
        present->left = n1;
        present->right = n2;
    }
    print(root);
    cout<<endl;
    int x,d;
    cin>>x>>d;
    TreeNode *rot = addOneRow(root,x,d);
    print(rot);
    cout<<endl;

    return 0;
}
/**

5
3 7
1 -1 -1 10
-1 -1 9 -1
-1 -1
6 3

*/
