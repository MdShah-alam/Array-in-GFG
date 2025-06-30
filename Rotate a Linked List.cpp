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
void print(Node *head)
{
    Node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* rotate(Node* head, int k)
{
    int n=1;
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        n++;
    }
    k = k % n;
    if(k==0){
       return head;
    }
    temp->next = head;
    Node *tail = head;
    for(int i = 1;i<k;i++){
        tail = tail->next;
    }
    Node *newhead = tail->next;
    tail->next = NULL;
    return newhead;
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
    int k;
    cin>>k;
    Node *abc = rotate(head,k);
    print(abc);
    return 0;
}

/**



*/
