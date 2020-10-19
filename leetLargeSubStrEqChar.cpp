/*
*
//***************************************1624. Largest Substring Between Two Equal Characters.******************************************

https://leetcode.com/problems/largest-substring-between-two-equal-characters/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"aa"
"abca"
"cbzxy"
"cabbac"
"xyabyxasdfasx"



// Time Complexity: O(n).  													// n- length of the array.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).													// n- length of the array.
// Space Complexity: O(1).	
// This algorithm is observation based. This question translates to maxm. dist. b/w similar chars. We use an array to store first
// occurance of each char and calc. dist. b/w curr. and first occur. of char and maximize the maxm. dist(result) var.








class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>occur(26,-1);
        int res=-1;
        for(int i=0;i<s.length();i++){
            if(occur[s[i]-'a']==-1) occur[s[i]-'a']=i;
            else{
                res=max(res, i-occur[s[i]-'a']-1);
            }
        }
        return res;
    }
};