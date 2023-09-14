/*
*
//******************************************945. Minimum Increment to Make Array Unique.*******************************************

https://leetcode.com/problems/minimum-increment-to-make-array-unique/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.





// Solution 1 has faster runtime but higher Space Complexity.
// Time Complexity: O(n+m).													//n-#nums in the array, m-range of nums in the array.
// Space Complexity: O(m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n+m).													//n-#nums in the array, m-range of nums in the array.
// Space Complexity: O(m).	
// This algorithm is Map+Observation based. We iter. over array to and keep track #occur of each num in the array. Later, we iter. over the array and keep 
// track of extra numbers 'rem' which occurred multiple times and need to be increased to a greater uniq. value. We track rem and in extra iter. we push 
// all extra nums to curr. iter. 'i', if we are at 'i' and this num occurred occur[i] times, we do res+=rem and move all extra nums to 'i', since we already 
// have a num in this value we add duplicate vals of curr. num to rem: rem+=occur[i]-1 so that they can inc. to a greater uniq. value. If occur[i]==0,
// we do res+=rem and push all extra nums from 'i-1' to 'i', as there is no num here, we let one of the rem to be in this val 'i' and we track remaining 
// extra nums as rem-1 and we move to next value. In this way in every step of iter. we try to settle if any extra rem is present and add extra rem if 
// curr. num occurred multiple times and move to next num/value, if there are still extra nums left after the iter, we use (n)*(n+1)/2 to calc. rem. steps to 
// settle rem values in next rem indices.






class Solution {
public:
    int minIncrementForUnique(vector<int>& v) {
        int occur[100001];
        memset(occur, 0, sizeof(occur));
        for(int& num:v) occur[num]++;
        int res=0, rem=0;
        for(int i=0;i<=100000;i++) {
            res+=rem;														// Steps to inc. rem values from 'i-1' to 'i'.
            if(occur[i]!=0 ) rem+=occur[i]-1;								// If curr. val is present, add extras from curr. value.
            else if(rem) rem--;												// If 'i' is absent,we let one extra value settle here and track rem. extra values.
        }
        res+=(rem*(rem+1))/2;												// #steps to settle rem. extra values in the next 'rem' indices.
        return res;															// Returning min. #steps to make uniq. valued array.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting+Observation based. This approach is same as the above one but use the given array, here also we track extra nums as 'rem' and 
// we move extra nums to greater values in each step. When we are at v[i], our rem nums would be at v[i-1], so we calc. the empty number space b/w curr. and 
// prev. indices and try to settle an extra num if present. We calc. #steps needed for the extra nums present and track left over extra nums. If our 
// v[i]==v[i-1], it means our extra nums had already reached curr. value and since we already have a num in curr. value we add curr. num to extra nums and 
// move to next iter. If we still have extra nums after the iter., we use (n)*(n+1)/2 to calc. rem. steps to settle rem values in next rem indices. We return 
// total #steps at the end of iter.










class Solution {
public:
    int minIncrementForUnique(vector<int>& v) {
        int res=0, rem=0;
        sort(v.begin(), v.end());											// Sort the given array.
        for(int i=1;i<v.size();i++) {
            if(v[i]==v[i-1]) rem++;											// Inc. rem by 1 as curr. val is already present.
            else {
                int gap=v[i]-v[i-1]-1;										// Calc. extra space b/w curr. and prev. value.
                int fill=min(gap, rem);										// Find how many extra nums can we settle here.
                res+=(fill*(fill+1))/2;										// Use (n)*(n+1)/2 to get #steps needed.
                rem-=fill;													// Dec. rem by settled nums count.
                res+=(rem*(gap+1));											// Move rem. extra nums from prev. value to curr. value.
            }
        }
        res+=(rem*(rem+1))/2;												// #steps to settle rem. extra values in the next 'rem' indices.
        return res;															// Returning min. #steps to make uniq. valued array.
    }
};

