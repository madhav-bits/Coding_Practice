/*
*
//******************************************************1981. Minimize the Difference Between Target and Chosen Elements.******************************************************

https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[4,5,6],[7,8,9]]
13
[[1],[2],[3]]
100
[[1,2,9,8,7]]
6
[[11,12],[12,13],[13,14],[14,15],[15,16]]
1
[[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 70],[1, 33]]
800






// Time Complexity: O(m*(n+k)).																				// m-rows, n-cols of matrix, k-max possible sum of nums, it depends on 'm'.
// Space Complexity: O(k).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n*k).																			// m-rows, n-cols of matrix, k-m*70-> which is range of sums possible.
// Space Complexity: O(k).	
// This algorithm is DP+Pruning based. Here, the range of nums and the target is small so we use a DP bool array to track all the sums which are possible to form till the curr. row. We use 2 arrays
// one for the prev. and one for the curr. row. While iter. over an array, we use the set/true indices in prev. DP array and those to the curr. num and update the indices in the curr. row DP array. 
// After finishing every row, we update the prev. row DP array to the curr. row's DP array values, so that we can use them in next iter. At end of iter. we iter. over last row's DP array and get
// the index closest to the target value and return the closest dist.

// We do some pruning here, we track the max. sum acheived for each row so that when we move to next row, we only move until maxSum so that we don't have to iter. over all indices unnecessarily.
// We also push each row's elems into unordered_set so that we remove duplicates and avoid repeating steps.
// These pruning steps played a very significant role in getting the solution accepted.


// This discussion post has some more explanation for this algo and had also discussed DFS approach too.
// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/discuss/1418757/DP-%2B-Pruning-4Sum-II-and-All-Sums






class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& v, int target) {
        vector<vector<bool>>dp(2, vector<bool>(v.size()*70+1,false));									// DP array to track which sums are possible until curr. row.
        dp[1][0]=true;
        int maxPrev=1;																					// Max. possible sum acheivable unti prev. row.
        for(int i=0;i<v.size();i++) {
            dp[i%2]=vector<bool>(v.size()*70+1, false);													// Resetting curr. row's DP array.
            int maxCurr=-1;
            for(int num: unordered_set(v[i].begin(), v[i].end())) {										// Iter. over curr. row's unique elem(As pushed into set).
                for(int k=0;k<=maxPrev;k++) {															// Iter. only until maxSum possible till prev. row.
                    if(dp[(i-1+2)%2][k]) {																// If 'k' sum is possible by rows until prev. row.
                        dp[i%2][k+num]=true;															// We mark 'k+num' as true for curr. row.
                        maxCurr=max(maxCurr, k+num);													// We track the maxSum possible till curr. row.
                    }
                }
            }
            maxPrev=maxCurr;																			// Updating the maxPrev so that we can use it for next row.
        }
        
		int res=INT_MAX, rows=v.size();
        for(int i=0;i<=maxPrev;i++) {																	// We iter. until maxSum of last row.
            if(dp[(rows-1)%2][i] && abs(i-target)<res) res=abs(i-target);								// Tracking the closest sum to target.
        }
        return res;																						// Returning the closest sum to target.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*(n+k)).																				// m-rows, n-cols of matrix, k-max possible sum of nums, it depends on 'm'.
// Space Complexity: O(k).	
// This algorithm is Bitset based. Here, since the totals we are trying to acheive is small and also it requires lots of updates to track possible sums, bitset would be optimal data structure here.
// We use bitset datatype to store what sums are possible to acheive till curr. row. When working on a row, we use bitset of prev. row and use it update the curr. row's bitset array. We left-shift
// prev. row's bitset datatye by 'k' steps as a result all set bits move to left by k steps indicating that the total of all those sums had increase by 'k' and it is stored in curr. row's bitset.
// With a single left-shift all prev. sums input had been taken, curr. value is added and all those sums are udpated at the same time, If not for bitset datatype this entire step would be an O(n)
// TC, thus improving speed. We do the same for all values in this array and OR the curr. row's bitset datatype. At the end of iter. we iter. over all possible sum values and get the closest one
// to target and return it.









class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& v, int target) {
        
        vector<bitset<5000>>dp(2);																		// Bitset array to track all possible sums till curr. row.
        dp[1].set(0);																					// Default case.
        for(int i=0;i<v.size();i++) {
            dp[i%2].reset();																			// Resetting curr. row's bitset.
            for(int num:v[i]) {																			// Iter. over curr. row's values.
                dp[i%2]|=(dp[(i-1+2)%2]<<num);															// LEFT-SHIFT prev. row's bitset by curr. num and OR it onto curr. row's bitset datatype.
            }
        }
        
        int res=INT_MAX, rows=v.size();
        for(int i=1;i<5000;i++) {																		// Iter. over all possible sums.
            if(dp[(rows-1)%2].test(i) && abs(i-target)<res) res=abs(i-target);							// If sum acheivable, we try to get the closest sum and store the gap.
        }
        return res;																						// Returning the closest sum's gap from target value.
    }
};

