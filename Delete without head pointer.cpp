#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};
void deleteNode(Node* del_node)
{
    Node *curr = del_node;
    Node *prev = del_node;
    while(curr->next!=NULL){
        curr->data = curr->next->data;
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete(curr);
}

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
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
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
        head = insert_at_tail(head,x);
    }

    print(head);
    deleteNode(head->next->next);
    print(head);

    return 0;
}
