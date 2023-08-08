/*
*
//******************************************************2211. Count Collisions on a Road.******************************************************

https://leetcode.com/problems/count-collisions-on-a-road/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"RLRSLL"
"LLRR"
"RRRLLL"
"SSSRSLRSRLLLSRLSSSSLLLLRLSRSRLLRLSRL"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. 'L' chars only count if there is a 'R'/'S' char before it and preventing it form going to INT_MIN, similarly 'R' chars only count
// towards res if they have 'L'/'S' towards right preventing them from going to INT_MAX, we use prev. to track if there are any 'R'/'S' to it's left and we temp. track #'R's
// encountered without adding to res until we encounter an 'L'/'S'. 







class Solution {
public:
    int countCollisions(string s) {
        int res=0, temp=0;
        bool prev=false;													// Tracks if any 'R'/'S' had occurred.
        for(char&ch:s) {
            if(ch=='L') {													// If curr. char is 'L'.
                if(prev==true) res++;										// If there is any 'R'/'S' to it's left, we add curr. char to res.
                if(temp!=0) {												// If there are any prev. 'R's yet to be added to res, we add them now.
                    res+=temp;
                    temp=0;
                }
            } else if(ch=='R') {											// If curr. char is 'R'.
                temp++;														// We temp. track #'R's.
                prev=true;													// We mark either of 'R'/'S' had occurred.
            } else if(ch=='S') {											// If curr. char is 'S'.
                if(temp!=0) {												// If there are any prev. 'R's yet to be added to res, we add them now.
                    res+=temp;
                    temp=0;
                }
                prev=true;													// We mark either of 'R'/'S' had occurred.
            }
        }
        return res;															// Returing the total #collisions.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is observation based. We first iterate from the start and exclude all indices which goes to INT_MIN and dont' collide with any chars, we stop this iter. when
// we find a char which either stays there-'S' or goes to the right side. We similarly also exclude indices which goes to INT_MAX and dont' collide with any chars and stop iter.
// when we find chars going to left/staying there. Since two extremes are removed all remaining chars would collide with each other or stay there, since 'S' chars won't 
// contribute to collisions, we count #non-'S's and return the count.






class Solution {
public:
    int countCollisions(string s) {
        int res=0, temp=0;
        int i=0,j=s.length()-1;
        while(i<s.length() && s[i]=='L') i++;								// Excluding all chars going to INT_MIN.
        while(j>=0 && s[j]=='R') j--;										// Excluding all chars going to INT_MAX.
        for(int k=i;k<=j;k++) {												// Counting non-'S's in remaining indices as they contribute to collisions.
            if(s[k]!='S') res++;
        }
        return res;															// Returning the total #collisions.
    }
};

