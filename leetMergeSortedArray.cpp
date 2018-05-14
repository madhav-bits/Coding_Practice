/*
*
//**********************************************************88. Merge Sorted Array.***************************************************

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,2,3,0,0,0]
3
[2,5,6]
3


// Time Complexity: O(m+n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m+n).
// Space Complexity: O(1).	
// This algorithm is iterations based, simple merging of sorted arrays. Since, space for complete memory is allocated in the firt array. We push
// elem. into first array from the back. If there are still remaining in the second array to pushed into the first array( All rem. elem.< smallest
// of first array), then push them into the first array in another while loop.



class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        int k=v1.size()-1;													// Updating index.
        while(m>0 && n>0){
            //cout<<"Working onk: "<<k<<endl;
            if(v2[n-1]>v1[m-1]){											// If second array elem. is greater, then push into first array.
                v1[k]=v2[n-1];
                n--;
            }
            else{															// If first array elem. is greater, then update index in first array.
                v1[k]=v1[m-1];
                m--;
            }
            k--;															// Changing the updatable index.
        }
        //cout<<"K is: "<<k<<endl;
        while(k>=0 && n>0){													// Pushing rem. elem. into first array.
            v1[k]=v2[n-1];
            n--;
            k--;
        }
    }
};