#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n = 7, hours = 50;
     int T[7] = {10, 100, 4, 16, 8, 17, 28};
     int sum = 0, i = 0;
  
    sort(T, T+n);
  
for (i = 0; i < n; i++) {
    if (sum + T[i] > hours)
    {
        break;
    }  
    sum = sum + T[i];
}

cout << "Maximum number of tasks that can be done in " << hours << " hours is: " << i << endl;

} 