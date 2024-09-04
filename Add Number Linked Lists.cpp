#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node *insert_at_tail(Node *&head , int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
        return head = newNode;

    Node *temp = head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    return head;
}

Node *reverse_(Node *head)
{
    Node *prev=NULL,*curr=head;

    if(curr==NULL || curr->next==NULL)
        return curr;

    while(curr!=NULL){
        Node *nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

Node* addTwoLists(Node* num1, Node* num2)
{
    if(num1==NULL)
        return num2;
    if(num2==NULL)
        return num1;

    Node *ptr1 = reverse_(num1);
    Node *ptr2 = reverse_(num2);

    int carry=0;
    Node *ans=NULL;

    while(ptr1!=NULL || ptr2!=NULL){
        int val1=0;
        int val2=0;
        if(ptr1!=NULL)
            val1=ptr1->data;

        if(ptr2!=NULL)
            val2=ptr2->data;

        int sum=val1+val2+carry;
        carry=sum/10;
        int d=sum%10;
        Node *tt=new Node(d);

        if(ans==NULL)
            ans=tt;
        else{
            tt->next=ans;
            ans=tt;
        }
        if(ptr1!=NULL)
            ptr1=ptr1->next;
        if(ptr2!=NULL)
            ptr2=ptr2->next;
    }
    if(carry>0){
        Node *tt=new Node(carry);
        if(ans==NULL)
            ans=tt;
        else{
            tt->next=ans;
            ans=tt;
        }
    }

    Node *temp=ans;
    while(temp!=NULL && temp->data==0){
        temp=temp->next;
    }
    if(temp==NULL)
        return new Node(0);
    return temp;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Node *head1 = NULL , *head2=NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        head1=insert_at_tail(head1,a);
    }
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        head2 = insert_at_tail(head2,a);
    }

    print(head1);

    print(head2);

    Node *head = addTwoLists(head1,head2);
    print(head);

    return 0;
}
/**

2 3
1 2
3 4 5

2 3
4 5
3 4 5

4 2
0 0 6 3
0 7

*/
