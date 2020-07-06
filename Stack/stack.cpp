#include<iostream>
#define MAX_SIZE 5

using namespace std;

int A[MAX_SIZE]; 
int top = -1;  

void Push(int x) 
{
  if(top == MAX_SIZE -1) { 
		cout<<"Error: stack overflow\n";
		return;
	}
	A[++top] = x;
}


void Pop() 
{
	if(top == -1) { 
		cout<<"Error: No element to pop\n";
		return;
	}
	top--;
}

 
int Top() 
{
	return A[top];
}


int IsEmpty()
{
    if(top == -1) return 1;
    return 0;
}


void Print() {
	int i;
	cout<<"Stack: ";
	for(i = 0;i<=top;i++)
		cout<<A[i]<< " ";
	cout<<"\n";
}

int main() {	
  
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
    Push(24);Print();
    Push(72);Print();
    cout<<Top();
}