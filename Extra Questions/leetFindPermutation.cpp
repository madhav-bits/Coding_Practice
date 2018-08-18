/*
*
//************************************************************484. Find Permutation.*****************************************************

By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' 
represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains 
uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be 
constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special 
string that can't represent the "DI" secret signature.

On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature 
in the input.

Example 1:
Input: "I"
Output: [1,2]
Explanation: [1,2] is the only legal initial spectial string can construct secret signature "I", where the number 1 and 2 construct an increasing 
relationship.
Example 2:
Input: "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can construct the secret signature "DI", 
but since we want to find the one with the smallest lexicographical permutation, you need to output [2,1,3]
Note:

The input string will only contain the character 'D' and 'I'.
The length of input string is a positive integer and will not exceed 10,000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"DIIDIIIDDIIIDD"



"DDIIDI"


"DIIDIIIDDDDDIIIIIDDIIIDDD"


"DDDDDD"


"D"


"I"


"IIIIII"


""




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Greedy based. We push the least valued possible number into the final result vector for every Sign encountered. We start
// iterating from index -1, we keep track of least possible number at any instant. We manipulate possible values when we encounter "I", which 
// has "D" following it. As, we need least lexical result, we push curr. possible num+#conse. "D"s following curr. "I", when we encounter "I".
// When we encounter "D", push the prev. value-1 into result vector. If the prev. value(last elem. of result vector), then push 1 into vector.








class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int>res;														// Stores the result seq. of ints.
        int curr=1;															// Tracks Least possible value at any instant.
        int len=s.length();													// Length of given vector.
        for(int i=-1;i<len;i++){
            // cout<<"Curr. index: "<<i<<endl;
            if(i>=0 && s[i]=='D'){											// If we encounter "D", push prev. value(if exist)-1 into result vector.
                if(res.size()==0)											// If prev. value doesn't exist, push curr. least possible.
                    res.push_back(curr);
                else res.push_back(res.back()-1);							// Pushing prev. value -1 into result vector.				
                continue;
            } 
            int count=0;													// #conse. "D"s following curr. "I".
            int j=i;														// Temp. storing "I" index.
            while(j+1<s.length() && s[j+1]=='D'){							// Extracting count of #continuous "D"s.
                count++;
                j++;
            }
            res.push_back(curr+count);										// Pushing curr. least+count into result vector.
            curr+=count+1;													// Updating the least possible for next "I".
        }
        return res;															// Returning the result vector of ints.
    }
};