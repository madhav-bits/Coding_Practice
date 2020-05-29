/*
*
//**********************************************1419. Minimum Number of Frogs Croaking.*******************************************

Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can 
croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given 
string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to 
finish a croak. If the given string is not a combination of valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".
Example 3:

Input: croakOfFrogs = "croakcrook"
Output: -1
Explanation: The given string is an invalid combination of "croak" from different frogs.
Example 4:

Input: croakOfFrogs = "croakcroa"
Output: -1
 

Constraints:

1 <= croakOfFrogs.length <= 10^5
All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"croakcroak"

"crcoakroak"

"croakcrook"

"croakcroa"


"crcroaoak"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is couting based. Here, we keep track of #occur. of each of the 5 chars. We use #c's to represent #active frogs simul.
// croaking. When we encounter 'k', we dec. the #c's and rest other char's count by 1. If a char is encountered, if it's revised cnt is
// more than it's prev. char in "croak", then the input is faulty, we return -1, we might also get incomplete croaks, so we use 
// occur[0]!=occur[4] to find all started croaks are finished properly or not, if not we return -1. When we encounter, 'c', we inc.
// the frogs cnt and try to update the max. #active frogs val. 

// IMPORTANT OBSERVATION:
// As, we want are trying to minimize #active frogs, once entire "croak" is encountered we dec. the cnt of frogs by 1. Same frog would
// be contributing to croaks from next index.






class Solution {
public:
    int minNumberOfFrogs(string s) {
        if(s.length()%5!=0) return -1;										// Base cases.
        int res=0;															// Tracks maxm #active frogs in an instant.
        vector<int>occur(5,0);												// Tracks faced chars and says whether input is valid.
        for(auto ch:s){														// Iter. over array.
            if(ch=='c'){													// First char.
                occur[0]++;													// Inc. the cnt indicating #active frogs.
                res=max(res, occur[0]);										// Updating maxm #active frogs in an instant val.
            }else if(ch=='r'){												// Second char.
                occur[1]++;													// Inc. the cnt.
                if(occur[1]>occur[0]) return -1;							// If it's cnt is >prev. char's, then input is invalid.
            }else if(ch=='o'){
                occur[2]++;
                if(occur[2]>occur[1]) return -1;
            }else if(ch=='a'){
                occur[3]++;
                if(occur[3]>occur[2]) return -1;
            }else if(ch=='k'){												// Last char.
                occur[4]++;
                if(occur[4]>occur[3]) return -1;					
                occur[4]--;occur[3]--;occur[2]--;occur[1]--;occur[0]--;		// Dec. the cnt of all prev. chars.
            }
        }	
        if(occur[0]!=occur[4]) return -1;									// If all opened croaks aren't closed, then input invalid.
        return res;															// Returning the maxm #active frogs in an instant val.
    }
};
