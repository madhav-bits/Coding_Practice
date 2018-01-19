/*
*
//******************************************************238. Product of Array Except Self.**********************************************

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements 
of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space 
complexity analysis.)






// Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//***************************************************NEED TO FOLLOW UP THE SOLUTION.*************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
// The logic is that saving the product of elem. fromt the start and from the end in two seprate vectors and using when required to prod. excl
// a elem.by getting prod. of elem prior to it from front vector and prod. of elem .after it from the back vector and multi. it.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        vector<int> u;
        int len=v.size();
        vector<int> front(len+1,1), back(len+1,1),res(len,1);
        front[0]=1;back[0]=1;							// Initialize the base case to 1.
        for(int i=1;i<=len;i++){
            front[i]=v[i-1]*front[i-1];               	//Stroes product of elements upto index-1.
            back[i]=v[len-i]*back[i-1];           		//Stores product from back- back[i]= prod. of "i" elem. from the end tow. beginning.
        }
        
        for(int i=1;i<=len;i++){
            res[i-1]=front[i-1]*back[len-i];			//Calc. the product exclu. the current elem.
            //cout<<"For index: "<<(i-1)<<"The front is: "<<front[i]<<" and back is: "<<back[len-i]<<endl;
        }
        
        return res;										//Returning the vector containing the desired product.
    }
};