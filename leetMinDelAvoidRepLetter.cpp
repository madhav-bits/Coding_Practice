/*
*
//***********************************1578. Minimum Deletion Cost to Avoid Repeating Letters.*******************************

https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.



Worked on test cases provided with the question.

"abaac"
[1,2,3,4,5]
"aabaa"
[1,2,3,4,1]
"abc"
[1,2,3]




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, since we need to pick a char from a rep. seq whose cost is maxm and delete the
// rest of the seq. So, we add all the cost in the first iter.. In the second iter. we pick the maxm. cost per seq., del
// them from the initial total and return the total.








class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int res=0, maxm=v[0];
        for(auto cost:v) res+=cost;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]){
                res-=maxm;
                maxm=v[i];
            }else maxm=max(maxm, v[i]);
            
        }
        res-=maxm;
        return res;
    }
};