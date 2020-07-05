#include<bits/stdc++.h>

using namespace std;


int binary_search(int key, int array[],int min,int max)
{
    min = 0;
    max = max;
    int mid=0;
    while(min<max)
    {
        mid = (min+max)/2;
        if(array[mid]<key)
        {
            min = mid+1;
        }
        else{
            max  = mid;
        }
    }
    return key;
}


int main()
{
   int arr[] = {1,2,3,4,5,6,7,8};
   cout<<binary_search(4,arr,0,8);
}