/*
*
//******************************************************2384. Largest Palindromic Number.******************************************************

https://leetcode.com/problems/largest-palindromic-number/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"444947137"
"00009"
"1111222233344455500000"
"00000"
"0000"
"22330"
"000011122"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration/observation based. We first count #occur of each of the chars in the num. We also track the largest char which occurred odd
// #times. We append all digits half times to res so that we will append it reverse version after forming complete string to form palindrome and using all 
// possible #occur. If res's first char is '0' that means it has leading zeroes so we reset res ="". Now, we append the largest char with odd #occur to res.
// Append the reverse version to res, if the res is still empty that means we had even #occur of all digits and '0' is the only digit occurred so we use 
// one instace of '0' and append it to res. We now return the final res.






class Solution {
public:
    string largestPalindromic(string num) {
        int occur[10], odd=-1;
        string res="";
        memset(occur, 0, sizeof(occur));
        for(char&ch:num) ++occur[ch-'0'];									// Tracking #occur of all digits.
        for(int i=0;i<10;i++) if(occur[i]%2==1) odd=i;						// Tracking largest digit with odd #occur.
        for(int i=9;i>=0;i--) res+=string(occur[i]/2, '0'+i);				// Appending chars in the first half of res.
        if(res[0]=='0') res="";												// If we have leading zeroes, we reset res to "".
        string temp=res;													// Temp store res so that we reverse it and append it to res to form palindrome.
        if(odd!=-1) res+=('0'+odd);											// If odd occur. digit exist, we append it.
        reverse(temp.begin(), temp.end());
        res+=temp;															// Append the reversed part to res.
        return (res.length()==0)?"0":res;									// Returning Largest palindrome number.
    }
};


