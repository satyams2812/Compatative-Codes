#include<iostream>
using namespace  std;

string dial[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int print(int num,string output[])
{
     if(num==0||num==1)
     {
         output[0]=" ";
         return 1;
     }
     string newoutput[10000];
     int lastnum = num%10;
     int k=0;
     int x = print(num/10,newoutput);
     for(int i=0;i<dial[lastnum].length();i++)
     {
         for(int j=0;j<x;j++)
         {
             output[k] = newoutput[j]+dial[lastnum][i];
                  k++;
         }

     }
     return k;
}


int keypad(int num,string output[])
{
    return print(num,output);
}


int main()
{
     int num;
     cin>>num;
     string output[10000];
      int count = keypad(num,output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
}
