#include <iostream>
#include<queue>

using namespace std;

int minCostRopes(int *arr,int n)
{
   long int cost=0;
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);
    while(pq.size()>1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();
        cost += A+B;
        pq.push(A+B);
    }
    return cost;
}



int main() {

int t;
cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     cout<<minCostRopes(arr,n);
     cout<<endl;
 }
	return 0;
}