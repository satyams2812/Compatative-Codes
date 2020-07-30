#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    int fib1=fib(n-1);
    int fib2=fib(n-2);
    return fib1+fib2;
}

int fibTD(int n, int *dp)
{
    if(n==0 || n==1)
    {
        return n;
    }
    // look up
    if(dp[n]!=0)
    {
        return dp[n];
    }
    // recursive case
    int ans;
    ans=fibTD(n-1, dp)+fibTD(n-2, dp);
    return dp[n]=ans;
}

int fibBottomUP(int n)
{
    int dp[100]={0};
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// bottom up space optimisation
int fibSpaceOptimise(int n)
{
    int a=0;
    int b=1;
    int c;
    for(int i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

    int dp[100]={0};
    cout<<fibTD(n, dp)<<endl;

    cout<<fibBottomUP(n)<<endl;

    cout<<fibSpaceOptimise(n)<<endl;
    return 0;
}
