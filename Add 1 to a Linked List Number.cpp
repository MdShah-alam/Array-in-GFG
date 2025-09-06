#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *insert_at_tail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if(!head) return newNode;
    Node *temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = newNode;
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

Node *reverseList(Node *head)
{
    if(!head || !head->next) return head;
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* addOne(Node* head)
{
    Node *head2 = reverseList(head);
    Node *curr = head2;
    int carry = 1;
    while(curr && carry){
        int sum = curr->data + carry;
        carry = sum/10;
        curr->data = sum%10;
        if(curr->next==NULL && carry){
            Node *newNode = new Node(carry);
            curr->next = newNode;
            head = reverseList(head2);
            return head;
        }
        curr = curr->next;
    }
    head = reverseList(head2);
    return head;
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
    cout<<endl;
    print(head);
    Node *hed = addOne(head);
    print(hed);

    return 0;
}
