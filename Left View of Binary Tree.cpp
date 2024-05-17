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
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void print(Node* root)
{
    if(root==NULL) return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

vector<int> leftView(Node* root)
{
    queue<Node*>q;
    q.push(root);
    vector<int>v;

    while(!q.empty()){
        vector<int>h;
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *presentNode=q.front();
            q.pop();

            h.push_back(presentNode->data);
            if(presentNode->left!=NULL)
                q.push(presentNode->left);
            if(presentNode->right!=NULL)
                q.push(presentNode->right);
        }
//        reverse(h.begin(), h.end());
        v.push_back(h[0]);
    }
    return v;
}

int main()
{
    int a;
    cin>>a;
    Node *root=new Node(a);

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node * presentNode=q.front();
        q.pop();

        int x,y;
        cin>>x>>y;

        Node* n1=NULL;
        Node* n2=NULL;

        if(x!=-1) n1=new Node(x);
        if(y!=-1) n2=new Node(y);

        presentNode->left=n1;
        presentNode->right=n2;

        if(n1!=NULL) q.push(n1);
        if(n2!=NULL) q.push(n2);
    }

    print(root);
    cout<<endl;

    vector<int>s=leftView(root);

    for(int i=0;i<s.size(); i++)
        cout<<s[i]<<" ";
    cout<<endl;

    return 0;
}

/**

1
2 3
4 5 6 7
-1 8 -1 -1 -1 -1 -1 -1
-1 -1

1
2 3
-1 -1 -1 -1

10
20 30
40 60 -1 -1
-1 -1 -1 -1

*/
