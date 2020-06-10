/*
*
//****************************************************997. Find the Town Judge.***********************************************

https://leetcode.com/problems/find-the-town-judge/description/


In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

 

Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
 

Constraints:

1 <= N <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


2
[[1,2]]


3
[[1,3],[2,3]]


3
[[1,3],[2,3],[3,1]]


3
[[1,2],[2,3]]


4
[[1,3],[1,4],[2,3],[2,4],[4,3]]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We take a boolean array to vote out all people who are not Judge. If the judge probables are not
// equal to 1, then we return -1. We iter. over all people to find the Judge probable, we iter. over trust array to find #people knows
// him, if it is total population-1, we return Judge number else we return -1.








class Solution {
public:
    int findJudge(int N, vector<vector<int>>& v) {
        if(N==1) return 1;
        vector<bool>isJudge(N, true);
        int rem=N;
        for(int i=0;i<v.size();i++){										// Iter. over trust array finding non-Judges.
            int node1=v[i][0];
            if(isJudge[node1-1]) rem--;										// Tracking #Judge probables.
            isJudge[node1-1]=false;											// Marking out people who aren't Judges.
        }
        // cout<<"rem: "<<rem<<endl;
        if(rem!=1) return -1;												// If Judge probables!=1, we return -1.
        int res=-1, cnt=0;
        for(int i=0;i<N;i++){												// We find the judge probable.
            if(isJudge[i]) res=i+1;
        }
        for(int i=0;i<v.size();i++){										// Cnt, #people knows judge probable.
            if(v[i][1]==res) cnt++;
            if(cnt==N-1) return res;										// If cnt is total-1, we return Judge number.
        }
        return -1;															// Judge not found, so return -1.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is similar to above solution. Here, we use a inEdge array which tracks #people trusting you, if you trust anyone, value
// stored will decrease. After iter. over trust array, we iter. over all nums, if we find any num. where #trusting it is total-1,we 
// return that num, if no num is found, we return -1.




class Solution {
public:
    int findJudge(int N, vector<vector<int>>& v) {
        if(N==1) return 1;
        vector<int>inEdge(N,0);
        for(int i=0;i<v.size();i++){										// Iter. over trust array.
            inEdge[v[i][0]-1]--;											// Tracking #people you trust.
            inEdge[v[i][1]-1]++;											// Tracking #people trusting you.
        }
        for(int i=0;i<N;i++){												// Iter. over all citizens.
            if(inEdge[i]==N-1) return i+1;									// If a num. has #people trusting him as total-1, return that num.
        }
        return -1;															// If Judge not found, we return -1.
    }
};
