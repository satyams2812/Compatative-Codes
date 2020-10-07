/*
Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>
#include <string>
using namespace std;


void printkeypad(int num,string output,string dialer[]){
    if(num ==0)
        cout<<output<<endl;
    
    int lastDigit = num%10;
    int smallNum = num/10;
    string op = dialer[lastDigit];
    
    for(int i=0; i<op.size();i++){
        printkeypad(smallNum,op[i]+output,dialer);
    }
    
}




void printKeypad(int num)
 {
   string dialer[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output;
    printkeypad(num,output,dialer);
    
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
