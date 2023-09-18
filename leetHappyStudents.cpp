/*
*
//******************************************************2860. Happy Students.******************************************************

https://leetcode.com/problems/happy-students/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1]
[6,0,3,3,6,7,2,7]
[15,17,4,5,12,2,5,4,17,18,8,15,3,4,1,2,1,3,7,8,9,8,6,3,2,3,3,4,4]
[1,1,2,2,2,2,3,4,4,4,3,3,3,4,4,5,5]



// Time Complexity: O(n).													// n-length of the given array.
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n-length of the given array.
// Space Complexity: O(n).	
// This algorithm is Counting Sort based. We need the given nums sorted for smoother processing, we use counting sort as the range of nums is small. We iter. 
// over occur. array and ignore indices where occur=0, we count #nums covered until now and the last num where #occur!=0, when we are at 'i', we check if 
// #nums covered>prev. val and #nums covered<i, if yes we increase the res. We can ignore the case where same val is present in selected and unselected parts, 
// as we won't meet the conditions in this case, so we iter. to next num in the array. We inc. res by 1 after the iter as the case where all nums are 
// selected would also meet the condition as #nums selected(v.size())> max. num in array. We return res now.




// We used same approach and solve the question with sorted array too.





class Solution {
public:
    int countWays(vector<int>& v) {
        // sort(v.begin(), v.end());
        // int res=(v[0]>0);
        // for(int i=0;i+1<v.size();i++) {
        //     if(i+1>v[i] && i+1<v[i+1]) res++;
        // }
        // if(v.size()>v.back()) res++;
        // return res;
        
        int res=0, nums=0, prev=-1, occur[v.size()];
        memset(occur, 0, sizeof(occur));
        for(int&num:v) occur[num]++;										// Track #occur. of each num.
        for(int i=0;i<v.size();i++) {										// Iter. over the array.
            if(occur[i]==0) continue;
            if(nums>prev && nums<i) res++;									// If condition is met(nums>=i aren't selected now), we inc. res.
            prev=i;															// Track max. num in selected part.
            nums+=occur[i];													// Track #nums in selected part.
        }
        res++;																// Inc. res for the case where all nums are selected.
        return res;															// Returning #ways to select group where everyone is happy.
    }
};

