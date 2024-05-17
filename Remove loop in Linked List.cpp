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

Node *insert_at_tail(Node *&head, int val)
{
    if(head==NULL)
    {
        head=new Node(val);
        return head;
    }

    Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    Node *newNode = new Node(val);
    temp->next=newNode;
    return head;
}

void print(Node *head)
{
    Node *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node *createcycle(Node *&head, int val)
{
    Node *temp=head;
    Node *valnode=head;
    while(temp->next!=NULL)
    {
        if(temp->data==val)
            valnode=temp;
        temp=temp->next;
    }

    temp->next=valnode;
    return head;
}

bool checkcycle(Node *head)
{
    Node *fast=head;
    Node *slow=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

void removeLoop(Node* head)
{
    Node * fast=head;
    Node * slow=head;

    do
    {
        cout<<fast->data<<" "<<slow->data<<endl;
        fast=fast->next->next;
        slow=slow->next;

    }while(fast!=slow);
    cout<<fast->data<<" "<<slow->data<<endl;
    cout<<endl<<"After"<<endl;
    fast=head;

    while(fast->next!=slow->next)
    {
        cout<<fast->data<<" "<<slow->data<<endl;
        fast=fast->next;
        slow=slow->next;
    }
    cout<<fast->data<<" "<<slow->data<<endl;
    slow->next=NULL;

}


int main()
{
    Node *head=NULL;
    int n;
    cout<<"How many node : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        head=insert_at_tail(head,a);
    }
    cout<<endl;
    print(head);

    int val;
    cout<<endl<<"Enter a number to create cycle : ";
    cin>>val;

    head = createcycle(head,val);

    cout<<checkcycle(head);
    cout<<endl;
    removeLoop(head);
    cout<<checkcycle(head);
    cout<<endl;

    return 0;
}
