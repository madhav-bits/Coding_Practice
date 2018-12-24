/*
*
//************************************************************962. Maximum Width Ramp.*****************************************************

Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

Note:

1) 2 <= A.length <= 50000
2) 0 <= A[i] <= 50000




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[3,4,2,6,2,1,5]




[3,6,1,2,1,5,2,3,1]




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. Here, for every value, we need smaller value with smaller indices, so we sort the given values based 
// on values, if values are same, we sort based on indices. Now, we extract values from PQ, if a value k is extracted, then all smaller values are 
// already extracted, of all those values, we need the minm. index(We track it through a variable), if the minm. index is >index of k, then we 
// don't update final result var else we update. Once the PQ is empty, we return the final result var.








class Solution {
public:
    
    
    struct comp{															// Custom comparator.
        bool operator()(pair<int,int>&lt, pair<int,int>&rt){				// Sort based on values, if values equal sort based on indices.
            return (lt.first>rt.first||(lt.first==rt.first && lt.second>rt.second));
        }
    };
    
    int maxWidthRamp(vector<int>& v) {
        int res=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;			// Declaring th PQ.
        for(int i=0;i<v.size();i++){										// Pushing value, index into PQ.
            pq.push({v[i],i});
        }
        int minm=pq.top().second;											// Init. the minm. index encountered.
        pq.pop();															// Pop first value.
        while(!pq.empty()){													// Till PQ is empty.
            pair<int,int>curr=pq.top();										// Extracting elem. from PQ.
            pq.pop();
            res=max(res, curr.second-minm);									// Trying to udpate final res, curr. index-minm. index till now.
            // cout<<"first: "<<curr.first<<" index: "<<curr.second<<endl;
            minm=min(minm, curr.second);									// Updating the minm. index encountered till now.
            
        }
        return res;															// Returning the final result(maxm. diff. in indices).
    }
};