/*
*
//**************************************************************55. Jump Game.******************************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

//These are the examples I had created, tweaked and worked on.
[]
[3,2,1,0,1,2,3]



// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// In a variable-count store the max. index to which we can jump at any point of time. If the curr. index is < count, then we can reach that index
// The instant the max. reachable index has crossed the v.size()-1, then we return true. If despite going through the entire iteration 
// v.size()-1 not reached, then we return false. This question doesn't seem to care about empty array(Either True or False is acceptable).




class Solution {
public:
    bool canJump(vector<int>& v) {
        if(v.size()==0) return true;
        int count=0;
        for(int i=0;i<v.size();i++){
            if(count>=i)											//This index is reachable.
                count=max(count,i+v[i]);							//Saving the max. index as the curr. index might dec. the max. reachable index.
            if(count>=v.size()-1)									// The instance where we found that v.size()-1 is reachable.
                return true;
        }
        return false;
    }
};




//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm is same as the above algorithm, but instead of checking for true instance, we check for false instance- the moment the curr.
// index is not reachable. If there is no fall instance after passing through the entire array, then we return true.





class Solution {
public:
    bool canJump(vector<int>& v) {
        if(v.size()==0) return true;
        int count=0;
        for(int i=0;i<v.size();i++){
            if(count<i)										//This index is not reachable.
                return false;
            count=max(count,i+v[i]);						//Saving the max. index as the curr. index might dec. the max. reachable index.
        }
        return true;
    }
};