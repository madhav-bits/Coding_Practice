/*
*
//***********************************************************Max Product Subarray.***************************************************


https://www.interviewbit.com/problems/max-product-subarray/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



9 5 2 -3 1 -2 1 4 -3 2 

10 5 0 2 -3 1 -2 1 0 -3 2


1 0

2 0 0

2 0 1

2 1 0 



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. Here, the maxm. subarray product depends mainly on '0's and neg. values encountered. As, two 
// neg. values in the subarray makes pos. value. So, corner neg. value encount. will paly crucial role in case of odd neg. values in subarray. In
// that case, we have to consider one last neg./first neg. in the subarray. So, we calc. subarray product from both sides, at every index we 
// choose the largest of two and use that to update the maxm. subarray product of whole array.



// If 0 encountered, we start from 1 once again in these iterations.
// left[i] indicates product of first i elements.
// right[i] indicates product of last i elements.


int Solution::maxProduct(const vector<int> &v) {
    if(v.size()==0) return 0;												// Base case.
    long int prod=1;														// Tracks product of nums iterated.
    int maxm=INT_MIN;														// Tracks max. subarray product.
    int total=1;															// Tracks product of all numbers.
    vector<int>left(v.size()+2, 0), right(v.size()+2,0);					// Stores product of nums. till a index 'i' form left, right side.
    for(int i=0;i<v.size();i++){											// Iter. from left side.
        total*=v[i];														// Get product of all nums.
        prod*=v[i];															// Add curr. elem. to the subarray from left side's product.
        left[i+1]=prod;														// Save product of nums. till index 'i'.
        if(prod==0) prod=1;													// Restart calc. subarray product.
    }
    if(total>0) return total;												// If entire product is positive, return it.
    prod=1;																	// Setting to default value for next iter.
    for(int j=v.size()-1;j>=0;j--){											// Iter. from right side.
        prod*=v[j];															// Add curr. elem. to the subarray from right side's product.
        // cout<<"product: j+1: "<<j+1<<" and prod: "<<prod<<endl;
        right[j+1]=prod;
        if(prod==0) prod=1;
    }
    for(int i=0;i<=v.size();i++){
        // cout<<"i: "<<i<<" and left; "<<left[i]<<" and right; "<<right[i+1]<<endl;
        int temp=max(left[i], right[i+1]);									// Comparing the substrings from both sides ending at i, i+1 indices.
        maxm=max(maxm, temp);												// Updating the maxm. product subarray.
    }
    return maxm;															// Returning the maxm. product subarray.
}
