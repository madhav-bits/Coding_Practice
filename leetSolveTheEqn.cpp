/*
*
//**************************************************************640. Solve the Equation.***************************************************

Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable 
x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

Example 1:
Input: "x+5-3+x=6+x-2"
Output: "x=2"
Example 2:
Input: "x=x"
Output: "Infinite solutions"
Example 3:
Input: "2x=x"
Output: "x=0"
Example 4:
Input: "2x+3x-6x=x+2"
Output: "x=-1"
Example 5:
Input: "x=x+2"
Output: "No solution"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"0x+x+5-3+0x+x=0x+6+x-2"
"x+5-3+x=6+6x-2"
"x=x+1"
"x+2=x+2"
"x=1"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array. At each step, it checks for various conditions. At the end, it gets numbers of x's on left and right side, 
// and sum of values  on left and right side, divide those values to get value ofx, and return it.








class Solution {
public:
    string solveEquation(string s) {
        int lSum=0, rSum=0, lx=0, rx=0;
        int lt=1, sign=1;
        int i=0, temp=0;
        while(i<=s.length()){
            // cout<<"Inside the while with i: "<<i<<endl;
            if(i==s.length() ||s[i]=='+'|| s[i]=='-' || s[i]=='='){
                // cout<<"Inside the fisrt while."<<endl;
                if(s[i-1]=='x' && lt==1){
                    if(temp>0) lx=lx+(sign*temp);
                    else if(i-2>=0 && (s[i-2]=='0')) lx;
                    else lx+=sign;
                }
                else if(s[i-1]=='x' && lt==0){
                    if(temp>0) rx=rx+(sign*temp);
                    else if(i-2>=0 && s[i-2]=='0') rx;
                    else rx+=sign;
                }
                else if(temp>0 && lt==1){
                    lSum+=(sign*temp);
                }
                else if(temp>0 && lt==0){
                    rSum+=(sign*temp);
                }
                
                
                if(s[i]=='='){
                    lt=0;
                    sign=1;
                }
                
                if(s[i]=='+') sign=1;
                else if(s[i]=='-') sign=-1;
                i++;
                temp=0;
                // cout<<"End of first if with i: "<<i<<endl;
            }
            else{
                // cout<<"Inside the second while."<<endl;
                while(i<s.length() && s[i]>=48 && s[i]<=57){
                    temp=temp*10+s[i]-48;
                    i++;
                }
                if(s[i]=='x') i++;
            }
            
        }
    
        
        // cout<<"lx: "<<lx<<endl;
        // cout<<"rx: "<<rx<<endl;
        // cout<<"lsum: "<<lSum<<endl;
        // cout<<"rsum: "<<rSum<<endl;
        if(lx==rx && lSum==rSum) return "Infinite solutions";				// If x's and sum on both sides are equal, return Infi. Slns.
        else if(lx==rx && lSum!=rSum) return "No solution";					// If x's and sum on both sides not equal, return No Sln.
        else{
            int xRem, rem;
            lx-=rx;
            rSum-=lSum;
            rSum/=lx;
            return "x="+to_string(rSum);									// Returning the value of x.
        }
    }
};