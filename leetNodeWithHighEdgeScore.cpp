/*
*
//******************************************************2374. Node With Highest Edge Score.******************************************************

https://leetcode.com/problems/node-with-highest-edge-score/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,0,0,0,7,7,5]
[2,0,0,2]
[4,4,4,4,1,2,0]
[4,4,4,4,1,2,5]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We use another array to keep track of the score of nodes based on the directional edges provided, at every step we try 
// maximize the score of the res, if the max. scores are equal, we try to minimize the node number. We return the node number with highest score at the end 
// of iter.







class Solution {
public:
    int edgeScore(vector<int>& v) {
        vector<long long int>score(v.size(), 0);							// To store the scores of the each of the nodes.
        int res=-1;
        for(int i=0;i<v.size();i++) {
            score[v[i]]+=i;													// Updating the score of the concerned node.
            if(res==-1 || (score[v[i]]>score[res] || (score[v[i]]==score[res] && v[i]<res))) res=v[i];// Track the node with highest score.
        }
        return res;															// Returning the node with highest score.
    }
};

