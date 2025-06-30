#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *insert_at_tail(Node *&head , int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
        return newNode;
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=newNode;
    return head;
}
void segregate(Node *&head)
{
    Node *temp = head;
    int ar[3]={0,0,0};
    while(temp!=NULL){
        ar[temp->data]++;
        temp = temp->next;
    }
    for(int i=0;i<3;i++)
        cout<<ar[i]<<"  ";
    cout<<endl;
    temp=head;
    for(int i=0;i<3;i++){
        while(ar[i]){
            temp->data = i;
            ar[i]--;
            temp=temp->next;
        }
    }
}

void print(Node *head)
{
    if(head==NULL) return ;
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    Node *head = NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        head = insert_at_tail(head, x);
    }
    print(head);
    segregate(head);
    print(head);
}

/**

7
2 1 2 0 1 2 0

*/
