#include<bits/stdc++.h>
void merge(int input[],int s,int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k =s;
    
    int temp[1000];
    while(i<=mid && j<=e)
    {
        if(input[i]<input[j])
            temp[k++] = input[i++];
        else
            temp[k++] = input[j++];
    }
    
    while(i<=mid)
       temp[k++] = input[i++];
    
    while(j<=e)
    temp[k++] = input[j++];
    
    for(int i=s;i<=e;i++)
        input[i] = temp[i];
    
}

void mergeSort(int input[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;
    mergeSort(input,s,mid);
    mergeSort(input,mid+1,e);
    
    merge(input,s,e);
}


void mergeSort(int input[], int size){
return mergeSort(input,0,size-1);
}

#include <iostream>
using namespace std;

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
