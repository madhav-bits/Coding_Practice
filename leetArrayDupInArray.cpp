/*
*
//*****************************************************442. Find All Duplicates in an Array.**********************************************

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]


// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// In the while loop, it makes sure that "ith" index has value "i+1", unless duplicate is encountered. By the end of iteration all the elem.
// will be in corre. indices(value-1) except the duplicates. So, we identify  the duplicates and push them to vector.


//*************************************************************CLEVER AND TRICKY SOLUTION.*************************************************
//There is one more way,we negate the value at the index" value-1" as we iterate through the array. We check whether the value at index" value-1"
// is negative or not, prior to negating it. So, If we encounter a negative value, it means that the value is duplicate and push the value into
// the vector.


class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        vector<int> u;
        int i=0;
        while(i<v.size()){                                      //Makes sure that ith index elem. is "i-1".
            if(v[i]!=v[v[i]-1]) swap(v[i],v[v[i]-1] );
            else i++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=i+1)										// Pushing those values which are not in place.(Value-"i" at index"i-1").
                u.push_back(v[i]);
        }
        return u;
    }
};