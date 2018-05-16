/*
*
//**********************************************************283. Move Zeroes.***************************************************

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]


Note:

1) You must do this in-place without making a copy of the array.
2) Minimize the total number of operations.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,0,2,3,0,4,5,6,0,7]
[0,0,1,0,2,3,0,4,5,6,0,7,0]
[]
[0]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Two ptrs based question. We maintain one iterates through out the length of the string. Other ptr separates the non-zeros 
// and zeros. If we encounter a non-zero we swap the curr. value(indexed "i") with value at index "j" valued 0. In this way we iterete the entire
// array. Starting from "j", we have zeroes till end of array after the iteration.



class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int j=0;																	// Starting from "j" all values need to be "0"s till end.
        for(int i=0;i<v.size();i++){
            if(v[i]!=0){															// Swapping Non-zero "j" index val. with index-"i"'s value.
                swap(v[j], v[i]);
                j++;																// Inc. the "j"'s value.
            }
        }
        
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Two ptrs based question. We maintain one iterates through out the length of the string. Other ptr separates the non-zeros 
// and zeros. If we encounter a non-zero we assign at index-"j", the value at "i". In this way we iterete the entire array. Starting from "j", we 
// need have zeroes till end of array after the iteration. So, we contiue "j"'s iteration till end of string and assign all values to "0".

// This method avoids unnecessary assignments in swapping, wihich is used in Solution 1.







class Solution {
public:
    void moveZeroes(vector<int>& v) {
        if(v.size()==0) return ;
        int j=0;																		// Starting from "j" all values need to be "0"s till end.
        for(int i=0;i<v.size();i++){
            if(v[i]!=0){																// Assign value at "j" index to "i" index.
                v[j]=v[i];
                j++;
            }
        }
        
        for( ;j<v.size();j++)															// Assigning from index "j" till end, the value->"0".
            v[j]=0;
        
    }
};