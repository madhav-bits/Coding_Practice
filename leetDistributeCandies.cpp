/*
*
//**********************************************************575. Distribute Candies.***************************************************

Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one 
candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number 
of kinds of candies the sister could gain.
Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[1,1,2,2,3,4]
[1,1,2,2,3,3]
[1,1,2,2,2,2]



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is HashMap based. We count types of chocolates available. If the types are < #chocolates/2, then we can give all types of choc.
// to sister, if types>#chocolates/2, then we can give #choc./2 types of choc. to sister.








class Solution {
public:
    int distributeCandies(vector<int>& v) {
        int res;
        unordered_map<int, int>m;													// Stores types of choc. and their count. 
        for(auto num:v) m[num]++;
        int types=m.size();															// #types of chocolates.
        // cout<<"Types: "<<types<<" and num: "<<v.size()/2<<endl;
        if(types<=v.size()/2) return types;											// Return #types of choc. if types, #choc./2.
        else return v.size()/2;														// Return #choc./2, if types>#choc./2.
    }
};