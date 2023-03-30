/*
*
//******************************************************1962. Remove Stones to Minimize the Total.******************************************************

https://leetcode.com/problems/remove-stones-to-minimize-the-total/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,4,9]
2
[4,3,6,7]
3



// Time Complexity: O(n+klogn).																			//n-#nums provided, k-#operations.
// Space Complexity: O(n).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+klogn).																			//n-#nums provided, k-#operations.
// Space Complexity: O(n).	
// This algorithm is Greedy+Priority Queue based. Here, as we are trying to minimum total after k operations, we have to remove half of greatest number available at every step, we get the greatest
// number using PQ, after removing num/2, we push the rest value into PQ and move to delete next greater num. We calc. total of all nums while pushing nums into PQ, after every operation, we remove
// the part that was removed during operation from the total and return the total after k operations.





class Solution {
public:
    int minStoneSum(vector<int>& v, int k) {
        int res=0;
        priority_queue<int>pq;
        for(int&num:v) {																				// Push all nums into PQ and get their total.
            res+=num;
            pq.push(num);
        }
        while(k) {																						// Perform K operations.
            int val=pq.top();
            pq.pop();
            res-=val/2;																					// Removing the substracted part from the total.
            val-=val/2;																					// Updating the curr. num after operation.
            // cout<<"subtracting: "<<val/2<<endl;
            pq.push(val);																				// Pushing updating num into PQ.
            k--;																						// Dec. the operations tracker value.
        }
        return res;																						// Returning the sum of all nums after K operations.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+l+k).																			//n-#nums provided, k-#operations, l-range of the nums.
// Space Complexity: O(l).	
// This iteration is Greedy+Counting Sorting based. Here, since the nums range is small, we can make use of counting sort and we greedily pick large values and split it into half, when reducing we reduce the occur. count in 
// the freq. array, and increase the count in the num/2 index to reflect new number after split. If the curr. num occur. is 0, we go towards smaller values in search of non-zero occur of nums. We do the same for K operations.










class Solution {
public:
    int minStoneSum(vector<int>& v, int k) {
        
        
        int res=0, maxm=0;
        vector<int>occur(10001,0);
        for(int&num:v) {
            occur[num]++;
            res+=num;
            if(num>maxm) maxm=num;
        }
        
        while(k && maxm) {
            if(occur[maxm]==0) {																		// If #occur. for curr. num is zero, we move to lesser values.
                maxm--;
                continue;
            }
            occur[maxm]--;																				// Dec. the freq. of curr. num.
            k--;
            res-=maxm/2;																				// Removing the decreased value from the total of the nums.
            int val=maxm-maxm/2;
            occur[val]++;																				// Inc. the freq. count of the resulting num after the operation.
        }
        return res;																						// Returning the total of the nums after K operations.
    }
};
