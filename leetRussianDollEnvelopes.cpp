/*
*
//**********************************************************354. Russian Doll Envelopes.***************************************************

You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both 
the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.

Example:

Input: [[5,4],[6,4],[6,7],[2,3]]
Output: 3 
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[5,4],[6,4],[6,7],[2,3]]


[[2,3],[5,5],[6,4],[6,7],[7,8]]


[[3,1],[4,2],[5,20],[5,10],[5,8],[6,9]]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is based on Custom sorting. We sort given values based on inc. widths, if the widths are same, they are sorted in desc. order
// of their heights. As a result, the answer had become finding Longest Increasing Height(All widths are already sorted). Now, this problem is 
// entirely same as problem 300) Longest Increasing Subsequence. We use a DP array, where dp[i] indicates the smallest height of all inc. subseq.
// of length i+1. If at pres. DP array is of length 'x', the new elem. is greater than all values, then this would form subseq. of length 'x+1', so 
// we new entry into DP array. If we get elem. with smaller height for a subseq. length we replace the older height. At the end of iter. we need 
// to return the length of the DP array.



// This link has some explanation about Tails(DP array) and inc. subseq. tails.
// https://leetcode.com/problems/longest-increasing-subsequence/discuss/74824/JavaPython-Binary-search-O(nlogn)-time-with-explanation

// This link has some explanation abt Sorting widths in inc. order and Heights in dec. order(If widths are equal). 
// https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation?page=1




class Solution {
public:
    
    struct comp{															// Custom sorting on inc. widths and dec. heights(If widths are equal).
        bool operator()(const pair<int,int>&a,pair<int,int>&b){
            return (a.first<b.first ||(a.first==b.first && a.second>b.second));
        }    
    };
    
    int maxEnvelopes(vector<pair<int, int>>& v) {
        // auto comp=[const pair<int,int>&a,const pair<int,int>&b]{			// Another method to write custom comparator.(Not proper syntax).
        //     return (a.first<b.first ||(a.first==b.first && a.second<b.second));
        // };
        
        sort(v.begin(), v.end(),comp());									// Custom sorting given array.
        vector<int>dp;														// Stores smallest height for inc. seq. of all lengths.
        for(int i=0;i<v.size();i++){										// Iter. over entire given array.
            // cout<<"Curr. index: "<<i<<endl;
            auto it=lower_bound(dp.begin(), dp.end(),v[i].second);			// Looking for curr. height in DP array.
            int ind=it-dp.begin();											// Calc. the index in DP array for curr. height.
            // cout<<"index: "<<ind<<endl;
            if(ind==dp.size()) dp.push_back(v[i].second);					// If all elem. in vector are smaller,then push curr. height into vector.
            else dp[ind]=v[i].second;										// Else, replace the previous height for that inc. subseq. length.
        }
        return dp.size();													// Return the vector size.(Longest increasing subsequence).
        
    }
};