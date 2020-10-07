#include <bits/stdc++.h> 

bool ispal(char input[], int start,int end)
{
    if(start==end)
        return true;
    
    if(input[start]!=input[end])
        return false;
    
    if(start<end+1)
        return ispal(input,start+1,end-1);
    
    return true;
        
}

bool checkPalindrome(char input[]) {
    int n = strlen(input);
    if(n==0)
    {
        return true;
    }
    return ispal(input,0,n-1);

}


#include <iostream>using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
