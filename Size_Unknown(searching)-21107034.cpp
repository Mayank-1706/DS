// Name: MAYANK BHATNAGAR
// SID:21107034
// Branch:MECHANICAL
#include<iostream>
using namespace std;

int binary_search_code(int arr[],int l,int r,int x)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}


int binary_search(int arr[], int x){
    int low = 0;
    int high = 1;

    while (arr[high] < x)
    {
        low = high;
        high = 2 * high;
    }

    return binary_search_code(arr,low,high,x);
}

int main(){

    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the number you want to search : ";
    cin >> x;

    cout<<"The index of the desired number is"<<endl;
    cout <<binary_search(arr, x) << endl;
    
}
