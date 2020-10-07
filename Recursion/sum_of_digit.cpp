int sumOfDigits(int n) {
    if(n<=0)
    {
        return 0;
    }

    int ans =  sumOfDigits(n/10);
      ans += n%10;
    return ans;
}


#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
