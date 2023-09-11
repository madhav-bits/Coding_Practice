/*
*
//***************************************************2390. Removing Stars From a String.***************************************************

https://leetcode.com/problems/removing-stars-from-a-string/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"leet**cod*e"
"erase*****"
"gnngab**cvd****laf**kljbaj**lbjklajl**"




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Stack based. Here, when we say we remove closest non-star char for every star in string. There are two cases one is that we have stars 
// to  it's mmediate left indices of a star(a series of stars consec.), here all these stars affect first non-star to left and irrespective of in which order
// we use stars to remove chars the #chars removed would be = first (len of *s series) non-star chars to left, so we can safely treat the stars in sequence
// for clarity. If stars from a seq are separated by another seq. of stars where the non-star chars in middle are less, then stars overflow to it's left side
// series of chars and these become an updated larger length series of stars and they can affect their length numbered immedi. left non-stars, irrespective 
// of the order of +stars. 
// We use res to track non-stars and we pop chars from it as we encounter stars and return the final version of res. 







class Solution {
public:
    string removeStars(string s) {
        string res="";
        for(char&ch:s) {
            if(ch!='*') res+=ch;											// Adding non-star chars to res.
            else res.pop_back();											// Popping chars from res as we encounter stars.
        }
        return res;															// Returning the final state of res.
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is same as the above one, instead of using a res string, we use an index 'i' on given string to track chars in final version and move back 
// the index as we encounter stars. If we are at 'i' it means that we have first 'i' chars in res. We return final version of res.









class Solution {
public:
    string removeStars(string s) {
        int i=0;
        for(char&ch:s) {
            if(ch!='*') s[i++]=ch;											// Adding chars to res.
            else i--;														// Remving chars from res.
        }
        return s.substr(0,i);												// Returning the final version of res.
    }
};


