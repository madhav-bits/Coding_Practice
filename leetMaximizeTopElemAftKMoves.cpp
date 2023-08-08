/*
*
//*******************************************2202. Maximize the Topmost Element After K Moves.*********************************************

https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[5,2,2,4,0,6]
4
[2]
1
[1,2,3,4,5]
4
[1,2,3,4,5]
5
[5,5,3,4,3,6,7,6,5,3,2,3,4,6,6,4,3]
16
[5,5,3,4,3,6,7,6,5,3,2,3,4,6,6,4,3]
17
[5,5,3,4,3,6,7,6,5,3,2,3,4,6,6,4,3]
18
[7,5,4,3,6]
4
[7,5,4,3,6]
5
[7,5,4,3,8]
4
[7,5,4,3,8]
5
[7,5,4,3,8]
6
[7,5,4,3,8]
7
[3,2,1]
1
[0]
1000000000
[0]
3
[0]
1
[0]
2




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration and observation based. For #moves>=arr length, we have max. of first (k-1) elems has the topmost value after the process. If arr length is 1, 
// we have no elems in #moves is odd or v[0] if #moves is even, as we replace back the first index value into the array. If #moves<arr length, we return the max of first k-2
// values and arr[k]. All these observations are made after writing multiple examples and dry runs, as there is a clear pattern here, we can decipher it with few dry runs.







class Solution {
public:
    int maximumTop(vector<int>& v, int k) {
        if(k==0) return v[0];
        if(v.size()==1) return (k%2==0)?v[0]:-1;							// If #elems is 1, we return -1 for odd #moves, v[0] for even #moves.
        k=min(k, (int)v.size()+1);											// For all K>v.size(), we see same pattern here, so we use v.size()+1 for them.
        int maxm=INT_MIN;
        for(int i=0;i<k-1;i++) {											// We track greatest val in first 'k-2' indices.
            if(v[i]>maxm) maxm=v[i];
        }
        if(k>=v.size()) return maxm;										// We return the max. val for k>=v.size() as we place back the max. in this range into array.
        return max(maxm, v[k]);												// For k<v.size(), we return max of first 'k-2' indices and v[k].
    }
};

