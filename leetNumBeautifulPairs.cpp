/*
*
//******************************************************2748. Number of Beautiful Pairs.******************************************************

https://leetcode.com/problems/number-of-beautiful-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,5,1,4]
[11,21,12]
[4,6,5,4,3,2,1,6,5,4,7,8,7,6,5,9,8,7,6,5,4,2,7,8,9]
[4,6,5,4,3,2,1]
[4,6,5,4,3,2,1,6,5,4,7,8,7,6,5]
[4,6,5,4,3,2,1,6,5,4,7,8,7,6,5,9,8,7,6]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration and observation based. Here since the range of nums that we calculate the gcd for(i.e 1 to 9), we can list the pairs whose gcd would be 1 and use
// it directly avoiding calls to gcd function, which saves runtime. For every num during iteration we get the number of prev. nums which satisfy the pairs condition by
// by using formula (total #prev. nums-#prev. nums divisible by curr. digit as in these cases the gcd would be >1 ) and add it to res. We return final #pairs at the end of iter.







class Solution {
public:
    
    int getPairs(vector<int>&v, int digit, int prevCount) {					// Returns #prev. nums which has a gcd>1 with curr. digit.
        if(digit==5 || digit==7 ) return prevCount-v[digit];				// total #prev. nums-#prev. nums with first digit divisible by curr. digit or viceversa.
        if(digit==2 || digit==4 || digit==8) return prevCount-v[2]-v[4]-v[6]-v[8];
        if(digit==3 || digit==9) return prevCount-v[3]-v[6]-v[9];
        if(digit==6) return prevCount-v[6]-v[3]-v[2]-v[4]-v[8]-v[9];
        if(digit==1) return prevCount;
        return 0;
    }
    
    int countBeautifulPairs(vector<int>& v) {
        int res=0;
        vector<int>occur(10,0);												// Stores #prev. nums whose first digit are 1-9.
        for(int i=0;i<v.size();i++) {
            int digit=v[i]%10;
            res+=getPairs(occur, digit, i);									// Gets #pairs involving curr. digit.
            occur[to_string(v[i])[0]-'0']++;								// Adding curr. num's first digit occurance to the array.
        }
        return res;															// Returning the total #pairs.
    }
};

