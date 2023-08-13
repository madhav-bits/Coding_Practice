/*
*
//********************************************1780. Check if Number is a Sum of Powers of Three.********************************************

https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


12
91
21
1
2
10000000
3345356
9684858
9999999
883858
100
101
280
18



// Time Complexity: O(lognbase3).											// Solution 2 has best Time and Space Complexity.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^m).													//m-(max. exp. of power of 3<given number)=lognbase3.
// Space Complexity: O(m).	
// This algorithm is Brute Force+DFS based. As the range of nums is small, we have only 15 powers of 3<maxNum, which gives us 2^15=32*10^3 combinations
// of powers of 3 to check, which falls within the Run Tim limits. So, we first calc. all powers of 3<given num, we use DFS to form all possible combi.
// to get the given num, if we are not able to get any combination, we return false else we return true.






class Solution {
public:
    
    bool findSumOfPowers(int rem, vector<int>&powers, int index) {
        if(rem==0) return true;
        // cout<<"rem: "<<rem<<" and index: "<<index<<endl;
        if(index<0) return false;
        while(index<powers.size() && powers[index]>rem) index--;			// Skipping powers>rem value.
        while(index>=0) {													// Using powers of 3 and DFS call to form rem. val.
            if(findSumOfPowers(rem-powers[index], powers, index-1)) return true;// If combination with sum=target found, we return true.
            index--;														// Moving to lesser power values.
        }
        return false;
    }
    
    bool checkPowersOfThree(int n) {
        vector<int>powers;
        for(int num=1;num<=n;num*=3) powers.push_back(num);					// Collecting powers of 3<given number.
        return findSumOfPowers(n, powers, powers.size()-1);					// If powers of 3 combination with sum=target found, we return true.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(lognbase3).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we are trying to write given num in terms of powers of 3, which can be thought of as writing num in base3 rep.
// But we don't want 2 in it's rep form. So, we decompose the num to get it's base 3 form and checking if we get 2 in that bit, if we dont' observe 2 
// anywhere we return true.

// Ex: 6651=3*3+3*3*3*3+3*3*3*3*3*3*3*3=3^1+3^4+3^8=(100010010)base3
// As seen here, sum of powers of 3 translates to base 3 rep with no '2' in the rep, which we checked in the algo.






class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==1) return true;												// Base case.
        while(n>1) {
            if(n%3==2) return false;										// If we get 2 in base rep, we return false.
            n/=3;
        }
        return true;														// We an represent given num as sum of powers of 3.
    }
};

