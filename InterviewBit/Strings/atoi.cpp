/*
*
//******************************************************************Atoi.**********************************************************

https://www.interviewbit.com/problems/atoi/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



  -10 12
  
  
  
-a  -10 12



-2147483647  



-54332872018247709407 4 54






// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we try to gather the first encountered valid num. prior to encountering nums, We try to get their 
// sign, if we encounter any invalid char by then, then we return zero. Once,we encounter number, we start accumulating values, now if we encounter
// any invalid chars including +/- signs, then we return the value. While accumulating values, if the accumulated value is >INT_MAX, with sign=1,
// we return INT_MAX. If value >INT_MAX+1, with sign=-1, we return INT_MIN. If we iterate till end of string accumulating values, then we return 
// value outside the iterating loop.








int Solution::atoi(const string s) {
    int sign=1;																// Tracks sign of digits encountered.
    bool start=false;														// Tracks whether we encountered digits or not.
    long long int res=0;													// Tracks value accumulated.
    for(int i=0;i<s.length();i++){
        // cout<<"index: "<<i<<endl;
        if(start==false && s[i]=='-') sign=-1;								// If signs encountered prior encountering digits, take their value.
        else if(start==false && s[i]=='+') sign=1;							
        else if(s[i]<'0' || s[i]>'9') break;								// If invalid chars encount. prior encount. digits, then return value.
        if(start==false && s[i]>='0' && s[i]<='9') start=true;				// If first digit encount. mark as digit encountered.
        if(s[i]>='0' && s[i]<='9') res=res*10+(s[i]-'0');					// If digits encountered, accum. value.
        if(sign==1 && res>=INT_MAX) return INT_MAX;							// If accumulated value overflown, return INT_MAX for +ve values.
        if(sign==-1 && res>=INT_MAX+(long long int)1) return INT_MIN;		// If accumulated value overflown, return INT_MIN for -ve values.
        // cout<<"start: "<<start<<endl;
    }
    return sign*res;														// Return the accumulated value.
}
