
void quickSort(int input[], int size) {
 if (size <= 1) 
        return; 
  
    
    quickSort( input, size-1 ); 
  
 
    int last = input[size-1]; 
    int j = size-2; 
  
   
    while (j >= 0 && input[j] > last) 
    { 
        input[j+1] = input[j]; 
        j--; 
    } 
    input[j+1] = last; 
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
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


