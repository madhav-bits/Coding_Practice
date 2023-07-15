/*
*
//******************************************************2364. Count Number of Bad Pairs.******************************************************

https://leetcode.com/problems/count-number-of-bad-pairs/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,1,3,3]
[1,2,3,4,5]
[5,4,6,7,5,4,2,4,3,6,5,4,8,7,6,5,4]
[5,4,3,2,1]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is map based. At every step in iter. we remove all prev. good pairs from the total pairs possible with curr. index, we also inc. the occur. 
// tracker of curr. index's diff in the map and return res at the end of iter.







class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        long long res=0;
        unordered_map<int,int>m;											// Tracks #occur. of a diff.
        for(int i=0;i<v.size();i++) {
            int diff=i-v[i];
            if(m.count(diff)==1) res+=i-m[diff];							// Adding (total Pairs -good pairs) of curr. index with prev. pairs.
            else res+=i;
            m[diff]++;														// Inc. the curr. diff count.
        }
        return res;															// Returning the total #bad pairs.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This solution is map based. Here, we calc. total #pairs possible and substract total #good pairs possible from it and retur #bad pairs.








class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        int len=v.size();
        long long res=(1ll*len*(len-1))/2;									// Calculating total #pairs.
        unordered_map<int,int>m;
        for(int i=0;i<v.size();i++) {
            m[i-v[i]]++;													// Tracking #occur. of each diff.
        }
        for(auto it=m.begin();it!=m.end();it++) res-=(1ll*it->second*(it->second-1))/2;// Removing #good pairs possible with curr./key diff.
        return res;															// Returning the total #bad pairs.
    }
};

