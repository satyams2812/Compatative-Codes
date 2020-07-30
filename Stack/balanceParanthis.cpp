using namespace std;

class Stack{ // class
	int top;
	public:
    char a[10];
	Stack(){
	    top=-1;
	}
	void push(char n){
	    if(top>=10){
	        cout << "stack overflow"<<endl;
	    }
	    else{
	        a[++top]=n;
	        cout <<"elemeent inserted "<<endl;
	    }
	}
	void pop(){
	    if(top<0){
	        cout <<"stack underflow"<<endl;
	        //return 0;
	    }
	    else{
	        a[top--];
	         //cout <<"element popped-"<<x<<endl;
	        //return x;
	    }
	}
	bool isEmpty(){
	    if(top<0){
	        return true;
	      
	    }
	    else{
	        return false;
	    } 
	}
	void printStack(){
	    for(int i=0;i<=top;i++){
	        cout <<a[i]<<endl;
	    }
	}
	bool cP(string s){
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='{' ||s[i]=='(' ||s[i]=='[' )
	        {
	            cout << s[i];
	            push(s[i]);
	        }
	        else{
	            if(isEmpty()){
	            return false;    
	            }
	            
	            else if(s[i]==')' && a[top]=='('){
	                pop();
	            }
	             else if(s[i]=='}' && a[top]=='{'){
	               pop(); 
	            }
	             else if(s[i]==']' && a[top]=='['){
	                pop();
	            }
	            else{
	                return false;
	            }
	        }
	    }
	    if(isEmpty()){
	        
	        return true;
	    }
	    else{
	        return false;
	    }
	}
};



int main() {
	Stack s;
	if(s.cP("{()}[](")){
	    cout <<"balanced";
	}
	else{
	    cout << "not balanced";
	}
	
	
	return 0;
}
