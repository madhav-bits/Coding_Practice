/*
*
//*****************************************2857. Count Pairs of Points With Distance k.********************************************

https://leetcode.com/problems/count-pairs-of-points-with-distance-k/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2],[4,2],[1,3],[5,2]]
5
[[1,3],[1,3],[1,3],[1,3],[1,3]]
0



// Time Complexity: O(n*k).													// n-size of the array, k-target num provided in question.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*k).													// n-size of the array, k-target num provided in question.
// Space Complexity: O(n).	
// This algorithm is Bit Manipulation based. We used the observation that if a^b=k, then k^b=a. We iter. over given array and for each num, we try to calc. 
// what other pair could match with curr. index to get target sum. As we add contribution from x, y axis index towards total, we assume each contribution 
// x,y with total=k, now we do x^v[i][0] and (k-x)^v[i][1] to get x, y- coordi. of other pair, we check #times this pair had occured and add it's count to res
// as curr. index and all this prev. occur would form pair. We pair curr. index with any future pairs of other pair if we add #occur of curr. pair to res 
// when the other pair occurred in later indices, thus every index is paired with matching index and counted towards res.







class Solution {
public:
    int countPairs(vector<vector<int>>& v, int k) {
        int res=0;
        unordered_map<int,unordered_map<int,int>>m;
        for(int i=0;i<v.size();i++) {
            for(int x=0;x<=k;x++) {											// Iter. over all possible combi from x,y axis.
                int x1=x^v[i][0], y1=(k-x)^v[i][1];							// Calc. the matching co-ordi to curr. pair.
                if(m.count(x1)==1 && m[x1].count(y1)==1) res+=m[x1][y1];	// If other indices occurred, we add their #occur to res.
            }
            m[v[i][0]][v[i][1]]++;											// We inc. #occur. of curr. coordi.
        }
        return res;															// Returning #matching pairs whose dist is k.
    }
};

