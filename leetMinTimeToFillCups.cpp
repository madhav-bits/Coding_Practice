/*
*
//******************************************************2335. Minimum Amount of Time to Fill Cups.******************************************************

https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,4,2]
[5,4,4]
[5,0,0]
[7,8,6]
[7,8,12]
[1,2,3]
[10,10,11]



// Time Complexity: O(n+m+l).												// n,m,l-three values in the given array.
// Space Complexity: O(1).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m+l).												// n,m,l-three values in the given array.
// Space Complexity: O(1).	
// This algorithm is Greedy Approach based. Here, we have to two cup filling situation as much as possible to get min. moves. Here, we greedily pick the indices
// with high values in every step, so that any of the cups requirement would get finished soon leaving us with no option but to fill only 1 cup per move. We
// slighly prune here by making multiple moves in an iter. such that the least of the two cups requirement would be less than the least cup requirement as 
// we will be repeating this step in every iter, if we do single move per iter. But, in a extreme case[6,6,6] or where all the cup requirements are the same,
// we will be forced to make single move per iter.







class Solution {
public:
    int fillCups(vector<int>& v) {
        int res=0, total=0;
        sort(v.begin(), v.end());
        while(v[1]>0) {														// Iter. as long as 2 cup can be filled in single move is possible.
            int moves=v[1]-max(0, v[0]-1);									// Making lowest value of the chosen to be < least cup requirement.
            res+=moves;														// Adding moves to res.
            v[1]-=moves;													// Dec. the values accordingly.
            v[2]-=moves;
            swap(v[0], v[1]);												// Arranging so that array still remains sorted.
            if(v[1]>v[2]) swap(v[1], v[2]);
            // cout<<"v[0]: "<<v[0]<<" v[1]: "<<v[1]<<" v[2]: "<<v[2]<<" and moves: "<<moves<<endl;
        }
        res+=v.back();														// Adding if any single cup filling moves left.
        return res;															// Returning total #moves made to fill all cups.
    }
};

