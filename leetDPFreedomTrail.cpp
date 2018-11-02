/*
*
//**************************************************************514. Freedom Trail.*******************************************************

In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the 
dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be 
spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one 
by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the 
center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of 
the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. 
After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
Example:


 
Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
Also, we need 1 more step for spelling.
So the final output is 4.
Note:

Length of both ring and key will be in range 1 to 100.
There are only lowercase letters in both strings and might be some duplcate characters in both strings.
It's guaranteed that string key could always be spelled by rotating the string ring.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"godding"
"gdggddooi"



"godding"
"godin"



// Time Complexity: O(n^3).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(m*n).	
// This algorithm is Dynamic Programming based. Here, as the combination leading to min. moves doesn't follow any sequence, we calc. min. dist
// moved to attain that combination. If we are setting char at index 'i', we calc. min. dist to all such chars in ring from prev. char's psns, 
// whose min. distances are calc. in prev. iteration. Thus, at the end. we iter. all possible psns of last char. in the ring and return the minm. 
// sum among them.


// dp[i][j] indicates min. steps to reach ith psn in key, which is at jth psn in ring. 
// We iter. over entire array of dp[key.length-1] and return minm. value among them.




class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>psns(26);
        int res=ring.length()*key.length();
        for(int i=0;i<ring.length();i++) 									// Storing psn of each char of key in ring.
            psns[ring[i]-'a'].push_back(i);
        
        int len=ring.length();
        vector<vector<int>>dp(key.length()+1,vector<int>(ring.length(),key.length()*ring.length()));// DP array.
        char prev=ring[0];													// First char.
        dp[0][0]=0;															// Init. dist.
        for(int i=0;i<key.length();i++){									// Iter. over keys.
            char ch=key[i];													// Curr. char.
            for(int j=0;j<psns[ch-'a'].size();j++){							// Iter. over psns of curr. char in ring.
                int a=psns[ch-'a'][j];
                for(int k=0;k<psns[prev-'a'].size();k++){					// Iter. over psns of prev. char in ring.
                    int b=psns[prev-'a'][k];
                    dp[i+1][a]=min(dp[i+1][a], dp[i][b]+min(abs(a-b), abs(len-abs(a-b))));// Extract min. dist to reach curr. index with curr. char.
                }
            }
            prev=key[i];													// Updating the prev. char var.
        }
        for(int j=0;j<ring.length();j++){									// Iter. over all ring psns for last char of key.
            res=min(res, dp[key.length()][j]);								// Extract min. dist.
        }
        return res+key.length();											// Return min. dist to obtain entire key.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^3).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based. This algo. is same as above one. As, curr. row values depend only on prev. row values, we can 
// work on only 2 rows using (%2) row values.









class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>>psns(26);
        int res=ring.length()*key.length();
        for(int i=0;i<ring.length();i++) 
            psns[ring[i]-'a'].push_back(i);
        
        int len=ring.length();
        vector<vector<int>>dp(2,vector<int>(ring.length(),key.length()*ring.length()));
        char prev=ring[0];
        dp[0][0]=0;
        for(int i=0;i<key.length();i++){
            char ch=key[i];
            for(int j=0;j<psns[ch-'a'].size();j++){
                int a=psns[ch-'a'][j];
                dp[(i+1)%2][a]=key.length()*ring.length();					// Setting the curr. using/updating index to default value.
                for(int k=0;k<psns[prev-'a'].size();k++){
                    int b=psns[prev-'a'][k];
                    dp[(i+1)%2][a]=min(dp[(i+1)%2][a], dp[i%2][b]+min(abs(a-b), abs(len-abs(a-b))));
                }
                if(i==key.length()-1) res=min(res, dp[(i+1)%2][a]);			// Extract min. dist. to reach last char. in key.
            }
            prev=key[i];
        }
        return res+key.length();											// Return the min. dist. to obtain all chars of key.
    }
};