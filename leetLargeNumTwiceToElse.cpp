/*
*
//**************************************************747. Largest Number At Least Twice of Others.******************************************

In a given integer array nums, there is always exactly one largest element.

Find whether the largest element in the array is at least twice as much as every other number in the array.

If it is, return the index of the largest element, otherwise return -1.

Example 1:
Input: nums = [3, 6, 1, 0]
Output: 1
Explanation: 6 is the largest integer, and for every other number in the array x,
6 is more than twice as big as x.  The index of value 6 is 1, so we return 1.
Example 2:
Input: nums = [1, 2, 3, 4]
Output: -1
Explanation: 4 isn't at least as big as twice the value of 3, so we return -1.
Note:
nums will have a length in the range [1, 50].
Every nums[i] will be an integer in the range [0, 99].





//Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//Time Complexity: O(n).
// Space Complexity: O(1).
//The logic is that we extract the two most largest elements in the array. If the second elem. doesn't satisfy the condition, then we have to 
//return -1, if it sastisfies condition then all the else(lesser val. elem to it) elements satisfy the condition. So ,we have to return the
// index of the largest value number.

class Solution {
public:
    int dominantIndex(vector<int>& v) {
        if(v.size()==1)										//If only one. elem. is present then it sastisfies the condition in the qsn.
            return 0;
        int index, large1, large2, len=v.size();
        if(v[0]>v[1]){										//Initializing the two most largest elements by using first two elements.
            index=0;
            large1=v[0]; large2=v[1];
        }
        else{
            index=1;
            large1=v[1]; large2=v[0];
        }
        
        for(int i=2;i<len;i++){
            if(v[i]>large1){								//If the encountered elem. is large than large1 then large1, large2 gets updated.
                large2=large1;
                large1=v[i];
                index=i;
            }
            else if(v[i]>large2){							//If the encountered elem. is large than large2, then only large2 gets updated.
                large2=v[i];
            }
        }
        if(large1>=2*large2)								// If 2*large2 is less than large1, then all elem. satisfy the conditon in qsn.
            return index;
        else												//If 2*large2 is (>=) than large1, then the conditon in qsn. is not satisfied.
            return -1;										// As condition not satisfied, so returning -1.
    }
};