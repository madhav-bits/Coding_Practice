/*
*
//**************************************************************Next Permutation.*******************************************************

https://www.interviewbit.com/problems/next-permutation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6 1 1 2 6 5 3


7 1 1 2 3 5 6 3


9 1 1 2 3 5 6 3 2 1

10 1 1 2 3 5 6 3 2 1 4


3 1 3 2


6 3 9 9 9 2 2


7 3 9 9 9 2 2 1

// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is iteration/Sorting based. So, as to next greatest number, we have to work from the back, we iter. over last seq. of dec. order
// elements and sort them starting from index(i). If we get the entire given seq. as dec. order seq. then just sort it and return the seq. If not 
// we swap the closest value greater than value at index(i-1) and return the array.








void Solution::nextPermutation(vector<int> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ind=v.size()-1;														// We iter. from the back.
    while(ind-1>=0 && v[ind]<=v[ind-1]) ind--;								// We reach the first elem. of dec. seq.
    // cout<<"index: "<<ind<<endl;
    sort(v.begin()+ind,v.end());											// Sort the dec. array part.
	if(ind==0) return ;														// If entire array is sorted, return the array.
    int prevIndex=ind-1;													// Storing the ind-1.
    while(ind<v.size() && v[ind]<v[prevIndex]) ind++;						// Finding closest val>value at (ind-1) and swap it.
    swap(v[prevIndex], v[ind]);												// Swap the vlaues at ind-1 and above chosen index.
    return ;																// Return the array.
}
