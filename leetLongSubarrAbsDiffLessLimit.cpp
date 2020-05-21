/*
*
//**************************1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit.************************

https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/


Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute 
difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[8,2,4,7]
4
[10,1,2,4,7,2]
5
[4,2,2,2,4,4,2,2]
0


[4,8,5,1,7,9]
6



// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).	
// This algorithm is Stack based solution. Here, since we want the substring elem. max. diff to be <=limit. We maintain two stacks
// one maintains that maxm. values in the substring, other maintains minm. If curr. num's diff with maxm/minm






class Solution {
public:
    int longestSubarray(vector<int>& v, int limit) {
        int res=1, start=0, close=0;
        deque<int>maxQue, minQue;
        maxQue.push_back(0);
        minQue.push_back(0);
        for(int i=1;i<(int)v.size();i++){
            close=i;
            // cout<<"i: "<<i<<" start: "<<start<<" and close: "<<close<<endl;
            if(v[maxQue.front()]-v[i]>limit){
                while(!maxQue.empty() && v[maxQue.front()]-v[i]>limit){
                    if(start==maxQue.front()) maxQue.pop_front();
                    if(start==minQue.front()) minQue.pop_front();
                    start++;
                }
            }else if(v[i]-v[minQue.front()]>limit){
                while(!minQue.empty() && v[i]-v[minQue.front()]>limit){
                    if(start==minQue.front()) minQue.pop_front();
                    if(start==maxQue.front()) maxQue.pop_front();
                    start++;
                }
            }
            while(!maxQue.empty() && v[maxQue.back()]<v[i]) maxQue.pop_back();
            while(!minQue.empty() && v[minQue.back()]>v[i]) minQue.pop_back();
            maxQue.push_back(i);
            minQue.push_back(i);
            res=max(res, close-start+1);
        }
        return res;
        
        
        
        // int minIndex=0, maxIndex=0, res=1;
        // int start=0, close=0, lt=0;
        // for(int i=1;i<(int)v.size();i++){
        //     if(abs(v[maxIndex]-v[i])>limit){
        //         maxIndex++;
        //         lt=max(lt, maxIndex);
        //         for(int j=lt;j<i;j++){
        //             if(v[j]>v[maxIndex]) maxIndex=j;
        //             if(abs(v[j]-v[i])>limit){
        //                 lt=max(lt, j+1);
        //                 maxIndex=j+1;
        //             }
        //         }
        //     }
            
        //     if(abs(v[minIndex]-v[i])>limit){
        //         minIndex++;
        //         lt=max(lt, minIndex);
        //         for(int j=lt;j<i;j++){
        //             if(v[j]<v[minIndex]) minIndex=j;
        //             if(abs(v[j]-v[i])>limit){
        //                 lt=max(lt, j+1);
        //                 minIndex=j+1;
        //             }
        //         }
        //     }
            
        //     minIndex=(v[i]<v[minIndex])?i:minIndex;
        //     maxIndex=(v[i]>v[maxIndex])?i:maxIndex;
        //     res=max(res, i-lt+1);
        // }
        // return res;
    }
};



