/*
*
//******************************************************1915. Number of Wonderful Substrings.******************************************************

https://leetcode.com/problems/number-of-wonderful-substrings/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"aba"
"aabb"
"he"
"jjaccddeeffabghacgaebadadf"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Bit Manipulation based. Here, as we are working with 10 chars. We can use integer to represent if each of the 10 chars had occurred 
// even/odd number of times. We update this rep as we iterate, when at index 'i': 'rep' indicates whether each of the chars had occurred even/odd until now.
// So, we add occur[rep] to res, as this indicates from the index of those past occurrances to curr. index all of the chars have occurred even #times. Now,
// we flip one bit at a time and add occur[rep^flipPsn] to res, as it indicates that from the index of those past occurrances to curr. index, one char had
// occurred odd #times, we do this at every index and return res at the end of iter. 







class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long int res=0;
        vector<int>occur(1024,0);											// Stores #occur. of each of the rep of nums.
        occur[0]=1;															// Empty array representative.
        int rep=0;															// Representative of the chars.
        for(char&ch:word) {
            rep^=(1<<(ch-'a'));												// Marking the curr. char has occurred, flipping cause it's occur change from even->odd and vice versa.
            res+=0ll+occur[rep];											// Adding #prev. occur. of rep, as it indicates that substr from then to 'i' has all even #chars per type. 
            int flipPsn=1;
            for(int i=0;i<10;i++) {											// Flipping one char at a time, indicate one char occurring odd #times.
                res+=0ll+occur[rep^flipPsn];								// Adding #prev. occur of modified rep to res.
                flipPsn<<=1;												// Moving the flipPsn to next char.
            }
            // cout<<bitset<10>(rep)<<endl;
            occur[rep]++;													// Inc. the #occur. of curr. rep.
        }
        return res;															// Returning total #substrs that satisfies the conditions.
    }
};

