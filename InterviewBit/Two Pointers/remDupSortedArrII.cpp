/*
*
//******************************************************Remove Duplicates from Sorted Array II.***********************************************

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


21 1 1 1 1 2 2 2 3 3 3 4 4 4 4 4 5 5 5 5 5 6 


12 1 1 1 2 2 2 3 3 3 4 4 4 

4 1 2 3 3



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Pointers and count based. We maintain two ptrs, one iter. over array and other maintains the index of numbers till which they 
// are following the given cdn. We iter. over array and maintain count of conse. same digits faced. When the count>2, we skip copying the digit
// to first index, else we copy the digit to first index and inc. it. If the curr. digit is diff. from prev. one, then renew count to 1, copy it
// to first index. This way, by the end of iter. we have all numbers following cdn till index-> first index1-1.








int Solution::removeDuplicates(vector<int> &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int index=0;															// First index, maintains vals following given cdn.
    int prev=-1, count=0;													// Stores prev. value and count of latest conse. digits.
    for(int i=0;i<v.size();i++){											// Second index iter. over array.
        if(v[i]==prev) count++;												// If curr. value is same as prev. inc. the count.
        else{																// If curr. is a new number.
            count=1;														// Update the count to 1.
            prev=v[i];														// Update the prev. value.
        }
        if(count>2) continue;												// If count>2, skip copying curr. value to first index.
        v[index]=v[i];														// Else, copy curr. value to first index.
        index++;															// Inc. the first index.
        
    }
    return index;															// Return the len. of digits array following given cdn.
}
