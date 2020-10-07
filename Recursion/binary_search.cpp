int binarySearch(int input[],int start,int end,int element)
{
    
    if (end >= start){
      int middle = (start+end)/2;
      if (input[middle] == element)
         return middle;
      if (input[middle] > element)
         return binarySearch(input, start, middle-1, element);
      return binarySearch(input, middle+1, end, element);
   }
   return -1;
}

int binarySearch(int input[], int size, int element) {
  
return binarySearch(input,0,size-1,element);
}

#include <iostream>
using namespace std;

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
