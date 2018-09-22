/*
*
//******************************************************************MAXSPPROD.**********************************************************


https://www.interviewbit.com/problems/maxspprod/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


7 2 5 3 1 7 9 11



[2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based. Here, we are supposed to get the closest greater value on both sides to each index. For this we do two iter.
// from both sides and track the greatest value on both sides and store their product in an array, we get the maxm. of those values and return 
// the mod of that value.
// At any moment stack's contents are those which haven't encountered greater value in the drn of iteration.

// Here, the only mistake I had done is calculating mod for the product prior to comparing the products for the maxm. value. Thus, I was 
// comparing the modulo values and extracing the greatest remainder instead of greatest product.







int Solution::maxSpecialProduct(vector<int> &v) {
    long long int maxm=0;													// Track the product of the indices values.
    int modu=1000000007;													
    stack<long long int>st;													// Useful in getting the greater value on left side of each index.
    vector<long long int>res(v.size(),0);
    for(int i=v.size()-1;i>=0;i--){                        					// Collecting 'l' values.
        while(!st.empty() && v[i]>v[st.top()]){						// Extract all indices for which curr. index has the closest greater value.
            res[st.top()]=i;												// Storing curr. index in all those indices.
            // cout<<"i: "<<st.top()<<" left: "<<i<<endl;
            st.pop();
        }
        st.push(i);															// Pushing curr. index to get it's left closest greater value's index.
    }
    stack<long long int>st2;												// Useful in getting the greater value on right side of each index.
    for(int i=0;i<v.size();i++){                        					// Collecting 'r' values.
        while(!st2.empty() && v[i]>v[st2.top()]){
            res[st2.top()]=(res[st2.top()]*i);								// Storing the product of indices of greater values on both sides.
            // cout<<"i: "<<st2.top()<<" right: "<<i<<endl;
            maxm=max(maxm,res[st2.top()]);									// Extracting the maxm of those products.
            st2.pop();
        }
        st2.push(i);
    }
    
    return (int)(maxm%modu);												// Returning the mod of the greatest product value.
}
