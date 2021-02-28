/*
*
//**********************************************************1773. Count Items Matching a Rule.***************************************************

https://leetcode.com/problems/count-items-matching-a-rule/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]
"color"
"silver"
[["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]]
"type"
"phone"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We check the value in ruleKey and we increase the count of result whenever the corresponding value in each index of 
// items array matches ruleValue and we return the res value after iteration.








class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res=0;
        for(int i=0;i<items.size();i++){
            if(ruleKey=="type" && items[i][0]==ruleValue) res++;
            else if(ruleKey=="color" && items[i][1]==ruleValue) res++;
            else if(ruleKey=="name" && items[i][2]==ruleValue) res++;
        }
        return res;
    }
};