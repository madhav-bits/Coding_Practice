/*
*
//******************************************************2222. Number of Ways to Select Buildings.******************************************************

https://leetcode.com/problems/number-of-ways-to-select-buildings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"001101"
"11100"
"0101010101"
"01010010010"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Dynamic Programming based. We store the #substrings of i length ending with 0/1(j) in dp[i][j] array. We form recurrenc relatoin based on the conditions provided. A substring of length 'i' ending with 1, 
// uses the substrings of length 'i-1' and ending with '0', so we dp[i][j]+=dp[i-1][non j] for 3 lengths. We also inc. the count for substring of length 1 by 1 for every index. After the iter. we return #substrings ending with 0/1
// of length 3.







class Solution {
public:
    long long numberOfWays(string s) {
        long long int res=0;
        vector<vector<long long int>>dp(4, vector<long long int>(2,0));
        for(char&ch:s) {
            if(ch=='1') {																				// If curr. char is '1'. We update those substrs which end with '1'.
                dp[3][1]+=dp[2][0];																		// substr of length 'i' depends on substr of length 'i-1' which ends with '0'.
                dp[2][1]+=dp[1][0];
                dp[1][1]++;																				// Inc. the #occur. of substr of length 1 by 1.
            }else {
                dp[3][0]+=dp[2][1];
                dp[2][0]+=dp[1][1];
                dp[1][0]++;
            }
        }
        return dp[3][0]+dp[3][1];																		// Returning #substrs of length 3 ending with 0/1.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Since we need substrs of length 3, we can use prefixSum of #zeroes, ones in the array. For every index, we calc. #substrs of length 3 with curr. char as middle char. For ex: if curr. char 
// is '1', we multiple prev occur. of zeroes with remaining zeroes to the right to get the #substrs of length 3 with curr. char in the middle. We use same logic for every index and adding all these substrs count to the res and
// return it at the end of iter.


// This algorithm is Slightly counter-intutive and a really good approach.




class Solution {
public:
    long long numberOfWays(string s) {
        long long int res=0;
       
        int totalOnes=0, ones=0, zeroes=0, totalZeroes=0;
        for(char&ch:s) {																				// Calc. total #zeroes, ones.
            (ch=='1')?totalOnes++:totalZeroes++;
        }
        for(char&ch:s) {
            if(ch=='0') {
                zeroes++;
                res+=ones*(totalOnes-ones);																// Getting #substrs of len 3 with curr char as midddle zero(ones*0*remOnes)
            }
            else {
                ones++;
                res+=zeroes*(totalZeroes-zeroes);														// Getting #substrs of len 3 with curr char as midddle one(zeroes*1*remZeroes)
            }
            
        }
        return res;																						// Returing the total #substrs of length 3 satisfying the given requirement.
    }
};

