#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

void heapify(int arr[],int n,int i)
{
    int largest = i; //intiatize the root
    int left = 2*i+1; //left  
    int right = 2*i+2;// right
    //If left child is larger than root
    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    //if right child is larger than root
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;      
    }

    // If largest is Not Root
    if(largest!= i )
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);

    }

}

void heapSort(int arr[],int n)
{
     //build heap(rearrange arrage)
     for(int i = n/2-1; i>=0; i--)
     {
         heapify(arr,n,i);
     }
     for(int i=n-1;i>0;i--)
     {
         swap(arr[0],arr[i]);
         heapify(arr,i,0);
     }
}   


void printArray(int arr[], int n)
{
     for(int i = 0; i<n; ++i)
     {
         cout<<arr[i]<< " ";
         cout<<"\n";
     }
}


int main()
{
    int arr[] = {12,11,13,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    cout<<"Sorted Array"<<"\n";
    printArray(arr,n);
}