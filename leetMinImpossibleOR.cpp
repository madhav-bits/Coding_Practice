/*
*
//******************************************************2568. Minimum Impossible OR.******************************************************

https://leetcode.com/problems/minimum-impossible-or/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1]
[5,3,2]
[1,2,4,5,8,12]



// Time Complexity: O(n+k).																				//n-length of the array, k=32 as we are dealing with 32 bit ints.
// Space Complexity: O(k).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+k).																				//n-length of the array, k=32 as we are dealing with 32 bit ints.
// Space Complexity: O(k).	
// This algorithm is observation+Math based. Here, as we can form nums by performing OR on the members of the array, one observation plays a major role here, any number can be formed by OR of diff.
// powers of 2 less than it.Ex: If we have 1,2,4,8 in our array we form all the values from 9 to 15, i.e from [2^3+1, 2^4-1], and if we have 16 also, we can form [2^4+1, 2^5-1]. So, we store all 
// powers of 2 from the array in a set, we iter. over powers of 2 in another iter and return the first power of 2 not present in the set.



// This discussion forum link has detailed explanation of this approach:
// https://leetcode.com/problems/minimum-impossible-or/discuss/3201897/JavaC%2B%2BPython-Pow-of-2






class Solution {
public:
    int minImpossibleOR(vector<int>& v) {
        unordered_set<int>st;
        for(int&num:v) {																				// Storing all powers of 2 from the array in the set.
            if((num&(num-1))==0) st.insert(num);
        }
        int num=1;
        while(num<=INT_MAX) {																			// Iter. over powers of 2.
            if(st.count(num)==0) return num;															// Returning the first power of 2 not present in the array.
            num<<=1;
        }
        return -1;
    }
};

