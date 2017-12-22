/*

//********************************************************213. House Robber II.*******************************************************

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much 
attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob 
tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

//Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//Time Complexity: O(n).
// Space Complexity: O(1).
//As we have to not include First and Last elements at the same time, we will make two vectors (v.begin(), v.end()-1) && (v.begin()+1, v.end())-.
//-Two vectors one excludes the first and the other vector excludes the last one.
//Two algorithms used to solve the question.
class Solution {
public:
    int maxRob(vector<int> v){
        int prev2=0, prev1=0,res=0;
        for(int i=0;i<v.size();i++){
		res=max(prev2+v[i], prev1);				// We are evaluating two possiblilities of index "i-1" and "i-2".
            prev2=prev1;						// Saving the max. upto index "i-2".
            prev1=res;							// Saving the max. upto index "i-2".
        }
        return res;
    }
    
    int rob2(vector<int>& v) {
        int incl=0, excl=0;							//Max. Sum till any index if the current house is included/robbed or not.
        for(int i=0;i<v.size();i++){
            int temp=incl;							//Temporarily saved previous index inclusive value.
            incl=v[i]+excl;							// If the curr. index is included, then we add max. sum(if previous index is not included).
            excl=max(excl, temp);					// If the curr. index is excl., then the previous index might be included or not( So-
        }											//- calc. max of the both).
        return max(incl, excl);						//  We need to return the max. of either last elem. is included/excluded.
    }
    
    int rob(vector<int>& v) {
        if(v.size()==0)
            return 0;
        if(v.size()==1)
            return v[0];
        vector<int> u(v.begin(), v.end()-1);
        vector<int> w(v.begin()+1, v.end());
        int res1=rob2(u);							//Algorithm2 is called from here.
        int res2=rob2(w);							//Algorithm2 is called from here.
        return max(res1,res2);						//Returning the max. of the two sub cases.
    }
};