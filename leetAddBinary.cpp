/*
*
//****************************************************************67. Add Binary.*******************************************************

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"1001"
"101010"

"101001"
"101010"

"0110"
"0"




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step  calculates the sum of the array, calc. the curr. result and carry and pass it to next iter.,
// In the next iter. we use the carry forwarded from prev. bit's sum in calc. the curr. bit's addn.








class Solution {
public:
    string addBinary(string a, string b) {
        string res="";														// Result str.
        int i=a.length()-1, j=b.length()-1;								
        int sum, carry=0;													// Stores sum and carry of addns. 
        while(i>=0 || j>=0 || carry>0){										// Iterates till max len of two strs, until carry exists.
            if(i>=0 && a[i]=='1')carry++;									// If index valid, extract value.
            if(j>=0 && b[j]=='1') carry++;
            res=to_string(carry%2)+res;										// Calc. curr. index addn value.
            carry=carry/2;													// Calc. carry for the next iteration.
            i--;															// Dec. the iterator values.
            j--;
        }
        // cout<<"The result is: "<<res<<endl;
        return res;															// Returning the result str.
        
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, at each step  calculates the sum of the array, calc. the curr. result and carry and pass it to next iter.,
// In the next iter. we use the carry forwarded from prev. bit's sum in calc. the curr. bit's addn. The improvization of this algo. to above one
// is that it calculates the maxm length of two arrays and initiate an result str of that length.Thus, avoiding appending each bit at the 
// beginning of the result after calc. each Higher significant bit.





class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1, j=b.length()-1;
        int sum, carry=0;													// Stores sum and carry of addns.
        int maxm=max(a.length(), b.length());								// Calc. max. of two lengths.
        string res2(maxm,'0');												// Init. result str of length maxm. of two strs.
        while(maxm>0){														// Iter. max of the two strs.
            if(i>=0 && a[i--]=='1')carry++;									// If index valid, then extract value.
            if(j>=0 && b[j--]=='1') carry++;
            res2[maxm-1]=carry%2+'0';										// Extracts curr. index's addn value.
            carry=carry/2;													// Extract carry value.
            maxm--;															// Decreasing the iterator value.
        }
        
        if(carry>0) res2="1"+res2;											// If carry still exists, then append it to beginning of the str.
        // cout<<"The result is: "<<res2<<endl;
        return res2;														// Returning the calc. result str.
        
    }
};