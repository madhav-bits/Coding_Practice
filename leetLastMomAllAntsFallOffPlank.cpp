/*
*
//*******************************************1503. Last Moment Before All Ants Fall Out of a Plank.*******************************************


https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided with question.



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. Here, when two ants clash, they exchange their directions towards edges.This means total time taken by
// all ants to fall off is the initital largest dist. an ant has to travel. So, we iter. over two arrays and get the largest dist. and return it.






class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // sort(left.begin(), left.end());
        // sort(right.begin(), right.end());
        // return ((left.size()==0?0:1+*max(left.begin(), left.end())),(right.size()==0?0:n-*min(right.begin(), right.end())+1));
        int res=0;
        for(auto num:left)													// Iter. over array and getting maxm. dist. to travel.
            res=max(res, num);
        for(auto num:right)													// Iter. over array and getting maxm. dist. to travel.
            res=max(res, n-num);
        return res;															// Returning maxm. dist. to travel/time for all ants to fall off.
    }
};