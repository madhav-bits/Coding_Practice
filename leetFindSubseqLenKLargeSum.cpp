/*
*
//***************************************2099. Find Subsequence of Length K With the Largest Sum.***************************************

https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,1,3,3]
2
[-1,-2,3,4]
3
[3,4,3,3]
2
[5,4,3,6,5,4,3,2,6,7,6,5,4,3,4,56,5,4,3]
7



// Time Complexity: O(n+klogn+k).											// Solution 2 has better Asymptotic Time Complexity but larger Space Complexity.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogk+k+klogk).
// Space Complexity: O(k).	
// This algorithm is Priority Queue based. Here, we first maintain Min PQ to maintain top K values, we later transfer all the corresponding indices to another
// array to sort them, we later iter over sorted indices and collect corresponding numbers in order and push them to res inorder and return res.







class Solution {
public:
    vector<int> maxSubsequence(vector<int>& v, int k) {
        if(k==v.size()) return v;
        vector<int>res(k, 0);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<v.size();i++) {
            if(pq.size()<k || v[i]>pq.top().first) {						// Maintaining top K values.
                pq.push({v[i], i});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<int>u;
        while(!pq.empty()) {												// Pushing indices corres. to top K values to array.
            u.push_back(pq.top().second);
            pq.pop();
        }
        sort(u.begin(), u.end());											// Sort indices of top K values.
        for(int i=0;i<k;i++) res[i]=v[u[i]];								// Collecting top K values in inc. order of indices.
        return res;															// Returning top K values in inc. order of indices.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+klogn+k).
// Space Complexity: O(n).	
// This algorithm is slightly modified version of the above algo. Here, rather than restricting the pq size to grow above k, we allow it to reach arr.size(), 
// because Time Complexity to build/heapify an array is linear, so we build entire Max PQ in linear time. Transfer top k values to another PQ to sort indices
// we later indices and push corresponding values to res. 




class Solution {
public:
    vector<int> maxSubsequence(vector<int>& v, int k) {
        if(k==v.size()) return v;
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        priority_queue<int, vector<int>, greater<int>>pq1;
        for(int i=0;i<v.size();i++) pq.push({v[i], i});
        while(!pq.empty() && k) {											// Collecting indices of top K values and pushing indices to Min PQ.
            pq1.push({pq.top().second});
            pq.pop();
            k--;
        }
        while(!pq1.empty()) {												// Collecting values corresponding to sorted indices of top K values.
            res.push_back(v[pq1.top()]);
            pq1.pop();
        }
        return res;															// Returning top K values in inc. order of indices.
    }
};

