#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    int n;
    cin>>n;
    int d;
    cin>>d;
    n--;
    priority_queue<int, vector<int>, greater<int>> right; // minHeap
    priority_queue<int> left; // maxHeap
    int med;
    left.push(d);
    med=left.top();
    cout<<med<<endl;
    while(n--)
    {
        cin>>d;
        if(left.size() > right.size())
        {
            if(d < med)
            {
                right.push(left.top());
                left.pop();
                left.push(d);
            }
            else
            {
                right.push(d);
            }
            med=(left.top()+right.top())/2;
        }
        
        else if(left.size()==right.size())
        {
            if(d < med)
            {
                left.push(d);
                med=left.top();
            }
            else
            {
                right.push(d);
                med=right.top();
            }
        }
        
        else
        {
            if(d > med)
            {
                left.push(right.top());
                right.pop();
                right.push(d);
            }
            else
            {
                left.push(d);
            }
            med=(left.top()+right.top())/2;
        }
        cout<<med<<endl;
    }
    return 0;
}