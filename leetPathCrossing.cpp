/*
*
//*********************************************************1496. Path Crossing.*********************************************************

https://leetcode.com/problems/path-crossing/description/


Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You 
start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False 
otherwise.

 

Example 1:

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.


Example 2:

Input: path = "NESWW"
Output: true
Explanation: Notice that the path visits the origin twice.
 

Constraints:

1 <= path.length <= 10^4
path will only consist of characters in {'N', 'S', 'E', 'W}


*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked on examples provided with the question.



// Time Complexity: O(n).
// Space Complexity: O(n).													// n- leng. of the string.

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).													// n- leng. of the string.	
// This algorithm is HashMap based. Here, we store all previously visited psns in hashmap, where we convert psns to string and store it in map.
// We can convert x,y into int rep. by 10001*x+y, we use 10001 as there 10000 possible values for x, y making it 10001 base. We iter. over
// given string of movements, acc. to chars, we change x,y values. We check if curr. rep is already present in map, if it is we are revisiting
// already visited psn, we return false. If not we insert curr. psn rep into map. If we don't find any prev. visited psns until last, we return
// true.








class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        // unordered_set<int>st;
        // st.insert(10001*x+y);											// Shows how int. rep. for curr. psn. can be created.
        unordered_set<string>st;											// Stores string reps. of all visited psns.
        st.insert(to_string(x)+"#"+to_string(y));							// Storing string rep. for (0,0).
        for(auto ch: path){													// Iter. over string.
            if(ch=='E') x++;												// Changing x, y values accordingly.
            else if(ch=='W') x--;
            else if( ch=='N') y++;
            else y--;
            // int temp=10001*x+y;											// Creating int. rep. for curr. psn.
            string temp=to_string(x)+"#"+to_string(y);						// Forming string rep. for curr. psn.
            if(st.count(temp)==1) return true;								// If this rep. is already present, we are revisiting psn.
            st.insert(temp);												// Storing curr. psn rep. in map.
        }
        return false;														// No revisiting observed, we return false.
    }
};