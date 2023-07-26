/*
*
//********************************************2182. Construct String With Repeat Limit.********************************************

https://leetcode.com/problems/construct-string-with-repeat-limit/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"cczazcc"
3
"aababab"
2
"zzzzzzzzzzzb"
3
"abababaadlkjadabbasnbebjvndcnsdkjfaefjefasf"
3
"robnsdvpuxbapuqgopqvxdrchivlifeepy"
2



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Counting Sort based. As, we are using lowercase alphabets, we track #occur. of each alphabet in a array. We visit this array in rev. 
// order as we aim for lexically largest str. We skip all chars whose #occur. is zero, for a non-zero occur. greatest char, we append min(rep, occur[i]) chars
// to res. There will be cases where same char might have been earlier used adj. to even greater char, so maintain a var called diff to take care of this.
// We now also append 1 instance of next greatest char and we repeat same process again. If we are not able to find the greatest/next greatest char we stop 
// the process as we there aren't any chars/ or we can't ensure <=rep adj. chars of same type respectively.







class Solution {
public:
    string repeatLimitedString(string s, int rep) {
        vector<int>occur(26,0);
        for(char&ch:s) occur[ch-'a']++;										// Tracking #occur. of each char.
        string res="";
        int max1=25, max2=25;
        while(true) {
            while(max1>=0 && occur[max1]==0) max1--;						// Skipping chars with zero occur.
            if(max1<0) break;												// If no chars to use, we stop the process.
            int diff=(res.length()>0 && res.back()==('a'+max1))?-1:0;		// Use the current char while satisfying the repeat limit condition.
            int len=min(occur[max1], rep+diff);
            res+=string(len,'a'+max1);										// Appending curr. char to res.
            occur[max1]-=len;												// Dec. the #occur. of curr. char by #chars appended in this step to res.
            if(max2>=max1) max2=max1-1;										// Ensuring this is next greatest char. to above used one.
            while(max2>=0 && occur[max2]==0) max2--;						// Skipping chars with zero occur.
            if(max2<0) break;												// If no chars to use, we stop the process.
            res+=('a'+max2);												// Appending 1 char of next greatest char.
            occur[max2]--;
        }
        
        return res;															// Returning the lexically largest str satisfying the repeat limit condition.
    }
};

