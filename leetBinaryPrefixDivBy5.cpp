/*
*
//******************************************************1018. Binary Prefix Divisible By 5.******************************************************

https://leetcode.com/problems/binary-prefix-divisible-by-5/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[0,1,1]
[1,1,1]
[0,1,1,0,1,1,0,1,0,1,0,1,1]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Modulo Arithmatic based. Here, as the length of the array is huge, we can't store the num rep of prefix indices. As we are trying to find
// whether the num rep is divisible by 5, we make use of Modulo arithmatic and only track the rep%5 and keep appending later indices to it, it works because 
// multiplying to a multiple of 5 will also lead to a multiple of 5, so we can safely focus on rest of the value, if this rest of the value after making 
// addns in each index is divisible by 5 which is it's modulo=0, then we can say that total num rep is div by 5. We keep reducing updated num rep=rep%5 so that 
// we only track excess part after removing multiples of 5 in num rep. For every index, we add true if total rep is div by 5 else it would be false.






class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& v) {
        vector<bool>res(v.size(),false);
        int rem=0;
        for(int i=0;i<v.size();i++) {
            rem=rem*2+v[i];													// Adding curr. index to prefix num rep.
            rem%=5;															// Taking excess part not div by 5.
            if(rem==0) res[i]=true;											// If div by 5, we update res with true.
        }
        return res;															// Returning an arr indicating which of the prefixes are div by 5.
    }
};

