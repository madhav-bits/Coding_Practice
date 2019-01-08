/*
*
//**************************************************************Binary Representation.*******************************************************

https://www.interviewbit.com/problems/binary-representation/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1


2


16


17


15



21473647





// Time Complexity: O(k).  
// Space Complexity: O(k).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(k).
// Space Complexity: O(k).	
// This algorithm is iteration based. Here, we approach from MSB to LSB, since numbers are represented in powers of 2, we extract MSB by checking
// whether it's set to 1(curr. num divisible by curr. divisor), accordingly store MSB and remove the divisor from num. if divisible. In the next
// step we decrease the divisor by 2 and repeat the process as in first step and do this until div is >0. Now, we remove the preceeding zeroes in
// the beginning and return the remaining string.








string Solution::findDigitsInBinary(int num) {
	if(num==0) return "0";													// Base case.
    string res="";															// Stores the final form.
    int div=pow(2,30);														// Highest bit value.
    while(div>0){															// Until num is valid.
        // cout<<"num: "<<num<<" and div: "<<div<<endl;
        if(num/div>0){														// If curr. bit is set to 1.
            res+='1';														// Storing bit value.
            num-=div;														// Removing curr. divisor from num. 
        } 
        else res+='0';														// Curr. num not divisible by curr. divisor.
        div/=2;																// Reducing the divisor value by 2.
    }
    int index=0;			
    while(index<res.length() && res[index]=='0') index++;					// Removing preceeding zeroes.
    return res.substr(index);												// Returning the bit form of given int.
}







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(k).
// Space Complexity: O(k).	
// This algorithm is iteration based. This is from LSB to MSB. We extract the last bit each time, since every num. is written in terms of powers 
// of 2, after extracting LSB, we divide by 2, to right push the bits by 1 step. Now, once again divide by 2 to get LSB, we do this until the 
// num becomes 0.






string Solution::findDigitsInBinary(int num) {
    if(num==0) return "0";													// Base case.
    string res="";															// Final bit form string.
    while(num>0){															// Until bit is valid.
        if(num%2==1) res+='1';												// If LSB is 1, store it.
        else res+='0';														// If LSB is 0.
        num/=2;																// Div. by 2 to a left shift of bits by 1 step.
    }
    reverse(res.begin(), res.end());										// Reverse the obtained bit form.
    return res;																// Return the bits form string.
}
