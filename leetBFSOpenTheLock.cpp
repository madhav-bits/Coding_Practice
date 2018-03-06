/*
*
//************************************************************752. Open the Lock.*******************************************************

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels 
can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you 
will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the 
lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

["0201","0101","0102","1212","2002","2345","3000"]
"8202"





// Time Complexity: O(5^4).  
// Space Complexity: O(5^4).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(5^4).	
// Space Complexity: O(5^4).	
// This algorithm extracts all possible next moves and stores them in a queue(if a move is not visited atleast once) and update that strings' dist.
// The isntant, we don't have any strings in the queue(unvisited strings) or we have reached target string, we stop(As it will be the 
// shortest dist. to target).


class Solution {
public:
    
    vector<string> extrDig(string s){								// Extracts all possible next move-strings from curr. string.
        vector<string> v;
        string temp;
        for(int i=0;i<4;i++){
            temp=s;
            temp[i]=((temp[i]-'0'+1)%10)+'0';						// Move in forward drn.
            v.push_back(temp);
            temp[i]=((s[i]-'0'+9)%10)+'0';							// Move in backward drn.
            v.push_back(temp);
        }
        return v;
    }
    
    int openLock(vector<string>& v, string target) {
        if(target=="0000") return 0;
        //int result;
        unordered_map<string, int> m,n,visit;						// n stores dist,  m stores deadend strings.
        for(int i=0;i<v.size();i++) m[v[i]]=1;						// Storing the deadend strings in map.
        queue<string> q;											// Stores unvisited next move-strings.
        if(m["0000"]==1) return -1;									// If the start is deadend, we can't target.
        q.push("0000");
        n["0000"]=0;												// As, start dist. =0.
        visit["0000"]=1;											// Marking the starting string is visited.
        while(!q.empty()){
            vector<string> u;										// To, stores all possible next Moves.
            string curr=q.front();
            q.pop();
            u=extrDig(curr);										// Extracting next Moves.
            for(int i=0;i<u.size();i++){
                //cout<<"Curr. is: "<<curr<<" and the modified string is: "<<u[i]<<endl;
                if(m[u[i]]!=1 && visit[u[i]]==0){					// If a next move is not a deadend or it's not visited atleast once.
                    if(u[i]==target) return n[curr]+1;				// If target string found, directly returning dist.
                    n[u[i]]=n[curr]+1;								// It's dist. is updated.
                    //if(u[i]==target) return n[u[i]];
                    visit[u[i]]=1;									// Marking as visited.
                    q.push(u[i]);									// Pushing it into queue, as not visited(adj's moves are not extracted).
                }
            }
            
        }
        return -1;													// If, target not found, then return -1;
    }	
};
