/*
*
//******************************************************540. Single Element in a Sorted Array.***********************************************

Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this 
ingle element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[1,1,2]
[3,3,7,7,10,11,11]
[2,2,3,3,4,4,5,6,6]
[2,3,3,4,4,5,5,6,6]
[3,3,4,4,5,6,6,6,6]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).	
// Space Complexity: O(1).	
// This algorithm is Binary Search Algorithm. We scan for middle elem. decide on whether it's equal to it's adjacent value, we decide whether
// to concentrate on left or right subarray.




class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int start=0, end=v.size()-1, mid;
        while(start<end){
            mid=(start+end)/2;										// Find the mid index.
            //cout<<"Start is: "<<start<<" and the end is: "<<end<<" and the mid is: "<<mid<<endl;
            if(mid==start+1){										// When, there are only three elem. in the subset.
                if(v[mid]==v[start]) start=end;						// If, first two elem. are equal, then third is the required result.
                break;												// Else, the first value is the req. answer, but not the mid one, as we are
            }														// maintaining the subarray to be odd length at all times.
            if(((mid-start)%2!=0 && v[mid]==v[mid-1]) || ((mid-start)%2==0 && v[mid]!=v[mid-1]))
                start=(mid%2==0)?mid:mid-1;//(mid%2==0)?mid:mid+1	// Making sure that, at each step, the subarray has only one single valued elem.
            
            else
                end=(mid%2==0)?mid:mid+1;							// mid+1 here mid-1 above, to make sure that no elem. is missed out.
        }
        //out<<"Outside the while: Start is: "<<start<<" and the end is: "<<end<<endl;
        return v[start];    										// Returning the single occurance value.
    }
};