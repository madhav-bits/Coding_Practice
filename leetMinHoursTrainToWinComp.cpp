/*
*
//**************************************2383. Minimum Hours of Training to Win a Competition.*****************************************

https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


5
3
[1,4,3,2]
[2,6,3,1]
2
4
[1]
[3]
3
3
[4,7,6,5,8,6,5,3,4]
[4,6,5,2,5,6,3,1,3]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. We start with the given energy and exp and iterate through the array and at every stage we track how much energy, exp
// are lacking to pass this stage and we substract energy of that stage and add exp as we move to next index. We track the max. req. energy, exp and add these 
// values to return required training because the other instances where req. energy, exp are lesser are already covered if we gain max. req. energy, exp.







class Solution {
public:
    int minNumberOfHours(int currEnergy, int currExp, vector<int>& energy, vector<int>& exp) {
        int reqEnergy=0, reqExp=0;
        for(int i=0;i<energy.size();i++) {
            if(energy[i]-currEnergy+1>reqEnergy) reqEnergy=1+energy[i]-currEnergy;// Track max. required energy.
            if(exp[i]-currExp+1>reqExp) reqExp=1+exp[i]-currExp;			// Track max. req. exp.
            currEnergy-=energy[i];											// Dec. energy as we move to next opponent.
            currExp+=exp[i];												// Inc. exp as we move to next opponent.
        }
        return reqEnergy+reqExp;											// Returning total #required training hours.
    }
};
