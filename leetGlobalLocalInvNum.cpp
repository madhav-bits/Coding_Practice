/*
*
//*****************************************************775. Global and Local Inversions.**********************************************

We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//********************************************************TRICKY ALGORITHM.************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
// This is tricky algorithm, I had almost cracked it. Bad luck, missed it out. Here the local and global inv. are same whenever an elem. at
// index "i" > elem. at index "i+1" only all elem. following it has to be greater than at "i". This is possible if a sorted array is tweaked
// by swapping any no. of pair of adjacent elem. only one. This leads to say the value of elem. at index "i" and has to be adjacent to index "i"
// so, abs(v[i]-i)<=1 for any index. If violated, then false is returned.


class Solution {
public:
    bool isIdealPermutation(vector<int>& v) {
        for(int i=0;i<v.size();i++){
            if(abs(v[i]-i)>1) return false;
        }
        return true;
    }
};





//************************************************************Solution 2:************************************************************
//********************************************************BRUTE FORCE ALGORITHM.************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).






class Solution {
public:
    bool isIdealPermutation(vector<int>& v) {
        int global=0, local=0;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(j>i && v[i]>v[j])
                    global++;
                if(j==i+1 && v[i]>v[j])
                    local++;
            }
        }
        //cout<<"Global is: "<<global<<endl;
        //cout<<"Local is: "<<local<<endl;
        if(global==local)
            return true;
        else 
            return false;
    }
};