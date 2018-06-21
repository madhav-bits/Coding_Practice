/*
*
//**********************************************************163. Missing Ranges.***************************************************

Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,4,3,50,50,98]
0
99


[2147483647]
-2147483648
2147483647


[-2147483648,-2147483648,0,2147483647,2147483647]
-2147483648
2147483647



[]
-2147483648
2147483647


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS NOT LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step finds the dist. b/w curr and prev. index's values, we append last value into array. If we have
// only 1 elem. b/w curr. and prev. index's vaue, we push the value only, if not, we push the range symbole into the final result.


// This algo. works perfectly fine for all values except for those values which involve INT_MAX, INT_MIN, that could be worked around by using
// long instead, even that isn't working fine here. 




class Solution {
public:
    //string getStr(int prev, int curr){
    //    return (prev==curr)? to_string(prev): to_string(prev)+"->"+to_string(curr);
    //}
    vector<string> findMissingRanges(vector<int>& v, int lower, int upper) {
        int  prev=lower-1,curr;
        v.push_back(upper+1);												// Pushing the upper range into result vector.
        vector<string>res;													// Final result str.
        for(int i=0;i<v.size();i++){										// Iterating the array.
            int curr=v[i];
            // cout<<"prev: "<<prev+1<<" and curr: "<<curr<<endl;	
            if(curr>prev+1){												// If numbers exist b/w curr. and prev value.
                if(prev+1==curr-1) res.push_back(to_string(prev+1));		// IF only is b/w curr. and prev.
                else res.push_back(to_string(prev+1)+"->"+to_string(curr-1));// If >1 value exists b/w curr. and prev.
                //res.push_back(getStr(prev+1,curr-1));
            }
            prev=curr;														// Updating the curr. value.
        }
        // for(auto str: res)
        //     cout<<str<<" ";
        // cout<<endl;
        return res;															// Returning the final result str.
    }
};




