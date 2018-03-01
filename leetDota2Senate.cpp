/*
*
//**************************************************************649. Dota2 Senate.*****************************************************

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the senate wants to make a decision about a change in the Dota2 game. The 
voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

Ban one senator's right: 
A senator can make another senator lose all his rights in this and all the following rounds.
Announce the victory: 
If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and make the decision 
about the change in the game.
Given a string representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party 
respectively. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of 
voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party, you need to predict which party will finally announce 
the victory and make the change in the Dota2 game. The output should be Radiant or Dire.

Example 1:
Input: "RD"
Output: "Radiant"
Explanation: The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights any more since his right has been banned. 
And in the round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
Example 2:
Input: "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in the round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in the round 1. 
And in the round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
Note:
The length of the given string will in the range [1, 10,000].





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"RDDDRDRR"


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This greedy algo. version is mentioned in the Discuss section of LeetCode.
// This algorithm This is obliviously a greedy algorithm problem. Each senate R must ban its next closest senate D who is from another 
//party, or else D will ban its next senate from R's party.

//The idea is to use two queues to save the index of each senate from R's and D's parties, respectively. During each round, we delete the 
//banned senate’s index; and plus the remainning senate’s index with n(the length of the input string senate), then move it to the back of its 
//respective queue.



class Solution {
public:
    string predictPartyVictory(string s) {
        queue<char>r,d;
        for(int i=0;i<s.length();i++)
            (s[i]=='R')?r.push(i):d.push(i);
        
        while(!r.empty() && !d.empty()){
            int r_index=r.front(), d_index=d.front();
            r.pop(); d.pop();
            (r_index<d_index)? r.push(r_index+s.length()):d.push(d_index+s.length());
        }
        
        return (r.size()>d.size())? "Radiant": "Dire";
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(1).	
// This algorithm is greedy, it eliminate the first non-eliminated senate in sequence from other party, such that there party member is the first
// remaining senate. Don't know, why this doesn't work out with the test cases. Though it had passed 72 cases of 80.




class Solution {
public:
    string predictPartyVictory(string s) {
        string t="";
        //int psn1=0, psn2=0;                 // psn 1 is for radiant, psn2 is for dire.
        while(1){
            int psn1=0, psn2=0; 
            while( psn1<s.length() && s[psn1]!='R') psn1++;							// No, "R" senates to delete.
            if(psn1==s.length()) return "Dire";
            
            while(psn2<s.length() && s[psn2]!='D') psn2++;							// No, "D" senates to delete.
            if(psn2==s.length()) return "Radiant";
            //cout<<"Psn1 is: "<<psn1<<" and psn2 is: "<<psn2<<endl;
            
            for(int i=0;i<s.length();i++){
                if(s[i]=='R'){
                    cout<<"R at index: "<<i<<" deleting D at: "<<psn2<<endl;
                    if(psn2<s.length()) s[psn2]='a';
                    else return "Radiant";
                    while(psn2<s.length() && s[psn2]!='D') psn2++;					// Searching for the next index of "D".
                }
                if(s[i]=='D'){
                    cout<<"D at index: "<<i<<" deleting R at: "<<psn1<<endl;
                    if(psn1<s.length()) s[psn1]='a';
                    else return "Dire";
                    while( psn1<s.length() && s[psn1]!='R') psn1++;					// Searching for the next index of "R".
                }
            }
        }
        //return t;
    }
};