#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *insert_at_tail(Node *&head , int val)
{
    if(head==NULL) return head=new Node(val);
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

void print(Node *head)
{
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void removeLoop(Node *head)
{
    Node *slow=head;
    Node *fast=head;

    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            break;
        }
    }
    if(slow==head){
        while(fast->next!=slow)
            fast=fast->next;
        fast->next=NULL;
    }
    else if(slow==fast){
        slow=head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
}

void loop(Node *head , int val)
{
    Node *temp=head;
    Node *temp2;

    while(temp->next!=NULL){
        if(temp->data==val)
            temp2=temp;
        temp=temp->next;
    }

    temp->next=temp2;
}

int main()
{
    int n;
    cin>>n;
    Node *head=NULL;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head = insert_at_tail(head,a);
    }
    print(head);
    cout<<"loop start point : ";
    int k;
    cin>>k;
    loop(head,k);
    removeLoop(head);
    return 0;
}
/**

5
1 2 3 4 5

*/
