/*
*
//****************************************************************Rotated Array.*********************************************************

https://www.interviewbit.com/problems/rotated-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



6 7 0 1 2 3 6




10 4 6 7 7 9 9 0 1 3 4





// Time Complexity: O(logn).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn).
// Space Complexity: O(1).	
// This algorithm is Binary Search based. Here, we try to choose one of two halves. If left half is sorted and it's least value is > second half's
// right most value, it means the least value is in right half, except this any other scenario would point to left half containing least value. We
// continue this process, until there are elements left to be searched. At the end of iteration, we return the last index's value.








int Solution::findMin(const vector<int> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i=0, j=v.size()-1;													// Init. the iterator values.
    while(i<j){
        int mid=(i+j)/2;
        if(v[i]<=v[mid] && v[i]>v[j]) i=mid+1;								// If this part is sorted with least value is > tail value.
        else j=mid;															// Else, all cdns will direct to this left half of values.
    }
    return v[i];															// Return the least value.
}
