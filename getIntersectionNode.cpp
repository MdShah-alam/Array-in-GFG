#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        this->next = NULL;
    }
};

Node *insert_at_tail(int val,Node *head)
{
    Node *newNode = new Node(val);
    if(head==NULL)
        return newNode;
    Node *temp = head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = newNode;
    return head;
}

void print(Node *head)
{
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

void merge_two_list(Node *a,Node *b,int x)
{
    Node *temp1 = a;
    Node *temp2 = b;

    while(temp1->next!=NULL)
        temp1=temp1->next;
    while(x>1){
        temp2 = temp2->next;
        x--;
    }
    temp1->next = temp2;
}

Node *intersectPoint(Node *a , Node *b)
{
    unordered_set<Node*>st;
    while(a!=NULL){
        st.insert(a);
        a=a->next;
    }
    while(b!=NULL){
        if(st.find(b)!=st.end())
            return b;
        st.insert(b);
        b = b->next;
    }
    return NULL;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Node *a=NULL,*b=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a = insert_at_tail(x,a);
    }
    print(a);
    cout<<endl;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        b = insert_at_tail(x,b);
    }
    print(b);
    cout<<endl;
    int x,y;
    cin>>x;

    merge_two_list(a,b,x);
    print(a);
    cout<<endl;
    print(b);
    cout<<endl;
    cout<<intersectPoint(a,b)->val<<endl;
    return 0;
}
/**

3 5
1 2 3
4 5 6 7 8
3

*/
