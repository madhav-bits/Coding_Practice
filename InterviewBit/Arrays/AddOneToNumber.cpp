/*
*
//***************************************************************Add One To Number.*******************************************************

https://www.interviewbit.com/problems/add-one-to-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,0,1]

[9,9,9]


[0,9,9,9]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is linear time based. We start from the end, we calc. the carry and pass it to the next digit, if at the end we have 1 as carry,
// we create new node assign it the value-1. We also remove the zeroes in front of Most Significant digit.






vector<int> Solution::plusOne(vector<int> &v) {
    int carry=1;
    for(int i=v.size()-1;i>=0;i--){											// Performing the addn.
        int sum=carry+v[i];
        v[i]=sum%10;
        carry=sum/10;
    }
    vector<int>res;															// Final result array.
    if(carry==1){ 															// If we have a carry.
        res=vector<int>(v.size()+1);										// Init. a new vector.
        res[0]=carry;														// Assigning the carry value at zero index.
        for(int i=1;i<res.size();i++)										// Assigning the else values at indices starting from 1.
            res[i]=v[i-1];
    }
    else res=v;																// If no valid carry, just copy the modified vector.
    int ind=0;
    while(res[ind]==0) ind++;												// Finding the index of first significant bit.
    return vector<int>(res.begin()+ind,res.end());							// Returning the result after removing the leading zeroes.
}
