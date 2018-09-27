/*
*
//**************************************************************Highest Product.*******************************************************


https://www.interviewbit.com/problems/highest-product/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 0 -1 3 100 70 50


5 -2 -1 0 2 3


5 -3 -2 -1 2 3

5 -3 -2 -2 -1 3



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is Greedy based. We sort the given numbers. The largest product can be fist three, or it can be product of first two and the 
// last one, as the first two nums can be negative(their product might be larger than then product of second and third largest number). So, we
// compare the results of both these combinations/products and give out the largest result.








int Solution::maxp3(vector<int> &v) {
    if(v.size()<3) return -1;												// Filtering out unnecc cases.
    int len=v.size();														// Get length of given array.
    sort(v.begin(), v.end());												// Sorting the given array.
    int res=1;																// Init. the given array.
    res=v[len-1]*v[len-2]*v[len-3];											// Get the product of top three values.
    res=max(res, v[len-1]*v[0]*v[1]);										// Get the product of first two and largest value.
    return res;																// Return the largest triplet product.
}
