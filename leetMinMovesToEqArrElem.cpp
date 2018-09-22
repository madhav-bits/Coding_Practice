/*
*
//******************************************************453. Minimum Moves to Equal Array Elements.***********************************************

Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is 
incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[2,20,5,10,23,1]


[2]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
//*****************************************************THIS IS A PRETTY GOOD QUESTION.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(1).	
// This algorithm is Sorting based. At any point, we target one elem. and inc. all values till it's next smallest numbers is equal to it. This
// way we iter. over all numbers and get total sum.








class Solution {
public:
    int minMoves(vector<int>& v) {
        int res=0, prev=0;
        sort(v.begin(), v.end());											// Sort the given array.
        for(int i=1;i<v.size();i++){
            int diff=v[i]-v[i-1];
            // cout<<"diff: "<<diff<<endl;
            // cout<<"The addn: "<<prev+diff<<endl;							// Adding prev. inc., as when equating to prev. small it's not inc.
            res+=(prev+diff);												// Adding the diff. and prev. inc. to the total sum.
            prev+=diff;														// Updating the prev. change.
        }
        return res;
    }
};











//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. If observed, we are basically increasing the least value at any instant and making the least value equal 
// to the largest value in the array. So, the result in diff b/w least and else values.









class Solution {
public:
    int minMoves(vector<int>& v) {
        int minm=v[0], res=0;												// Tracks Minm value, final result.
        for(int i=1;i<v.size();i++){
            minm=min(minm, v[i]);											// Calc. min value of the array.
        }
        for(auto num:v){
            res+=(num-minm);												// Calc. diff. to minm.
        }
        return res;															// Return the sum of differences.
    }
};

