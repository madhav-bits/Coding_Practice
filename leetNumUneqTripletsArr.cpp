/*
*
//******************************************2475. Number of Unequal Triplets in Array.*****************************************

https://leetcode.com/problems/number-of-unequal-triplets-in-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,4,2,4,3]
[1,1,1,1,1]
[6,5,4,3,5,6,7,8,7,6,54,3,12,13,14,13,2,3,54,6,7,8,76,5,4,33,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Combinatorics based. Here, first we get total #possible triplets formed. We iter. over all nums and gather their occur., later we iter. 
// each num and remove those triplets which have curr. num occuring twice, thrice which makes those triplets not meet conditions.







class Solution {
public:
    int unequalTriplets(vector<int>& v) {
        int len=v.size();
        int res=(len*(len-1)*(len-2))/6;									// Total #triplets
        vector<int>occur(1001,0);
        for(int&num:v) occur[num]++;										// Tracking #occur. of each num in the array.
        for(int i=1;i<=1000;i++) {
            int rep=occur[i];
            int rem=v.size()-rep;
            if(rep>=2) res-=((rep*(rep-1))/2)*rem;							// Triplets where curr. num occur twice.
            if(rep>=3) res-=((rep*(rep-1)*(rep-2))/6);						// Triplets where curr. num occur thrice.
        }
        return res;															// Returning total #unequal triplets.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, we first iter. over array and collect #occur. of each of the nums. Later, we iter over each of the nums and form
// triplets where curr. num would be the middle num of the triplet and we calc. #possib. for first num and third num in the triplet, multiply the 3 possib. 
// and add it to res.We do this for all the nums and return triplets count at the end of iter.










class Solution {
public:
    int unequalTriplets(vector<int>& v) {
        int res=0, left=0, right=v.size();
        vector<int>occur(1001,0);
        for(int&num:v) occur[num]++;										// Tracking #occur. of each num in the array.
        for(int i=1;i<=1000;i++) {
            if(occur[i]==0) continue;
            right-=occur[i];												// #occur. of values>curr. num.
            res+=left*occur[i]*right;										// #Triplets where curr. num would be the middle num.
            left+=occur[i];													// Inc. the count of nums with value<curr. num.
        }
        return res;															// Returning total #unequal triplets.
    }
};

