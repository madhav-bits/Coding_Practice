/*

//***************************************************INS14C - Digo plays with Numbers.************************************************
https://www.spoj.com/problems/INS14C/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Greedy based algorithm. Here, we calculate the #turns each person would get. Sharry, so as to minimize the resulting 
// string,  would try to remove the ones from the left, if there are no ones left he would remove left out zeros(removing any zero leads
// to same resulting string). Digo so as to maximize the resulting string, he removes the leftmost zeros as it would minimize the dec. 
// in value. If there are no zeros left, he would remove ones(removing any one leads to same resulting string). We keep count of how 
// many zeros, ones to be removed from the right, once we are past those many zeros/ones in final iteration, we append else chars to 
// final string.







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
    	int init,final;
    	cin>>init>>final;
    	string s;
    	cin>>s;
    	double moves=init-final;
    	// cout<<"moves: "<<moves<<endl;
    	int ones =ceil(moves/2);											// #moves to Sharry(remove Ones).
    	int zeros=moves-ones;												// #moves to Digo(remove Zeros).
    	// int lastOne, lastZero;
    	// cout<<"ones: "<<ones<<" and zeros: "<<zeros<<endl;
    	int totalOnes=0, totalZeros=0;
    	for(auto ch:s){
    		if(ch=='0') totalZeros++;
    		else totalOnes++;
    	}
    	// int rightZero=0, rightOne=0;
    	// if(totalOnes<ones) rightZero=ones-totalOnes;
    	// if(totalZeros<zeros) rightOne=zeros-totalZeros;
  //   	rightZero=totalZeros-rightZero;
  //   	rightOne=totalOnes-rightOne;
  //   	int on=0, ze=0;
  //   	string res="";
  //   	// cout<<"left ones: "<<ones<<" and rightones: "<<rightOne<<endl;
		// // cout<<"left zeros: "<<zeros<<" and rightzeros: "<<rightZero<<endl;
  //   	for(int i=0;i<s.length();i++){
  //   		if(s[i]=='0') ze++;
  //   		else on++;
  //   		if(s[i]=='0' && ze>zeros && ze<=rightZero) res+=s[i];
  //   		if(s[i]=='1' && on>ones && on<=rightOne) res+=s[i];
  //   	}

    	if(totalOnes<ones) zeros+=ones-totalOnes;							// If #turns are more than ones present, we remove zeros in remaining moves.
    	if(totalZeros<zeros) ones+=zeros-totalZeros;						// If #turns are more than zeros present, we remove ones in remaining moves.
    	int on=0, ze=0;
    	string res="";
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='0') ze++;
    		else on++;
    		if(s[i]=='0' && ze>zeros) res+=s[i];							// If moved past removed ones, append to final string.
    		if(s[i]=='1' && on>ones) res+=s[i];								// If moved past removed zeros.
    	}
    	cout<<res<<endl;
    }
    

    return 0;
}