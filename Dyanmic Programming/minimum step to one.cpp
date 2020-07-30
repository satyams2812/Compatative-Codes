#include <iostream>
#include <climits>
using namespace std;

int minSteps(int n, int *dp)
{
    if(n==1)
    {
        return 0;
    }
    // look up
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int op1, op2, op3;
    op1=op2=op3=INT_MAX;
    if(n%3==0)
    {
        op1=minSteps(n/3, dp);
    }
    if(n%2==0)
    {
        op2=minSteps(n/2, dp);
    }
    op3=minSteps(n-1, dp);
    int ans=min(min(op1, op2), op3)+1;
    return dp[n]=ans;
}

int minStepsBu(int n)
{
    int dp[100]={0};
    for(int i=2; i<=n; i++)
    {
        int op1, op2, op3;
        op1=op2=op3=INT_MAX;
        if(i%3==0)
        {
            op1=dp[i/3]+1;
        }
        if(i%2==0)
        {
            op2=dp[i/2]+1;
        }
        op3=dp[i-1]+1;
        dp[i]=min(min(op1, op2), op3);
    }
    return dp[n];
}

int main() {
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<minSteps(n, dp)<<endl;
    cout<<minStepsBu(n)<<endl;
    return 0;
}
