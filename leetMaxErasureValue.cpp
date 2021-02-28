/*
*
//*****************************************************1695. Maximum Erasure Value.***************************************************

https://leetcode.com/problems/maximum-erasure-value/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[4,2,4,5,6]
[5,2,1,2,5,2,1,2,5]
[4,7,8,43,7,4,8,49,6,4,3,7,6,45,32,6,7,33,8,86,5]
[10000]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. Here, we are trying to find a window with unique values and return the maxm. sum of those
// windows. So, we track the occurances(last occurance) of each possible num. in the array until curr. index and remove all indices
// to ensure that curr. index is unique in the window. At every index, we form the window and try to maximize the total of values in 
// the window and return the maxm. window total.








class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        vector<int>occur(10001,-1);											// Stores the last occur. of values in windows.
        int res=0, total=0, start=0;
        for(int i=0;i<v.size();i++){										// Iter. over array.
            total+=v[i];													// Adding curr. index into window.
            while(occur[v[i]]!=-1){											// Removing vals until curr. index's val is uniq in window.
                total-=v[start];											
                occur[v[start++]]=-1;										// Marking the val. as unvisited.
            }
            occur[v[i]]=i;													// Marking curr. index's val as visited.
            // cout<<"i: "<<i<<" and total: "<<total<<endl;
            res=max(res, total);											// Maximizing the window's total.
        }
        return res;															// Returning the maxm. of window's total.
    }
};