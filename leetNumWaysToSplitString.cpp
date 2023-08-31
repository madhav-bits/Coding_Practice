/*
*
//******************************************************1573. Number of Ways to Split a String.******************************************************

https://leetcode.com/problems/number-of-ways-to-split-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"111"
"111111"
"1111"
"10101"
"1001"
"0000"
"000"
"00000"
"000000"
"000000000"
"010011001110001000101100000101010100101"
"1000011100010100001010001010000110101"
"00000111100001110010010101000010101100010101010101"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. For use to break string into 3 non-empty substrings with equal '1's, the total #1s have to be multiple of 3 else we 
// return 0. We use an array to keep track of #indices which have index numbered prefixSum of 1s. If we don't have any 1s in the array, we return the #ways 
// derived from the formula in the algo. Else for every index(i) where the prefixSum of 1s is totalOnes/3, we have all indices where prefixSum=2*totalOnes/3 
// which forms end of second substr strating i+1 and the rest indices to be third substr. As all indices with prefixSum of #1s=totalOnes/3 pair with second 
// substr till prefixSum=2*totalOnes/3 to break string into 3 substrs, we could say (#totalOnes/3)*(#2*totalOnes/3) gives the total combinations in which 
// we can break str.







class Solution {
public:
    
    int numWays(string s) {
        int res=0, mod=1000000007;
        int totalOnes=0, ones=0, len=s.length();
        int occur[s.length()+1];											// Tracks #indices where prefixSum of #1s=index.
        memset(occur, 0, sizeof(occur));
        for(char&ch:s) {
            if(ch=='1') totalOnes++;										// Counting #1s in the array.
            occur[totalOnes]++;												// Tracking #indices where prefixSum=index.
        }
        if(totalOnes==0) return ((1ll*(len-2)*(len-1))/2)%mod;				// If totalOnes=0, we return #ways to break string from the formula.
        if((totalOnes%3)!=0) return 0;										// If totalOnes isn't multiple of 3, we can' divide into 3 substrs with equal 1s.
		int split=totalOnes/3;												// Calc. #1s in each split.
        // cout<<"totalOnes: "<<totalOnes<<endl;
       return (1ll*occur[split]*occur[2*split])%mod;						// Returning total #ways in which we can split the string.	
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. This is similar to above problem except that we optmized space utilization as we are only using 2 prefixSums for which we 
// need #indices with a given prefixSum, we maintain two vars and track the #indices rather than using the array.





class Solution {
public:
    
    int numWays(string s) {
        int res=0, mod=1000000007;
        int totalOnes=0, ones=0, len=s.length();
        for(char&ch:s) {
            if(ch=='1') totalOnes++;
        }
        if(totalOnes==0) return ((1ll*(len-2)*(len-1))/2)%mod;
        if((totalOnes%3)!=0) return 0;
        // cout<<"totalOnes: "<<totalOnes<<endl;
        int first=0, second=0;
        for(char&ch:s) {
            if(ch=='1') ones++;
            if(ones==(totalOnes/3)) first++;								// Tracking #indices where prefixSum=totalOnes/3(End of first substring).
            else if(ones==(2*totalOnes)/3) second++;						// Tracking #indices where prefixSum=2*totalOnes/3(End of second substring).
        }
        return (1ll*first*second)%mod;										// Returning total #ways in which we can split the string.
    }
};

