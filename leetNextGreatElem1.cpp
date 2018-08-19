/*
*
//************************************************************496. Next Greater Element I.*****************************************************

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for 
nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[4,1,2,3,6]
[1,3,4,2,8,9,6]



[1,3,5,2,4]
[5,4,3,2,1]




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Stack based, we first find the next closest greater num. to each num. in vector v using stack. We remove all nodes from 
// stack whose value is less than curr. value, we store this greater value in the smaller value's index in another array. We iterate the first
// array, look for that value's psn in second array using map, which gives index, we can get it's next closest greater value from the greater
// array, we extract the gretaer value for each value in first vector and push it into the final result vector.








class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& u, vector<int>& v) {
        stack<int>st;														// Useful in obtaining closest next greater value.
        vector<int>great(v.size(),-1);										// Stores indices of next greater value.
		unordered_map<int,int>m;											// Relates nums in second array to their indices.
        for(int i=0;i<v.size();i++){										// Iter. second array.
			m[v[i]]=i;
            while(!st.empty() && st.top()<v[i]){							// If the prev. values are less than curr. val.
                great[st.top()]=i;											// Store curr. index in prev. index in gretater array.
                st.pop();
            }
            st.push(i);														// Push curr. index into stack.
        }
        // for(auto num:great) cout<<num<<" "<<endl;
        vector<int>res;														// Final result vector.
        //for(int i=0;i<v.size();i++)m[v[i]]=i;
        for(int i=0;i<u.size();i++){										// Iter. the first array.
            int ind=great[m[u[i]]];											// Extracting the index of next greater value to curr. val in first arr.
            if(ind==-1)														// If index is -1, we push -1 directly into final result vector.
                res.push_back(ind);
            else res.push_back(v[ind]);										// Push the next greater value to final result vector.
        }
        return res;															// Returning the final result vector.
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algo. is same as previous one, except it stores directly in map, the next greater val. to diff. nums if they exist. Thus, when we iter.
// first array, we check for nums in map, if exist, then next greater val. is the value corres. to this key(num). If not, the next greater 
// val. to that num hasn't been calculated, so we push -1 into final result vector.









class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& u, vector<int>& v) {
        stack<int>st;
        unordered_map<int,int>m;											// Stores next greater val.(if exist) for any num.
        vector<int>res;
        for(int i=0;i<v.size();i++){
            while(!st.empty() && st.top()<v[i]){
                m[st.top()]=v[i];											// If next greatet val. exist, pushing directly into map.
                st.pop();
            }
            st.push(v[i]);
        }
        
        for(int i=0;i<u.size();i++){
            if(m.count(u[i])==0) res.push_back(-1);							// If value is not in map, then push -1 into final result vector.
            else res.push_back(m[u[i]]);									// If val. is in map, then push it's value pair into final res. vector.
        }
        return res;															// Returning the final result vector.
		
    }
};