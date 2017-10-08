#include <iostream>
#include<cstdlib>


using namespace std;

//Dynamic Programming, fibanocci series bottom to top approach.
//First Fib number is: 1
//Second Fib number is: 1
//Third Fib number is: 2
//Fourth Fib number is: 3


int fib(int n){
	int arr[n+1];
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<=n;i++)
		arr[i]=arr[i-1]+arr[i-2];
	return arr[n];
}

int main(){
    cout << "Hello World" << endl;
    int n=10;
    cout<<"Fibanocci series 10th element is: "<<fib(n)<<endl;

    return 0;
}

