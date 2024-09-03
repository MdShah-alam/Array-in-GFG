#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *insert_at_tail(Node *head , int val)
{
    if(head==NULL){
        head = new Node(val);
        return head;
    }

    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    Node *tmp = new Node(val);
    temp->next=tmp;
    return head;
}

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

bool isPalindrome(Node *head)
{
    stack<int>st;
    Node *temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    while(head!=NULL){
        if(head->data!=st.top())
            return false;
        head=head->next;
        st.pop();
    }
    return true;
}

int main()
{
    Node *head = NULL;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head,a);
    }

    print(head);
    cout<<endl<<isPalindrome(head)<<endl;
    return 0;
}
