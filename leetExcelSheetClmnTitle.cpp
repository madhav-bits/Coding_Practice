/*
*
//******************************************************168. Excel Sheet Column Title.***********************************************

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



1
26
27
676
677
701
702
703




// Time Complexity: O(logn/log26).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logn/log26).
// Space Complexity: O(1).	
// This algorithm is Base 26 based. At each step, we extract the curr. char from the number provided. We update the number to extract the next 
// char. Thus, after obtaining the all chars, we reverse the string to the final result.





class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n>0){
            int rem=n%26;													// Extrac.the curr.char.
            if(rem==0) rem=26;												// If rem==0, append 'Z'.
            n=(n-rem)/26;													// Updating the val.for next char.
            res+=rem+64;													// Appending the curr. char to the final result.
        }
        // if(n!=0)
        //     res+=n+64;
        //cout<<"Preswapped ans: "<<res<<endl;
        int i=0, j=res.length()-1;
        while(i<j){															// Reversing the obtained string.
            swap(res[i], res[j]);
            i++;j--;
        }
        //cout<<"The final ans: "<<res<<endl;
        return res;															// Returning the final result string.
    }
};