#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int a){
        data=a;
        next=NULL;
    }
};

void insert_end(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){
        head=new_node;new_node->next=head;
        return;
        }
    while(temp->next!=head){
        temp=temp->next;
        }   
    temp->next=new_node;
    new_node->next=head;
}

void print_list(Node *head){
    if (head==NULL){
        return;
    }
    cout<<(head->data)<<" ";
    for (Node *p=head->next;p!=head;p=p->next){
        cout<<(p->data)<<" ";
    }
}

int main(){
    Node *head=NULL;
    insert_end(head,15);
    insert_end(head,10);
    insert_end(head,1);
    insert_end(head,5);

    print_list(head);
}