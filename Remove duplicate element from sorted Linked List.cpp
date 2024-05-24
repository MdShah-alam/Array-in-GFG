#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node *insert_at_tail(Node *&head , int a)
{
    if(head==NULL) return head = new Node(a);

    Node *temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(a);
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *removeDuplicates(Node *head)
{
    if(head==NULL && head->next==NULL) return head;

    Node *curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data)
            curr->next=curr->next->next;
        else
            curr=curr->next;
    }
    return head;
}

int main()
{
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head,a);
    }
    print(head);
    cout<<endl;
    Node *temp=removeDuplicates(head);
    print(temp);
    cout<<endl;
    return 0;
}
