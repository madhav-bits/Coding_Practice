/*
*
//******************************************************************Fraction.*********************************************************


https://www.interviewbit.com/problems/fraction/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


-1999
220


1999
220



19
220



6153
990



0
-1


-2
1





// Time Complexity: O(logn/log10).  										// Both complexities depends on the divisor's properties.
// Space Complexity: O(logn/log10).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log10).											// Both complexities depends on the divisor's properties.
// Space Complexity: O(logn/log10).	
// This algorithm is division based. Here, we calculate remainder and pass it as dividend for next iteration. We also keep tracks of dividends we
// are facing as part of division. If, we encounter a prev. encountered, then there is recurring fraction, we stop iter. we insert '(' at it's 
// first occurance in the string, and append ')' at the end and return it. If we divide without any remainder, then return the obtained quotient.












string findRem(string res, long int rem, long int divi, unordered_map<long int,int>&m){
    // cout<<"INside fn."<<"with res: "<<res<<endl;
    while(rem!=0){															// Until completely divided/recurring fraction observed.
        long int curr=rem;													// Temp. storing remainder.
        if(m.count(rem)==1) break;											// If this dividend/remainder is already observed.
        long int quo=(curr*10)/divi;										// Calc. quotient.
        rem=(curr*10)%divi;													// Calc. remainder/dividend for next iteration.
        // cout<<"quo: "<<quo<<" and rem: "<<rem<<endl;
        m[curr]=res.length();												// Storing the occurance of curr. dividend.
        res+=to_string(quo);												// If remainder!=0, storing curr. quotient.
        // cout<<"APpended quo: "<<quo<<endl;
        if(rem==0) return res;  											// If proper division(No remainder), then return quotient.
    }
    int ind=m[rem];															// Get prev. occurance of curr. dividend.
    string temp="";															// Final result string.
    temp=res.substr(0,ind)+"("+res.substr(ind)+")";							// Forming final result str.
    return temp;															// Returning final result string.
    
}


string Solution::fractionToDecimal(int num1, int div1) {
    if(num1==0) return "0";													// Base cases.
    if(div1==1) return to_string(num1);										// Base cases.
    unordered_map<long int,int>m;											// Tracks rem. encountered on the way.
    string res="";															// Stores quotient of the division.
    if(num1<0 ^ div1<0) res+="-";											// Calc. neg. sign for the result.
    long int num=labs(num1), divi=labs(div1);								// Turning them into positive nums.
    // cout<<"num: "<<num<<" and divi: "<<divi<<endl;
    res+=to_string(num/divi);												// Calc. quo prior to Decimal point.
    if(num%divi==0)  return res;											// If no rem. then return the qoutient.
    res+=".";																// Adding '.' prior to fraction part.
    long int rem=num%divi;													// Forwarding divisor, remainder to the fn.
    // cout<<"rem: "<<rem<<endl;
    return findRem(res, rem,divi,m);										// Returning the quotient as string.
}
