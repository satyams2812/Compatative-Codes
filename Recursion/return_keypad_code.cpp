/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
#include <cstring>
using namespace std;


 string  dial[10] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 
  
int   print(string output[],int num) 
{ 
    
    if(num==0||num==1)
    {
        output[0]="";
        return 1;
    }
    string newoutput[10000];
    int last=num%10;
    int k=0;
  int x=print(newoutput,num/10);
   
    for (int i=0; i<(dial[last].length()); i++) 
    { 
       for(int j=0;j<x;j++)
       {
           output[k]=newoutput[j]+dial[last][i];
           k++;
       }
    } 
    return k;
} 
int keypad(int num, string output[])
{
  return  print(output,num);
}
#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
