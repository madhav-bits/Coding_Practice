/*
*
//**************************************2086. Minimum Number of Food Buckets to Feed the Hamsters.*****************************************

https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"H..H"
".H.H."
".HHH."
"...H.H.H.H.."
"....H.HHHH.H.HH.H.H.H.H......"



// Time Complexity: O(n).  													// Solution 2 is relatively cleaner algorithm and easy to understand.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Iteration+Greedy based. The best possible position to place food is in middle of two hamsters separated by empty space. So, in the first 
// iter. we find such cases and fill those spaces and modify the hamsters to diff. char so that they would be ignored when deciding to place food in next iter.
// In second iter. we place food beside those hamsters which still aren't covered and modify to hamsters to diff. char. If in third itration, we find any 
// hamsters that means they can't be adjacent to food and we return -1 else we return res(#food buckets placed).







class Solution {
public:
    int minimumBuckets(string s) {
        int res=0;
        // In first iteration we will try to place food buckets b/w and adj. to two hamsters for best use.
        for(int i=1;i+1<s.length();i++) {
            if(s[i]=='.' && s[i-1]=='H' && s[i+1]=='H') {					// Placing food b/w two hamsters separated by 1 empty space.
                s[i-1]='@';													// Modifying hamsters so that they would be ignored in later iterations.
                s[i+1]='@';
                res++;
                i+=2;
            }
        }
        
        for(int i=0;i<s.length();i++) {
            if(s[i]=='.' && i+1<s.length() && s[i+1]=='H') s[++i]='@', res++;// Placing bucket if curr. hamster isn't covered yet.
            else if(s[i]=='.' && i>0 && s[i-1]=='H') {						// Placing bucket if curr. hamster isn't covered yet.
                s[i-1]='@';													// Modifying hamster so that it would be ignored in later iterations.
                res++;
            }
        }
        for(char&ch:s) if(ch=='H') return -1;								// If we find any uncovered hamster, we return -1.
        return res;															// Returing minm. #food buckets used to cover all hamsters.
    }
};









//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Iteration+Greedy based. Here, for every hamster we encounter in iter., we try to place it towards right adj. index so that it might cover
// 'i+2' index if there is a hamster present there, thus covering two hamsters with single food bucket. Else, we try to place food bucket in 'i-1' index to 
// cover curr. hamster, if there is no space to the left adj. index then we can't cover curr. hamster and we return -1. We return #food buckets used at the 
// end of iter.










class Solution {
public:
    int minimumBuckets(string s) {
        int res=0;
        for(int i=0;i<s.length();i++) {
            if(s[i]=='H') {													// For every hamster.
                if(i+1<s.length() && s[i+1]=='.') {							// We try to place food it's right to probably cover 'i+2' index's hamster if present
                    res++;
                    i+=2;													// We skip 'i+2' index as hamster in that index is covered if present.
                } else if(i>0 && s[i-1]=='.') {								// We cover curr. hamster by placing food in left adj. index.
                    res++;
                } else return -1;											// If there is no empty space on both sides, we return -1.
            }
        }
        return res;															// Returing minm. #food buckets used to cover all hamsters.
    }
};

