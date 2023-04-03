/*
*
//******************************************************2121. Intervals Between Identical Elements.******************************************************

https://leetcode.com/problems/intervals-between-identical-elements/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3,1,2,3,3]
[10,5,10,10]
[4,7,5,2,8,1,10,13,15,2,8,3,10,12,17,28,34,28,45,23,27,36,7]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Prefixsum+SuffixSum based. Here, we use prefixSum, suffixSum arrays  to store the prefix dist from all prev. indices(which has value arr[i]) to index 'i' to 'i'. When we are working on next index to 'i' 
// we use the prefixDist to 'i', it store dist. of all prev. indices to 'i', if we multiply #indices till 'i next index' and (dist from 'i' to 'i next index') this is adding #steps to move all prev. indices from 'i' to
// 'i next index' prefix[i]=prefix[i-1]+i*(i-prev(i)). We do the same for suffixSum for every index, we add both these arrays to get the dist. of each index to all it's value recurring indices.







class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        vector<long long int>left(arr.size(),0), right(arr.size(),0);									// Init. the prefix, Suffix arrays.
        unordered_map<int, pair<long long int,int>>m,n;													// Maps which store  {#occur. of curr. value, last occur. of curr. value} for both drns.
        for(int i=0;i<arr.size();i++) {																	// Processing the prefix sums.
            if(m.count(arr[i])) {
                left[i]=left[m[arr[i]].second]+(i-m[arr[i]].second)*m[arr[i]].first;					// prefixSum till last occur. + (gap from last occur.)* (#occur. till last occur).
                m[arr[i]].second=i;																		// The above eqn adds #steps to move to last occur. and #steps to move all occur. from last occur. to curr. occur. index.
                m[arr[i]].first++;
            } else m[arr[i]]={1,i};																		// Default values of {#occur, last occur. index}
        }
        
        for(int i=arr.size()-1;i>=0;i--) {																// Processing the suffix Sums.
            if(m.count(arr[i])) {
                right[i]=right[n[arr[i]].second]+(n[arr[i]].second-i)*n[arr[i]].first;
                n[arr[i]].second=i;
                n[arr[i]].first++;
            } else n[arr[i]]={1,i};
        }

        for(int i=0;i<arr.size();i++) left[i]+=right[i];												// Adding the prefix, Suffix Sums.
        return left;																					// Returning the #steps array.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This solution is based on PrefixSum, SuffixSum based but a small change in the way how we calculate Prefix, Suffix Sums.

// If we have three indices x<y<z as three occuring indices of a number, while calc. prefixSum of dist. to index 'z', we do z-x+z-y->2*z-(x+y), this is simplified in the below code as #prev_occur.*i-(cumulativeSum till prev. index)
// for prefixSum and (cumulativeSum till next index)- #next_occur.*i for suffixSum calculations. Below link has clear explanation.



// This solution has a detailed explanation in the discussion forum:
// https://leetcode.com/problems/intervals-between-identical-elements/discuss/1647522/Java-or-TC%3A-O(N)-or-Simple-or-Explanation







class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        unordered_map<int, pair<long long int, int>>m;													// {prefixSum of indices, #indices}
        vector<long long int>prefixSum(arr.size(),0), suffixSum(arr.size(), 0);
        for(int i=0;i<arr.size();i++) {																	// Calculating prefixSum of distances for all indices.
            if(m.count(arr[i])) {
                prefixSum[i]=1ll*m[arr[i]].second*i-m[arr[i]].first;									// This expression is simplified form of prefixSum equation explained above.
            }
            m[arr[i]].first+=i;																			// Updating #occur, prefixSum of index values.
            m[arr[i]].second++;
        }
        
        m.clear();
        for(int i=arr.size()-1;i>=0;i--) {																// Calculating suffixSum of distances for all indices.
            if(m.count(arr[i])) {
                suffixSum[i]=m[arr[i]].first-(1ll*m[arr[i]].second*i);									// This expression is simplified form of SuffixSum equation explained above.
            }
            m[arr[i]].first+=i;																			// Updating #occur, suffixSum of index values.
            m[arr[i]].second++;
        }
        
        for(int i=0;i<arr.size();i++) {																	// Adding prefixSum, suffixSum for all indices.
            prefixSum[i]+=suffixSum[i];
        }
        return prefixSum;																				// Returning the #steps array.
    }
};

