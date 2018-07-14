/*
*
//************************************************************294. Flip Game II.*****************************************************

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend 
take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will 
be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true 
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"++++"


"++++--++++-+++-+++--"

"+++++"


"+++++---++++"








// Time Complexity: O(n!).  
// Space Complexity: O(n*n!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).	
// This algorithm is Backtracking/DFS based. Here, we check out for all possible moves at any instant, we make a move and pass the 
// updated string to the next player. If the next player is a winner in all the moves he can make, the current player is loser. If the next player
// doesn't have moves to make/ or his next player is winner for all the moves he can make,he is a loser, making the curr.player the winner.

// If the next player is a winner in one scenario,then we try to look for a other scenario, where the next player might lose, making the curr.
// player the winner.






class Solution {
public:
    
    bool findWinner(string &s){												// Find curr. player is winner or not?
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='+' && s[i+1]=='+'){
                // if(!findWinner(s.substr(0,i)+"--"+s.substr(i+2)))		// Passing arguments by values.
                //     return true;  
                s[i]='-'; s[i+1]='-';		
                if(!findWinner(s)){											// If the next player is loser in one case, then curr. is winner.
                    s[i]='+'; s[i+1]='+'; 									// Changing values to orig. values.
                    return true;    										// Returning curr. player as winner.
                } 
                s[i]='+'; s[i+1]='+';										// Changing values to orig. values.
            }
        }
        return false;														// Returning curr. player as loser.
    }
    
    bool canWin(string s) {
        if(s.length()<2) return false;										// If elem.<2, then first player can't make a move.
        return findWinner(s);												// Call fn. to find the winner.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^(n)).												//(<n!), as overlapping scenarios are covered by map, Not so sure.	
// Space Complexity: O(n*2^(n)).	
// This algorithm is HashMap and Backtracking/DFS based. Here, we check out for all possible moves at any instant, we make a move and pass the 
// updated string to the next player. If the next player is a winner in all the moves he can make, the current player is loser. If the next player
// doesn't have moves to make/ or his next player is winner for all the moves he can make,he is a loser, making the curr.player the winner.

// If the next player is a winner in one scenario,then we try to look for a other scenario, where the next player might lose, making the curr.
// player the winner.

// Here, we use map to store for a particular arrangement of str, is the curr. player winner or not? Whenever same scenario arises again, we 
// directly return the result from the map.




class Solution {
public:
    
    bool findWinner(string &s, unordered_map<string,bool>&m){
        if(m.count(s)==1) return m[s];										//If we already the result for curr. arrangement of str, then return it.
        for(int i=0;i<s.length()-1;i++){									// Making all possible moves.
            if(s[i]=='+' && s[i+1]=='+'){
                // if(!findWinner(s.substr(0,i)+"--"+s.substr(i+2)))		// Pasing arguments by value.
                //     return true;  
                s[i]='-'; s[i+1]='-';										//Changing str's values.
                if(!findWinner(s,m)){										// If next player is loser in one case, then curr. player is winner.
                    s[i]='+'; s[i+1]='+';
                    m[s]=true;												// Storing the curr. arrangement of str, leads to winner.
                    return true;    										// Return the curr. arrangement leads to winner.
                } 
                s[i]='+'; s[i+1]='+';										// Reverting to orig. values.
            }
        }
        m[s]=false;															// Storing the curr. arrangement of str, leads to loser.
        return false;														// Return the curr. arrangement leads to winner.
    }
    
    bool canWin(string s) {
        if(s.length()<2) return false;										// If #elem<2, then first player can't make move.
        unordered_map<string,bool>m;										// Stores result for diff arrangements of given str.
        return findWinner(s,m);												// Returning curr. player is winner or not?
    }
};
