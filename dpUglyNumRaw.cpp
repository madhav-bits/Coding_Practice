#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;


// Comes under DP category, but DP concepts not applied, there is another code, in which concepts are applied.
//Calculating the xth number in the ugly number series. Raw code, no optimization done.
// Highest Time Complexity.

int divby(int number, int a){
    if(number%a==0)
        divby(number/a,a);
    else
      return number;
}

int uglyNumber(int count){
    int i=0;
    int number=1;
    while( i<count){
        int temp=number;
        temp=divby(temp,2);
        temp=divby(temp,3);
        temp=divby(temp,5);
        if(temp==1){    
            i++;
        }
        number++;
    }
    return number-1;
    
}


int main(){
    int count=150;
    int result=uglyNumber(count);
    cout<<result<<" is the "<<count<<" th ugly number."<<endl;
    cout<<"Hi"<<endl;
    return 0;
}
