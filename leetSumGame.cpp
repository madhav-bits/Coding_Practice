/*
*
//************************************************************1927. Sum Game.************************************************************

https://leetcode.com/problems/sum-game/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"5023"
"25??"
"?3295???"
"???343??32??3?2?52?68?82"
"?3?32?"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Game Theory+ Greedy+ Greedy+ Observation based. We use few observations made here: '?'s on both sides of the half effectively cancel each other out 1:1 
// rendering them almost inaffective(last pair cancel indirectly and won't affect result, rest all pairs cancel with same value). So, we would be left with '?'s on one side. 
// Another observation is that if we have 2*k '?'s, the only sum which Bob can get out of this is 9*k, as every pair of these '?'s can be converted to 9=0+9=1+8...=9+0. 
// Another observation is that if we have odd #'?'s, Alice would get the last turn to choose a value, irrespective of how they fill earlier '?'s, by the time we reach last '?', 
// we only have at max 1 way to get total on both halves right, so Alice would choose any of the rest 8 vals and make them inequal.
// So, we calc. diff in sum of initial values in both halves also track rem. '?'s after some of the '?'s on each side cancel out. Now, we put together diff. in vals+contribution
// of '?'s and check if total!=0, that means left and right half have inequal totals, in which case we return true else we return false.





// This discussion forum link has good explanation on the observations mentioned above and also about the solution:
// Very detailed expalanation here: https://leetcode.com/problems/sum-game/discuss/1329069/Java-Greedy-O(n)-solution-with-detailed-explaination-covering-every-case
// https://leetcode.com/problems/sum-game/discuss/1328966/JavaC%2B%2BPython-Math-Problem-with-Explanation
// https://leetcode.com/problems/sum-game/discuss/1329380/One-liner
// https://leetcode.com/problems/sum-game/discuss/1328940/C%2B%2B-simple-solution-with-Explanation






class Solution {
public:
    bool sumGame(string s) {
        int sum=0, qsn=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='?') {
                qsn+=(i<s.length()/2)?1:-1;									// Tracking rem. '?'s after '?'s on both sides cancel out each other.
            } else sum+=(i<s.length()/2?1:-1)*(s[i]-'0');					// Tracking diff. of orig. vals in both halves.
        }
        if(qsn%2!=0) return true;											// If #'?'s is odd, we return true as Alice would get last chance to fill the '?'.
        return (sum+((qsn/2)*9))!=0;										// Now, checking if the intial diff+contribution of '?' gives inequal totals.
    }
};

