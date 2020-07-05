#include<bits/stdc++.h>
using namespace std;

int factorial (int n)
{
     cout<<"Starting to calculate " << n << " factorial " << endl; //statement 1
     int result;
     if(n==0)
     {
         result =1;
     }
     else
     {
         result = n*factorial(n-1);

     }
     cout<<"Finished Calculating "<<n << " factorial "<<endl; //statement 2
       return result;
     
}

int main()
{
    cout<<"Factorial of 4"<< factorial(4)<<endl;
    return 0;
}


/* int factorial (int n)
{
     if(n==0)
     {
     return 1;
     }
    return n*factorial(n-1);
}

int main()
{
   int n;
   cin>>n;
  cout<< factorial(n);
  return 0;
} */