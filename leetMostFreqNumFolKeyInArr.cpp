/*
*
//****************************************2190. Most Frequent Number Following Key In an Array.****************************************

https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,100,200,1,100]
1
[2,2,2,2,3]
2
[4,6,7,8,4,3,2,3,5,7,8,8,9,9,7,5,4,2,2,5,6,7,5,9,8,5,4]
5



// Time Complexity: O(n).													// n-length of the array, m- range of nums in the array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the array, m- range of nums in the array.
// Space Complexity: O(m).	
// This algorithm is iteration based. Here, #occur of target is defined as #occur besides key number in the array. We have to return target value with most 
// occur. We iterate the array and keep track of the #occur of each of the target values and their occur and track the target with max. #occur and return it.







class Solution {
public:
    int mostFrequent(vector<int>& v, int key) {
        int occur[1001], res=0;
        memset(occur, 0, sizeof(occur));
        for(int i=0;i<v.size()-1;i++) {										// Iter. the array.
            if(v[i]==key) {													// Key value found.
                if(++occur[v[i+1]]>occur[res]) res=v[i+1];					// Inc. the #occur of target and track max. occur target.
            }
        }
        // cout<<"res occur: "<<occur[res]<<endl;
        return res;															// Returning max. occur target value.
    }
};

