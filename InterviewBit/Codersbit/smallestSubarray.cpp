/*
*
//**************************************************************Smallest Subarray.*******************************************************

https://www.interviewbit.com/problems/smallest-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



3 3 1 4
8



4 3 1 6 2
14



5 1 2 3 4 5
7




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, we iter. over array and include the indices into window, after every inclusion, we check whether
// the sum of elements in window is>=target, then we pop out elements from the back, until the sum>=target, at every step of removal, we update
// the min. length of window satisfying cdn var. At the end of iteration, we return the result var.










int Solution::solve(vector<int> &v, int target) {
    long int sum=0;															// Tracks sum of elements in the window.
    int start=0, close=0;													// Tracks start and end of window.
    sum=v[0];																// Starting from index '0'.
    int len=v.size()+1;														// Final result var.(Smallest window size with sum>=target).
    for(int i=1;i<v.size();i++){											// Iter. over all indices in array.
        sum+=v[i];															// Including curr. index in window.
        close=i;															// Updating the window close index.
        while(sum>=target){													// If window sum>=target.
            len=min(len,close-start+1);										// Update the final result var.
            sum-=v[start];													// Removing start index from window.
            start++;														// Updating start index value.
        }
    }
    if(len==v.size()+1) return -1;											// If no such window found, return -1.
    return len;																// Returning the smallest window size whose sum>=target.
}
