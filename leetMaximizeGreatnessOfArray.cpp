/*
*
//******************************************************2592. Maximize Greatness of an Array.******************************************************

https://leetcode.com/problems/maximize-greatness-of-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,3,5,2,1,3,1]
[1,2,3,4]
[1,1,1,2,2,2,3,3,3,2,2,1,1,4,4,4,4,3,3,3,2,2,1,1,1,2,2,3,6,7,4,4,4,4,3,6,3,3]
[1,1,2,2,3,3,4,4,5]



// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Greedy based. We first sort the array, then iterate the array, at index 'i' where arr[i]>arr[i-1], we try to replace all possible prev. lesser values<arr[i-1] to satisfy
// the greatness requirement, as arr[i-1] values can't be greater than itself, we try to replace as many even smaller values as possible with all the occurances of arr[i-1] values and update the result 
// variable as per the number of replacements at this step, then add the remaining prev. lesser values count to #arr[i-1] values and store in req variable. Thus, we try to replace all prev. smaller 
// values with 'i-1'th index value whenever we have arr[i]>arr[i-1]. We return the res var at the end of iter.







class Solution {
public:
    int maximizeGreatness(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res=0;
        int req=0, temp=0;
        for(int i=0;i<=arr.size();i++) {
            if(i==0 || i==arr.size() || (i>0 && arr[i]>arr[i-1])) {										// We try to replace earlier values<arr[i-1] with arr[i-1]
                // cout<<"i: "<<i<<" and req: "<<req<<endl;
                res+=min(req, temp);																	// We try to replace as many earlier values(req) as possible with arr[i-1]
                req=(req>temp)?req-temp:0;																// Updating the req value as per replacements possible at this step.
                req+=temp;																				// Increasing the req value by temp(#arr[i-1] values)
                temp=1;																					// Resetting temp val to 1, to count curr. index.
            }else temp++;																				// Updating the #occurances of curr. value.
        }
        
        return res;																						// Returning the max possible replacements in the array.
    }
};

