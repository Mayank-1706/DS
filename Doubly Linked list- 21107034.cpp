#include<iostream>
using namespace std;

// definning a doubly linkied list
struct Node{
    string name;
    int age;
    Node *prev;
    Node *next;
    Node(string a, int b){
        name=a;
        age =b;
        prev=NULL;
        next=NULL;
    }
};

// function to insert a node at the front of a doubly linked list
void *insert_begin(Node *&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

// function to insert a node at the end of a doubly linked list
void *insert_end (Node *&head,string name,int age){
    //Creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node*res=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=res;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){
            temp=temp->next;
            }
        temp->next=res;
        res->prev=temp;
    }
}

// to delete the head of the doubly linked list
Node *delete_head(Node *&head){
    // there will be three casses
    
    if (head==NULL){
        // this case when there is no element in the doubly linked list
        return NULL;
    }
    if (head->next==NULL){
        // this case is when there is only one element in the doubly linked list
        delete head;
        return NULL;
    }
    else{
        // this is the main case when there are equal to or more than 2 elements in the doubly linked list
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

// to delete the last element of the doubly linked list
Node *delete_last(Node *&head){
    // sismilar to delete at head there will be conditions
    if (head==NULL){
        return NULL;
    }
    if (head->next==NULL){
        delete head;
        return NULL;
    }
    Node *curr=head;
    while (curr->next!=NULL){
        curr=curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
    return head;
}

// traversing through a doubly linked list
void print_list(Node*node){
    struct Node* last;
    // printing condition
    while (node != NULL) {
        cout << node->name<< " " << node->age << " <=> ";
        last = node;
        node = node->next;
    }
    // end condition 
    if (node == NULL){
        cout << "NULL\n";
    }
}

// for the proper way to lionk family members based on their relationships
void bubbleSort(struct Node *head)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;
  
    // condition for empty list
    if (head == NULL)
        return;
  
    do{
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->age < ptr1->next->age)
            {
                swap(ptr1->name, ptr1->next->name);
                swap(ptr1->age, ptr1->next->age);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

// adding all the nodes
int main(){
    Node *head=NULL;
    insert_end(head,"Kavita",44);
    insert_end(head,"Rani",73);
    insert_end(head,"Mayank",20);
    insert_end(head,"Atul",50);
    print_list(head);
    bubbleSort(head);
    print_list(head);
    
} 