/*
*
//**********************************************************880. Random Pick with Weight.***************************************************

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index 
in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has 
no arguments. Arguments are always wrapped with a list, even if there aren't any.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["Solution", "pickIndex", "pickIndex", "pickIndex", "pickIndex", "pickIndex", "pickIndex"]
[[[10,20,30]], [], [], [], [], [], []]


["Solution", "pickIndex", "pickIndex", "pickIndex", "pickIndex", "pickIndex", "pickIndex"]
[[[10]], [], [], [], [], [], []]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Uniform distribution based. Since, the random values has to be random proportionate to the weight of index. We calc. cumul.
// the sum of weights encountered on the path and store it each psn. As, we return random based on weights, if the rand generator returns value,
// which is between index[i] and index[i+1] or equal to index[i], return index[i+1].








class Solution {
public:
    vector<int>sum;															// Vector to store cumulative sum of weights.
    int count=0;															// Tracks Cumul. sum.
    Solution(vector<int> w) {
        for(auto num:w){
            count+=num;														// Calc. cumul. sum.
            sum.push_back(count);											// Pushing cumul. till then into vector.
        }   

		
		
		//sum.resize(w.size());												// If, we declare size of vector and assign values at indices,
        //int index=0;														// the execution is slightly faster. As, #inc. vector size is  dec.
        //for(auto num:w){
        //    count+=num;
        //    sum[index++]=count;
        //} 
		
    }
    
    int pickIndex() {
        int val=rand()%count;												// Random vlaue generator, generating values b/w [0,count-1].
        // cout<<"val: "<<val<<endl;
        // val=30;
        auto it=lower_bound(sum.begin(), sum.end(),val);					// Does binary search for first value>=target value.
        int ind=(it-sum.begin());											// Get the index of that value.
        if(sum[ind]==val) return ind+1;								// If val. matches return next index(As this rand value is incl. in next int.
        else return ind;													// Else, return ind.
        
		
		
        // int i=0,j=sum.size()-1;											// Another way to do binary search for first value>=rand value.
        // while(i<j){
        //     int mid=(i+j)/2;
        //     if(sum[mid]>=val) j=mid;
        //     else i=mid+1;
        // }
        // // cout<<"The result: "<<i<<endl;
        // if(sum[i]==val) return i+1;
        // else return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */