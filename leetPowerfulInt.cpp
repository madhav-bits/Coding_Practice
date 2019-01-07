/*
*
//**************************************************************970. Powerful Integers.*******************************************************

Given two non-negative integers x and y, an integer is powerful if it is equal to x^i + y^j for some integers i >= 0 and j >= 0.

Return a list of all powerful integers that have value less than or equal to bound.

You may return the answer in any order.  In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation: 
2 = 2^0 + 3^0
3 = 2^1 + 3^0
4 = 2^0 + 3^1
5 = 2^1 + 3^1
7 = 2^2 + 3^1
9 = 2^3 + 3^0
10 = 2^0 + 3^2
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
 

Note:

1 <= x <= 100
1 <= y <= 100
0 <= bound <= 10^6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3
6
99




2
1
19




1
1
4





// Time Complexity: O((logl/logm)*(logl/logn)).
// Space Complexity: O(l).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O((logl/logm)*(logl/logn)).
// Space Complexity: O(l).														
// This algorithm is backtracking based. Here, we iterate over all possible powers values for both integers whose value<target value. And check
// whether their sum <=target value. If it's less then, push it into a set. At the end of process, push the set values into vector and return.
// We use set, as there are different combinations of powers whose sum lead to same total, so to avoid duplicate sums, we use set. We also track
// prev. power value and make sure it's not equal to curr. power value to avoid infi. loops in case of base value of 1.






class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>st;												// Saves the possible sum values.
        int i=0,j=0;														// Expo. values.
        int prev=0, prev2=0;												// Tracks prev. power value.
        while(pow(x,i)<bound){												// Iter. over first number.
            j=0;
            if(pow(x,i)==prev) break;										// If prev. power value is same as curr. then break to avoid infi. loop.
            prev=pow(x,i);													// Calc. curr. power value.
            prev2=0;														// Init. prev. power value for inner loop.
            while(pow(x,i)+pow(y,j)<=bound){								// Iter. till condition satisfies.
                if(pow(y,j)==prev2) break;									// If prev. power value is same as curr. then break to avoid infi. loop.
                st.insert(pow(x,i)+pow(y,j));								// Inserting sum value into set to avoid dup. sum values.
                prev2=pow(y,j);												// Updating prev. power value of ineer loop.
                j++;														// Inc. the exponent value of inner loop.
            }					
            i++;															// Inc. the exponent value of outer loop.
        }
        vector<int>res;														// Stores the final list of unique sum values.
        for(auto it=st.begin();it!=st.end();it++){							// Pushing set contents into vector.
            res.push_back(*it);
        }
        return res;															// Returning the final list of unique sum values.
    }
};
