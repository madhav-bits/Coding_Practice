/*
*
//****************************************************************Min XOR value.***********************************************************

https://www.interviewbit.com/problems/min-xor-value/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4 29 18 21 24

5 4 2 34 24 58


// Time Complexity: O(nlogn).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. As, the nums with min. XOR lies next to each other if sorted. We sort the given numbers and find XOR
// between consecutive ints, return the minm. of them. 

// This problem can also be solved using TRIE, where we iterate over nums, for a num. we iterate through from MSB to LSB, as long as we find
// prev. nums with similar bits, we travel through Trie smoothly. If not prev. str exists with similar bits, we add the mismatch bit value
// to the final result, then travel in the mismatched bit path then iterate through bits of curr. num, by end we will get min. XOR involving 
// curr. num and prev. nums. Now, we insert this num. into the Trie. If curr. num is the answer when combined with some later num. we get the 
// answer when we traverse Trie with later num.
// If Trie is used, Time Complexity: O(n*32). Space Complexity: O(n*32).









int Solution::findMinXor(vector<int> &v) {
    int res=INT_MAX;														// Tracks the min. XOR value.
    sort(v.begin(), v.end());												// Sort the given num.
    int index=0;															// Tracks the curr. num we are calc. XOR for.
    while(index+1<v.size()){												// Until we have next num.
        int temp=v[index]^v[index+1];										// Calc. XOR value.
        if(temp<res) res=temp;												// Update the final result.
        index++;															// Moving the iterator forward.
    }
    return res;																// Returning the final result(Min. XOR value).
}
