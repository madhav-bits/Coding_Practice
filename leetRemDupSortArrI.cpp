/*
*
//*********************************************************26. Remove Duplicates from Sorted Array.************************************************

Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1,1,2,2,3,4,5,6,6,7,8,9,10,10]
[]
[1]


// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm iterates through the array, removes the duplicate values, as I thought we need to decrease the size of array(remove dupli. elem.)
// from the array.




class Solution {
public:
    int removeDuplicates(vector<int>& v) {
       if(v.size()==1) return 1;
       for(int i=1;i<v.size();i++){
           if(v[i]==v[i-1]){
               v.erase(v.begin()+i);
               i--;
           }
               
       }
        return v.size();
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm iterates through the array, maintains the count of single occuranes of all numbers. If the curr. value is not equal to the prev.
// recorded single occurance value, then this is the first occurance of that value, so the curr. value is stored. Thus, at the end of the 
// iteration, we will be having all the array's members- single record for a value in sequence. Which is observed in the final answer.



class Solution {
public:
    int removeDuplicates(vector<int>& v) {
       if(v.size()==0) return 0;
       //if(v.size()==1) return 1;
        int count=1;
        
       for(int i=1;i<v.size();i++){
           if(v[i]!=v[count-1]){
               v[count]=v[i];
                count++;
           }
               
       }
        return count;
    }
};