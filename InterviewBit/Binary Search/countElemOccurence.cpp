/*
*
//**************************************************************Count Element Occurence.*******************************************************

https://www.interviewbit.com/problems/count-element-occurence/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 5 7 7 8 8 10
8




6 5 7 7 8 8 10
11




// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we find the start and close indices of occurence of target value. After finding the start index, 
// if that index doesn't contain the target value, we return 0, else we calc. close index value, then we calc. the length of indices range with
// target value and return.







int Solution::findCount(const vector<int> &v, int target) {
    if(v.size()==0) return 0;												// Base case.
    int i=0, j=v.size()-1;													// Init. ptrs for binary search.
    while(i<j){																// Focuses on finding the start index of target value.
        int mid=(i+j)/2;
        if(v[mid]>=target) j=mid;											// If mid has >=target, we focus on left half.
        else i=mid+1;														// Else on right half.
    }
    if(v[i]!=target) return 0;												// If the start index doesn't have target value, return 0.
    int start=i;															// Temp. saving start index.							
    i=0;j=v.size()-1;														// Init. ptrs for binary search.
    while(i<j){																// Finding the close index index of target value.
        // cout<<"i: "<<i<<" and j: "<<j<<endl;
        int mid=(i+j)/2;											
        if(v[mid]>=target && v[mid+1]>target) j=mid;						// If mid value is >=target, if equals that index has last target value.
        else i=mid+1;														// Else focues on right half.
    }
    return (i-start+1);														// Returning the length of indices with target value.
}
