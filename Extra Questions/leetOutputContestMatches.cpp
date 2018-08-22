/*
*
//********************************************************544. Output Contest Matches.***************************************************

During the NBA playoffs, we always arrange the rather strong team to play with the rather weak team, like make the rank 1 team play with the 
rank nth team, which is a good strategy to make the contest more interesting. Now, you're given n teams, you need to output their final contest 
matches in the form of a string.

The n teams are given in the form of positive integers from 1 to n, which represents their initial rank. (Rank 1 is the strongest team and Rank 
n is the weakest team.) We'll use parentheses('(', ')') and commas(',') to represent the contest team pairing - parentheses('(' , ')') for 
pairing and commas(',') for partition. During the pairing process in each round, you always need to follow the strategy of making the rather 
strong one pair with the rather weak one.

Example 1:
Input: 2
Output: (1,2)
Explanation: 
Initially, we have the team 1 and the team 2, placed like: 1,2.
Then we pair the team (1,2) together with '(', ')' and ',', which is the final answer.
Example 2:
Input: 4
Output: ((1,4),(2,3))
Explanation: 
In the first round, we pair the team 1 and 4, the team 2 and 3 together, as we need to make the strong team and weak team together.
And we got (1,4),(2,3).
In the second round, the winners of (1,4) and (2,3) need to play again to generate the final winner, so you need to add the paratheses outside 
them.
And we got the final answer ((1,4),(2,3)).
Example 3:
Input: 8
Output: (((1,8),(4,5)),((2,7),(3,6)))
Explanation: 
First round: (1,8),(2,7),(3,6),(4,5)
Second round: ((1,8),(4,5)),((2,7),(3,6))
Third round: (((1,8),(4,5)),((2,7),(3,6)))
Since the third round will generate the final winner, you need to output the answer (((1,8),(4,5)),((2,7),(3,6))).
Note:
The n is in range [2, 212].
We ensure that the input n can be converted into the form 2k, where k is a positive integer.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


4096

1024

4

2

64

2048



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Vector/Recursion based. The basic idea is to form all teams sequentially in an ordered map or vector. We iter. only half teams
// choose last team that still hasn't been chosen. This way, no. of teams get reduced to half for second round, We do this until there is only oene
// team.








class Solution {
public:
    string findContestMatch(int n) {
        map<int,string>m;													// Relates team num. and matches history.
        for(int i=1;i<=n;i++){												// Init. with the team number.
            m[i]=to_string(i);
        }
        while(m.size()>1){													// Until only one team is left.
            // cout<<"Size: "<<m.size()<<endl;
            auto it=m.begin();												// Init. the iterator.
            int len=m.size();												// Size of the map for this iter.
            for(int i=0;i<len/2;it++,i++){
                int num1=it->first;
                int num2=n+1-num1;											// Calc. the team from the other end(lower rank).
                m[num1]="("+m[num1]+","+m[num2]+")";						// Creating a match string.
                m.erase(num2);												// Removing the second team.
            }
            n/=2;															// Dec. the #teams in contention.
        }
        return m.begin()->second;											// Return match history of first/top ranked team.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Vector/Recursion based. The basic idea is to form all teams sequentially in an ordered map or vector. We iter. only half teams
// choose last team that still hasn't been chosen. This way, no. of teams get reduced to half for second round, We do this until there is only oene
// team.






class Solution {
public:
    string findContestMatch(int n) {
        vector<string>v(n+1);												// Creating a vector of size n+1.
        for(int i=1;i<=n;i++) v[i]=to_string(i);							// Init. the team string.
        
        while(n>1){															// Until only 1 team is left.
            for(int j=1;j<=n/2;j++){										// Iter. over half the teams.
                int num2=n+1-j;												// Choosing the second team.
                v[j]="("+v[j]+","+v[num2]+")";								// Forming the match string.
                //v[num2]='.';											
            }
            n/=2;															// Dec. the count of #teams in contention.
        }
        return v[1];														// Return match history of first/top ranked team.
    }
};