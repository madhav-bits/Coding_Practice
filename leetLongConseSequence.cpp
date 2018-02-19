/*
*
//******************************************************128. Longest Consecutive Sequence.***********************************************

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[100,4,200,1,3,2]
[100,4,200,1,3,2, 2147483647, 2147483646, 2147483645, 2147483644, 2147483643]
[]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm uses HashMap to store all elements in array. Then, iterates through the map/array, starts counting from first number of a 
// sequence. Thus, it gets the max. length of consecutive sequence of numbers.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(m.empty()) return 0;								// If, there are no numbers. then return 0.
        unordered_map<int,int> m;
        for(auto num:nums)
            m[num]=1;
        int maxm=1,count=1;
        for(auto num:nums){									// Iterating through the map/array.
            count=1;
            if(m[num-1]!=1){                              	// Making, sure that this is the first num. of a consecutive sequence.
                int temp=num+1;
                while(m[temp]==1){
                    count++;
                    temp++;
                }
            }
            maxm=max(count,maxm);							// Saving the max. length of conse. sequence.
        }
        
        
        return maxm;										// Returning the max. length conse. sequence.
    }
};