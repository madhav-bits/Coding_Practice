/*
*
//**********************************************************517. Super Washing Machines.***************************************************

You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing 
machines at the same time .

Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum 
number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

Example1

Input: [1,0,5]

Output: 3

Explanation: 
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
Example2
3rd move:    2     1 <-- 3    =>    2     2     2   

Input: [0,3,0]

Output: 2

Explanation: 
1st move:    0 <-- 3     0    =>    1     2     0    
2nd move:    1     2 --> 0    =>    1     1     1     
Example3

Input: [0,2,0]

Output: -1

Explanation: 
It's impossible to make all the three washing machines have the same number of dresses. 
Note:
The range of n is [1, 10000].
The range of dresses number in a super washing machine is [0, 1e5].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,5]


[7,1,7]


[20,5,20]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Observation based. Here, we iterate over entire array, track # extra clothes from start till curr. index. These extra
// clothes would be shifted right side of curr. index. We will also calculate the extra clothes in each index, as these would take linear time.
// We try to get max. of these two vars and try to update the result min moves(Here max. extracted from the entire iteration).




// Here, max. moves required to maintain avg. clothes everywhere during iter. is the overall min. moves required.

// This link has some more description about the below algo.
// https://leetcode.com/problems/super-washing-machines/discuss/99185/Super-Short-and-Easy-Java-O(n)-Solution





class Solution {
public:
    int findMinMoves(vector<int>& v) {
        int sum=0;
        for(auto num:v) sum+=num;
        if(sum%v.size()!=0) return -1;										// If the avg. isn't integer, return -1(Not possible).
        int avg=sum/v.size();												// Calc. avg.
        int res=0;															// Tracks moves required.
        int reqLeft=0;														// Tracks extra clothes over avg in indices to the left of curr. index.
        for(auto num:v){													// Iter. over all indices.
            int give=num-avg;       										// Giving away from this index.
            reqLeft+=give;          										// Total req. of all elem. to the left of curr. index(Incl. curr. index).
            res=max(max(res,abs(reqLeft)),give);							// Extracting Max. flow through curr. index, try updating result.
        }
        return res;															// Returning min. moves.
        
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algo. is observation based. Here, we iter. over entire array and track #clothes req. on left, right side at each index. If both have 
// lesser clothes, we send extra clothes from curr. index(linear time). If one side has more, other has small amount of clothes lacking, then 
// we need abs(max) moves(as we move send clothes from curr. index). At each step, we try to update the moves required var. At the end, we 
// return this min moves required. 


// Here, max. moves required to maintain avg. clothes everywhere during iter. is the overall min. moves required.



// This link has some more description about the below algo.
// https://leetcode.com/problems/super-washing-machines/discuss/99181/c-16ms-on-solution-with-trivial-proof






class Solution {
public:
    int findMinMoves(vector<int>& v) {
        int len=v.size();
        vector<int>dp(v.size()+1,0);
        for(int i=0;i<v.size();i++){										// Hashing sum of indices till that index in index+1.
            dp[i+1]=dp[i]+v[i];
        }
        if(dp.back()%v.size()!=0) return -1;								// If avg isn't integer, return -1.
        int avg=dp.back()/v.size();											// Calc. avg.
        int res=0;															// Tracks min. moves required.
        
        for(int i=0;i<v.size();i++){
            int l=i*avg-dp[i];												// Calc. #clothes required on both sides of curr. index.
            int r=(len-1-i)*avg-(dp.back()-dp[i+1]);
            if(l>0 && r>0) res=max(res,l+r);								// If both sides have lesser clothes.(Send from curr. index.)
            else res=max(res, max(abs(l), abs(r)));							// If not we make max. of l, r moves to get avg. clothes everywhere.
            
        }
        return res;															// Returning min. moves required.
        
    }
};