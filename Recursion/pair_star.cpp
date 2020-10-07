/*

Pair star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/
int length(char input[]){
	int len = 0;
	for(int i =0;input[i]!='\0';i++){
		len++;
	}
	return len;
}

void pairStarhelp(char input[],int start){
	
	if(input[start]=='\0'){
		return;
	}   
	//Recursive Call 
	pairStarhelp(input,start+1);
    
    
	if(input[start] == input[start+1]){
		int l = length(input);
	
		input[l+1] = '\0';
		int i;
		//To shift the letters by 1
		for(i = l-1;i>=start +1;i--){
			input[i+1] = input [i];
		}
		//Entering * in between
		input[start+1] = '*';
	}
}


void pairStar(char input[]) {
 
    pairStarhelp(input,0);

}
#include <iostream>
using namespace std;

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
