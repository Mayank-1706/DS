#include<iostream>
using namespace std;

// definning the bst
struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key=x;
        left=right=NULL;
    }
};

Node *getSucc(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

int deleteElement(int arr[], int n, int x){
int i;
for (i=0; i<n; i++)
    if (arr[i] == x)
        break;
 
if (i < n){
    n = n - 1;
    for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
}
 
return n;
}

// function to delte the node
Node *delNODE(Node *root, int x){
    if (root==NULL){
        return root;
    }
    if(root->key>x){
        root-> left = delNODE(root->left,x);
    }
    else if(root->key<x){
        root->right= delNODE(root->right,x);
    }
    else {
        if (root->left==NULL){
            Node *temp= root->right;
            delete root;
            return temp;
        }
        else if (root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSucc(root);
            root->key=succ->key;
            root->right=delNODE(root->right, succ->key);
        }
        return root; 
    }
}

// defining the nodes
Node* newNode(int key){   
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);}

Node* insertLevelOrder(int arr[],int i, int n){
      Node *root = nullptr;

    if (i < n)
    {
        root = newNode(arr[i]);

        root->left = insertLevelOrder(arr,
                   2 * i + 1, n);
  
        root->right = insertLevelOrder(arr,
                  2 * i + 2, n);
    }
    return root;
}

// to print the bst
void inOrder(Node* root){
    if (root != NULL){
        inOrder(root->left);
        cout << root->key <<" ";
        inOrder(root->right);
    }
}
  

int main(){
    // defining the array
    int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin>>x;// element to be delted
    Node* root = insertLevelOrder(arr, 0, n);
    inOrder(root);
    cout<<" "<<endl;
    delNODE(root,x);//when deleted from bst
    inOrder(root);
    cout<<endl;
    deleteElement(arr,n,x);//deleted from array
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }// printing the array
}


// now considering the space complexities of both the functions
  