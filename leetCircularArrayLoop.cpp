/*
*
//**********************************************************457. Circular Array Loop.***************************************************

You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if 
it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element 
 element along the loop. The loop must be "forward" or "backward'.

Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.

Example 2: Given the array [-1, 2], there is no loop.

Note: The given array is guaranteed to contain no element "0".

Can you do it in O(n) time complexity and O(1) space complexity?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,6,6,7,7]
[]
[1,1,1,1]
[1,1,1,1,2,2,2,3,3]
[1,1,1,1,2,2,2,3,3,4,4,4,4,5,6]
[1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,7,8,9,10,1,1,1,1,1]


"aaraxrafafaodifjafibbbbiiraxbxbjit"
"rabbit"


"abcd"
"abcbadefged"

"RDDDRDRR"

"2*1-2+3-4"

[[0,0,1],[1,1,0],[1,1,1]]
[[1,1,1],[1,1,1],[0,1,1]]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS TRICKY AND TOUGH.*************************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algo. is inspired by algo. mentioned in the discussions section of LeetCode.
// The link is: https://leetcode.com/problems/circular-array-loop/discuss/94148/Java-SlowFast-Pointer-Solution
// This algorithm iterates the array, forms two pointers, if they meet without begin single elem. loop, then we got the answer. If not we mark
// all the indices on path to null(not usable, as it doesn't lead to loop). Thus, we go to next index with non-zero value.
// This is do-able in O(n^2) complexity, but with O(n) time complexity wit O(1) space is pretty tricky.

class Solution {
public:
    
    int nextIndex(vector<int> v, int i){												// Reachable index from here.
        i+=v[i];
        if(i<0) i+=v.size();
        else if(i>v.size()-1)
            i%=v.size();
        return i;
    }
    
    bool circularArrayLoop(vector<int>& v) {
        
        for(int i=0;i<v.size();i++){
            if(v.size()==0 || v.size()<2) return false;
            if(v[i]==0) continue;
            
            int slow=i, fast=nextIndex(v,i);
            while(v[i]* v[fast]>0 && v[i]* v[nextIndex(v,fast)]>0){		// Until, we move in a single drn from beginning.
                if(slow==fast){
                    if(slow==nextIndex(v,fast)) break;
                    return true;
                }
                
                slow=nextIndex(v,slow);									//Updating the slow ptr.
                fast=nextIndex(v,nextIndex(v,fast));					// Updating the fast ptr.
            }
            
            slow=i;
            int drn=v[slow];
            while(drn* v[slow]>0){                                          // Making all values zero, until we reach first zero.
                int temp=nextIndex(v,slow);                                 //Iterating to the next index we can reach from curr. index.
                v[slow]=0;
                slow=temp;
            }
        }
        
        return false;
        
    }
};
