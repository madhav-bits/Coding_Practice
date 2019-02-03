/*

//*****************************************************************ABA12C - Buying Apples!*************************************************************
https://www.spoj.com/problems/ABA12C/



Time Complexity:O(m*n).
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).
// Space Complexity:O(n).
// This is iteration based algorithm.





#include <iostream>

using namespace std;


int getRect(int num){
// 	if(num%2==1) return 1;
	int res=0;
	for(int i=1;i*i<=num;i++){
		if(num%i==0) res++;
	}
// 	cout<<"num: "<<num<<" res: "<<res<<endl;
	return res;
}

int main() {
	// your code goes here
	int num;
	cin>>num;
	int res=0;
	for(int i=1;i<=num;i++){
		res+=getRect(i);
	}
	cout<<res<<endl;
	return 0;
}