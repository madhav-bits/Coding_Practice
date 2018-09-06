/*
*
//******************************************************Repeat and Missing Number Array.***********************************************

https://www.interviewbit.com/problems/repeat-and-missing-number-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5 3 1 2 5 3




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT A ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. the array, the number that curr. index, we change that index's sign. Whatever may be the repeating 
// number(we try to change it the second time), thus we can get it directly, the missing number index also stays positive. As we have already got
// repeating number, we can directly identify the missing number by positive value in that index.

// *******************************************************This solution is a working one.****************************************************
// ***************************************This solution is useful, if we are allowed to change the given array.*************************************





vector<int> Solution::repeatedNumber(const vector<int> &v) {
    int sum=0;
    int rep=-1,miss=-1;
    for(int i=0;i<v.size();i++){											// Iter. the array.
        int ind=abs(v[i])-1;												// Get the curr. number.
        if(v[ind]<0){														// If the curr. index num is <0, then curr. num is repeating.
			rep=ind;														// Store the curr. num.
			v[ind]=-v[ind];													// Change the sign of that value.
        }
        v[ind]=-v[ind];														// Change the curr. number index's value's sign.
    }
	for(int i=0;i<v.size();i++){
		if(v[i]>0 && i!=rep) miss=i;										// If a num is >0 and index!=rep, then that index is missing num.
	}
		
    return vector<int>({rep,miss});											// Return the repeating number and missing number.
    
}









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS A ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sigma summation based. We get the Sigma of [1,n] numbers also we get Sigma of squares of [1,n] numbers. we calc. the sum of 
// given numbers, also their sum of their squres. We do obtained sum-targetsum for both categories. We divide the results to get the sum. of 
// squares of rep. and missing number. We use the obtained result (sum-targetSum) to get both these numbers.







vector<int> Solution::repeatedNumber(const vector<int> &v) {
    long long int sum=0;													// Stores sum of numbers.
    long long int sumSq=0;													// Stores sum of number's squares.
    long long int target=0;													// Stores target sum of numbers.
    long long int targetSq=0;												// Stores target sum of number's squares.
    int len=v.size();														// Stores len. of array.
    target=((long long int)len*(len+1))/2;									// Calc. tagret sum.
    targetSq=((long long int)len*(len+1)*(2*len+1))/6;						// Calc. target squares sum.
    for(auto num:v){
        sum+=(long long int)num;											// Calc. the sum of numbers.
        sumSq+=num*(long long int)num;										// Calc. the sum of numbers squares.
    }
    
    long long int sumDiff=sum-target;										// Get diff of numbers sum.
    long long int sqDiff= sumSq-targetSq;									// Get diff of numbers square sum.
    
    long long int comb=sqDiff/sumDiff;										// Get sum of two req. numbers.
    // cout<<"sumDiff: "<<sumDiff<<" and sqDif: "<<sqDiff<<endl;
    int dup=(int)(comb+sumDiff)/2;											// Get the rep. number.
    int mis=(int)comb-dup;													// Get the missing number.
    return vector<int>({dup,mis});											// Return the dup, missing number.
}
