
/*
//***************************************************************CuttingBitString.**********************************************************************

We are in a distant future. After the downfall of mankind, the Earth is now ruled by fairies. The "Turing game Online" website is hot among fairies right now. On this website, everyone can play the programming puzzle "Turing game".



Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on. In the Turing game, the player is given a string of bits (zeros and ones). The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros. If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros. Of course, it may be the case that even this is impossible. In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed. You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.



You are given a String S that consists of characters '0' and '1' only. S represents the string given to a player of the Turing game. Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5. If there is no such K, return -1 instead.

 
Definition
    	
Class:	CuttingBitString
Method:	getmin
Parameters:	String
Returns:	int
Method signature:	int getmin(String S)
(be sure your method is public)
    
 
Constraints
-	S will contain between 1 and 50 characters, inclusive.
-	Each character in S will be either '0' or '1'.
 
Examples
0)	
    	
"101101101"
Returns: 3
We can split the given string into three "101"s.

Note that "101" is 5 in binary.

1)	
    	
"1111101"
Returns: 1
"1111101" is 5^3.

2)	
    	
"00000"
Returns: -1
0 is not a power of 5.

3)	
    	
"110011011"
Returns: 3
Split it into "11001", "101" and "1".

4)	
    	
"1000101011"
Returns: -1
5)	
    	
"111011100110101100101110111"
Returns: 5


// Time Complexity: O(n^2)																// Also depends on #powers of 5<pow(2,51).
// Space Complexity: O(n)																// Also depends on #powers of 5<pow(2,51).
*/


//***************************************************************Solution 1.**********************************************************************

// Time Complexity: O(n^2)																// Also depends on #powers of 5<pow(2,51).
// Space Complexity: O(n)																// Also depends on #powers of 5<pow(2,51).


//*************************************************************************************************************************************************
//*************************************************************************************************************************************************
//*************************************************************************************************************************************************
// I don't know what's wrong with these solutions, but Topcoder just don't accept them, I had seen few similar logics with lot of macros got 
// accepted, may be i need macros. This question had costed me 5 hours. Shitty Question/ Shitty Compiler might be the reason.
//*************************************************************************************************************************************************
//*************************************************************************************************************************************************







#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<unordered_set>
#include<cmath>

using namespace std;

class CuttingBitString{
	
public:


	int getmin(string s){
		int len=s.length();
		vector<int>dp(len,len+1);
		unordered_set<int>st;
		long int val=1;
		double limit=pow(2,51);
		while(val<=limit){
			st.insert(val);
			val*=5;
		}

		for(int i=len-1;i>=0;i--){
			int val=0;
			if(s[i]=='0') continue;
			if(j+1<len && dp[j+1]==len+1) continue;
			for(int j=i;j<len;j++){
				val*=2;
				if(s[j]=='1') val+=1;
				if(st.count(val)==1){
					if(j==len-1) dp[i]=1;
					else dp[i]=min(dp[i], dp[j+1]+1);	
				} 
			}
		}
		return (dp[0]==(len+1)?-1:dp[0]);
	}	


	// int main(){
	// 	string s="111011100110101100101110111";
	// 	int res=getmin(s);
	// 	cout<<"res: "<<res<<endl;
	// }

};




//***************************************************************Solution 2.**********************************************************************

// Time Complexity: O(n^2)																// Also depends on #powers of 5<pow(2,51).
// Space Complexity: O(n)																// Also depends on #powers of 5<pow(2,51).
#include<vector>





#include <cstdlib> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 

using namespace std;

class CuttingBitString{
	
    
const long long int inf = 4503599627370496LL;     
public:

	void minVal(int &x, int y){
    	if(y<x) x=y;
        return ;
    }

	int getmin(string s){
		int len=s.length();
		vector<int>dp(len+1,len+1);
		set<int>st;
		long long int val=1;
		//double limit=pow(2,51);
		while(val<(1LL<<52)){
			st.insert(val);
			val*=5;
		}
		dp[0]=0;
		for(int i=0;i<len;i++){			// Here, the optimization is that when we are at index 'i', we would be updating values of all it's following indices min. length values, so that w
			// by the time we reach index 'j', we already have it's smallest value. So, we can skip it if it's doesn't satisfy conditions and save lot of iterations.
			if(dp[i]==(len+1) || s[i]=='0') continue;
			long long int val=0;
			for(int j=i;j<len;j++){
				val<<=1;
				val+=(s[j]-'0');
				if(st.find(val)!=st.end()){
					// dp[j+1]=min(dp[j+1], dp[i]+1);
					minVal(dp[j+1], dp[i]+1);
				}
			}
		}
		return (dp[len]==(len+1))?-1:dp[len];
	}	
};