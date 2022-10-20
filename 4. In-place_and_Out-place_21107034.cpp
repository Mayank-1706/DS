// MAYANK BHATANAGR
// 21107034
// MECHANICAL

/*Q1. What is the difference between in-place and out-place sorting algorithms?
ans-    An in-place algorithm is an algorithm that does not need an extra space and produces 
an output in the same memory that contains the data by transforming the input ‘in-place’. However,
a small constant extra space used for variables is allowed.
Simply we can say that if the extra memory taken by a sorting algorithm is between 1 to log(n) 
then it is called in place sorting algorithm and if it exceeds log(n) then it is called ot place 
sorting algorithm*/


// Implement Insertion sort in both (in-place and out-place) manner.

#include <iostream>
using namespace std;


// In-Place Insertion Sort

void insertion_sort_in(int arr[], int n)
{
    int i,key,j;
    for (i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}


// Out Place insertion Sort

void insertion_sort_OP(int arr[],int a,int b){
    if(a==b){
        return;
    }
    int j=a+1;
    int temp=arr[j];
    while(a>=0){
        if(arr[a]>temp){
            arr[a+1]=arr[a];
            a--;
        }
        if(a==-1){
            arr[0]=temp;break;
        }
        if(arr[a]<=temp){
            arr[a+1]=temp;break;
        }
    }
    insertion_sort_OP(arr,a+1,b);
}


// Code to Print the array

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
 

int main()
{
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];
    int new_arr[n];
    cout<<"Enter the array :";
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        arr[i]=new_arr[i];
    }
    cout<<"Sorting Using IN place sorting technique";
    insertion_sort_in(arr,n);
    print(arr,n);
    cout<<"Sorting Using OUT place sorting technique";
    insertion_sort_OP(new_arr,0,n-1);
    print(arr,n);
    
}



/*Q3. Suggest some practical examples of using in-place and out-place techniques? 
ans-    Out Place Techniques use more memory but makes the algorithm faster and In Place Technique uses l
ess memory but is generally slower
So Insertion Sort which is a form of in-place technique is used if the data is nearly sorted or when the list is small.
And Merge Sort which is a form of out-place technique can be used for large gata and if we have 
abundance of space as it has a Space complexity of O(N) in worst case.*/
