/*
*
//**************************************************************Roman To Integer.*******************************************************


https://www.interviewbit.com/problems/roman-to-integer/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



I

V

IV

IX

XI


CCD



CCCCDCM


XL


XC




// Time Complexity: O(logn/log10).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log10).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iter. over given Roman numeral String. At each step, we add the curr. numeral to the final result, we 
// also check previous index for it's lower numeral. If found, we subtract twice the lower numeral from the sum. As, we have added that numeral 
// to the final result earlier.







int Solution::romanToInt(string s) {
    int res=0;
    unordered_map<char,int>m;												// Links Roman literals to it's corres. number.
    m['I']=1;m['V']=5;m['X']=10; m['L']=50; m['C']=100; m['D']=500; m['M']=1000;// Assigning values to Roman literals.
    for(int i=0;i<s.length();i++){											// Iter. over given string.
        res+=m[s[i]];														// Add curr. value to final result.
        if(i>0 && s[i-1]=='I' && (s[i]=='X' || s[i]=='V')) res+=-2;			// Checking prev. index for lower Roman literals.
        if(i>0 && s[i-1]=='X' && (s[i]=='L' || s[i]=='C')) res+=-20;		// If found, substract twice their value(As, they were prev. added).
        if(i>0 && s[i-1]=='C' && (s[i]=='D' || s[i]=='M')) res+=-200;
        // cout<<"res: "<<res<<endl;
    }
    return res;																// Return the final result.
}

