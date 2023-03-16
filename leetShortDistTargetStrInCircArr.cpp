/*
*
//******************************************************2515. Shortest Distance to Target String in a Circular Array.***********************************************

https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["hello","i","am","leetcode","hello"]
"hello"
1
["a","b","leetcode"]
"leetcode"
0
["i","eat","leetcode"]
"ate"
0
["b","a","c","d","f","e","a","s","t","a","e","e"]
"a"
3
["b","af","c","d","f","e","e","s","t","a","e","a"]
"a"
3
["b","af","a","d","f","e","e","s","t","ag","e","ag"]
"a"
9



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate in both directions and return the one with smallest distance.






class Solution {
public:
    int closetTarget(vector<string>& words, string target, int start) {
        if(words[start]==target) return 0;
		
		// This is another/ slightly 
        // int forward=-1, lastIndex=-1;
        // for(int i=start;i<=words.size();i++) {
        //     if(words[i]==target) {
        //         if(forward==-1) forward=i-start;
        //         lastIndex=i;
        //     }
        // }
        // int back=-1, firstIndex=-1;
        // for(int i=start;i>=0;i--) {
        //     if(words[i]==target) {
        //         if(back==-1) back=start-i;
        //         firstIndex=i;
        //     }
        // }
        // if(firstIndex==-1 && lastIndex==-1) return -1;
        // if(forward==-1) forward=words.size()-start+firstIndex;
        // if(back==-1) back=start+words.size()-lastIndex;
        // return min(forward, back);
		
		
        
        int len=words.size(), front=-1, back=-1;
        for(int i=start;i<start+len;i++) {																// Searching for target string on the right side.
            if(words[i%len]==target && front==-1) front=i-start;
        }
        
        for(int i=start;i>start-len;i--) {																// Searching for target string on the left side.
            if(words[(i+len)%len]==target && back==-1) back=start-i;
        }
        if(front==-1 && back==-1) return -1;															// If target string not found, return -1
        return min(front, back);																		// Return the minm. dist to target string among two sides.
    }
};


