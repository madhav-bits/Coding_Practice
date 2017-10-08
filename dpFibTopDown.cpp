#include <iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#define MAX 100

using namespace std;

//Dynamic Programming, fibanocci series Top Down approach.
//First Fib number is: 1
//Second Fib number is: 1
//Third Fib number is: 2
//Fourth Fib number is: 3



int lookup[MAX];

int fib(int n){
    if(lookup[n]==0){
        if(n<=1)
            lookup[n]= 1;
        lookup[n]=fib(n-1)+ fib(n-2);// Calculating the fib values and saving them into lookup array, such that we don't
    }//table those vaues once again.
    return lookup[n];
}

int main(){
    cout << "Hello World" << endl;
    for(int i=0;i<MAX;i++){
        lookup[i]=0;
    }
    int n=10;
    cout<<"Fibanocci series 10th element is: "<<fib(n)<<endl;

    return 0;
}

