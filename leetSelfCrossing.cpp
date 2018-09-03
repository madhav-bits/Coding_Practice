/*
*
//************************************************************335. Self Crossing.*****************************************************

You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] 
metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

Example 1:

Input: [2,1,1,2]

?????
?   ?
???????>
    ?

Input: true 
Explanation: self crossing
Example 2:

Input: [1,2,3,4]

????????
?      ?
?
?
?????????????>

Output: false 
Explanation: not self crossing
Example 3:

Input: [1,1,1,1]

?????
?   ?
?????>

Output: true 
Explanation: self crossing




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,1,2]


[4,3,5,5,2,3]


[4,3,5,5,2,2]


[3,3,3,2,1,1]


[1,1,2,2,3,3,4,4,5]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. We can classify the self crossings into three types.
// 1) 4th edge passing through 1st edge and same pattern to later edges.
// 2) 5th edge passing through 1st edge and same pattern to later edges.
// 3) 6th edge passing through 1st edge and same pattern to later edges.
// We check specifically for these cdns, for each edge, if found, return true(Self Crossing occurs), if not return false at the end.

// If above explanation not understood, this link provides more insights into the above approach.
// https://leetcode.com/problems/self-crossing/discuss/79131/Java-Oms-with-explanation


// When, I was going through cases, didn't puch much observation, was thinking that self crossings might occur with very previous edges. But, 
// in real, self crossings occurs only with previous edges with diff. of 6 or less b/w indices.







class Solution {
public:
    bool isSelfCrossing(vector<int>& v) {
        if(v.size()<=3) return false;										// If <=3 edges present, return false(No Self Crossing).
        for(int i=3;i<v.size();i++){
            if(v[i]>=v[i-2] && v[i-3]>=v[i-1]){								//4->1
                // cout<<"side: "<<i<<" and type: "<<1 <<endl;
                return true;
            } 
            if(i>=4 && v[i-1]==v[i-3] && v[i-2]-v[i-4]>0 && v[i]>=v[i-2]-v[i-4]){//5->1
                // cout<<"side: "<<i<<" and type: "<<2<<endl;
                return true;
            } 
            if(i>=5 && v[i-3]-v[i-5]>0 && v[i-1]>=v[i-3]-v[i-5] && v[i-2]-v[i-4]>0 && v[i]>=v[i-2]-v[i-4] && v[i-1]<=v[i-3]){//6->1
                // cout<<"side: "<<i<<" and type: "<<3<<endl;
                return true;
            } 
        }
        return false;														// No Self-Crossing observed.
    }
};