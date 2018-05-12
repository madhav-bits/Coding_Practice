/*
*
//******************************************************239. Sliding Window Maximum.***********************************************

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see 
the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note: 
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,-1]
3

[2,-1]
1

[]																	// Despite mentioning "k" and size of array>1, this test case is tested for.
0





// Time Complexity: O(NlogN).  												// Doesn't exactly meet the Followup's requirements.
// Space Complexity: O(N).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(NlogN).												// Doesn't exactly meet the Followup's requirements.
// Space Complexity: O(N).	
// This algorithm makes use of Max Heap with pair as object and sort the contents based on the values of vector. At each step extr. Max. value
// if this value doesn't belong to curr. interval then ingnore(pop) it, extract until a max. val in the given interval. For setting up Max Heap
// time is O(k) and for pushing else N-k elements it takes (N-k)logN. Beats 60% of submissions.



class Solution {
public:
    
    struct comparator{                                                      // Implementing a customized Max Heap.
        bool operator()(const pair<int, int> a, const pair<int, int>b){
            return a.first<b.first;											// Sort based on the values from vector.
        }
    };
    
    
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator>pq;
        vector<int> res;
        if(v.size()==0) return res;
        for(int i=0;i<k;i++){												// Pushing the first "k" length values.
          pq.push(make_pair(v[i],i));  
        } 
        pair<int, int> p=pq.top();
        res.push_back(p.first);												// Extracting the first top value.
        for(int i=k;i<v.size();i++){	
            //cout<<"Curr. scanning index i: "<<i<<endl;
            pq.push(make_pair(v[i],i));										// Pushing values from index "k" to end.
            pair<int, int> temp;
            temp=pq.top();
            while(i-temp.second>=k){										// If Max. value is not from interval, then ignore(pop) it.
                //cout<<"Curr. extraced top node's index is: "<<temp.second<<endl;
                pq.pop();
                temp=pq.top();
            }
            //cout<<"Curr. pushed val. is: "<<temp.first<<endl;
            res.push_back(temp.first);										// Push the max. value from the interval into res. vector.
        }
        
        return res;															// Return the final res. vector.
    }
};