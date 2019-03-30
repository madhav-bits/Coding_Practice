/*
*
//******************************************************689. Maximum Sum of 3 Non-Overlapping Subarrays.***********************************************

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the 
lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,1]
1


[1,5,6,1,2,9,4,8,2,8,3,6,4,2,5]
4


[1,5,6,1,2,9,4,8,2,8,3,6,4,2,5]
5



[1,5,6,1,2,9,4,8,2,8,3,6,4,2,5]
1





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based solution. Here, since we need three non-overlapping subarrays, we form dp array from the left, right
// noting the max. subarray till window ending at index 'i' from '0' index. Similarly, right[i] stores index from where the window with max. sum starts
// to it's right. Now, we iter. probable indices of middle window and get the window with max. sum to left, right using dp arrays and returning the maxm.
// sum window.







class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& v, int k) {
        vector<long long int>total(v.size()+1,0);
        int sum=0;
        for(int i=0;i<v.size();i++){										// Accumulating array.
            sum+=v[i];
            total[i+1]=sum;
        }
        vector<int>left(v.size()+1,0), right(v.size()+1, 0);				// Stores indices from where the window with maxm. sum starts to lef, right of curr. index.

        // cout<<"left"<<endl;
        long long int maxm=INT_MIN, psn=-1;									// Default init.
        for(int i=k-1;i<v.size();i++){										// Tracking maxm. sum windows to left of curr. window start ('i+1-k'). 
            long long int val=total[i+1]-total[i+1-k];						// Window starts at index 'i+1-k'
            if(val>maxm){													// Get the leftmost max. sum window.
                psn=i-k+1;
                maxm=val;
            }
            // cout<<" i: "<<i<<" and psn: "<<psn<<" and maxm: "<<maxm<<endl;
            left[i]=psn;
        }

        // cout<<"right; "<<endl;
        psn=-1;
        maxm=INT_MIN; 
        for(int i=v.size()-k;i>=k;i--){										// Tracking maxm. sum windows to right of curr. window start 'i'.
            long long int val=total[i+k]-total[i];							// Window starts at index 'i'.
            if(val>=maxm){													// Getting the leftmost maxm. sum window.
                psn=i;
                maxm=val;
            }
            // cout<<" i: "<<i<<" and psn: "<<psn<<" and maxm: "<<maxm<<endl;
            right[i]=psn;
        }
        // cout<<"mid: "<<endl;
        vector<int>res;
        maxm=INT_MIN;
        for(int i=k;i+k-1<v.size()-k;i++){									// ITer. over all possible middle window start indices.
            int lIndex=left[i-1], rIndex=right[i+k];
            long long int lt=total[lIndex+k]-total[lIndex];
            long long int rt=total[rIndex+k]-total[rIndex];
            long long int mid=total[i+k]-total[i];							// Calc. left, right, curr. window values.
            // cout<<"index: "<<i<<" and lt: "<<lt<<" rt: "<<rt<<" mid: "<<mid<<endl;
            if(lt+rt+mid>maxm){												// Track the maxm. sum of three windows with leftmost indices.
                maxm=lt+rt+mid;
                res={lIndex, i,rIndex};										// Updating the result var.
            }
        }
        return res;															// Returning the start of three windows with maxm. sum with leftmost indices.
    }
};