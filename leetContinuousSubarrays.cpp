/*
*
//******************************************************2762. Continuous Subarrays.******************************************************

https://leetcode.com/problems/continuous-subarrays/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,2,4]
[1,2,3]
[5,4,6,7,6,5,4,3,2,3,4,5,6,7,8,7,6,5,4,5,6,5,4,3,4,3,4,5]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Deque based. Here, we check the diff of newly added element to the max, min of the elements present in the subarray satisfying conditions,
// as we need max, min of the subarrays and we have to keep track of them in case max, min get deleted in the process, in such cases deque would be best DS
// to use. Here, first we pop all indices from min, max DQs which are less, more than curr. value respectively and add curr. value into these DQs. Now, our
// DQs show max, min of the subarray, now we have to pop all those extremes which brakes the conditions, we also keep track of the start of the subarray, 
// when condition not met, we pop elements from DQs if their indices match prevIndex value thus we maintain only indices in DQs which are part of subarray, 
// on the extremes satisfy the condition, we add the curr. length to res as all the indices can start subarrays from their to curr. index and return res at the
// end of iter.


// This solution can be used for any abs. difference requirement.





class Solution {
public:
    long long continuousSubarrays(vector<int>& v) {
        // Use deques to track min, max values in the subarray.
        long long int res=0;
        int prevIndex=0;
        deque<int>minDq, maxDq;
        for(int i=0;i<v.size();i++) {
            while(!minDq.empty() && v[minDq.back()]>=v[i]) minDq.pop_back();// Remove entries which are >= curr. entry from minDQ.
            while(!maxDq.empty() && v[maxDq.back()]<=v[i]) maxDq.pop_back();// Remove entries which are <= curr. entry from maxDQ.
            minDq.push_back(i);												// Adding curr. entry into both DQs.
            maxDq.push_back(i);
            
            while(v[maxDq.front()]-v[minDq.front()]>2) {					// Removing extremes which don't satisfy the conditions.
                if(maxDq.front()==prevIndex) maxDq.pop_front();				// Removing entries which aren't part of subarray.
                if(minDq.front()==prevIndex) minDq.pop_front();				// Removing entries which aren't part of subarray.
                prevIndex++;												// After removing startIndex, we move to next index.
            }
            res=res+i-prevIndex+1;											// Add subarray length to res, add all the indices can start subarrays from their to curr. index.
        }
        return res;															// Returning the total #subarrays which satisfy the condition.
    }
};



