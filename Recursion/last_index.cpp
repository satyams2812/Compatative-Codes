int lastIndex(int input[], int size, int x) {
  if (size < 0)
        return -1;
    if (input[size] == x) {
        return size;
    }
    return lastIndex(input, size - 1, x);

}
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


