/*
*
//******************************************************592. Fraction Addition and Subtraction.***********************************************

Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The 
final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that 
has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If 
the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"-1/2+1/4+1/4"

"-1/2+1/3-1/10"

"-1/2+1/3+1/4"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. We iterate through the entire array, we store numers and denoms in two vectors, calc. lcm from the 
// denom. vector, accordingly we inc. the value of the numer and denom. to match the value of the LCM of denom. Later we find the gcd of the 
// updated sum of numer values, LCM of denom., we divide both the sum of number and LCM of denom. with this number to get the irreducible 
// form of addition of fractions.


// This can be done without using vectors by calc. LCM for every two values, but for simplicity and also reduce the number of calls to LCM, GCD fn.
// I had done the LCM, GCD for the additon for all nums at a single go at the end.






class Solution {
public:
    
    int gcd(int a, int b){													// Calc. GCD of two nums.
        if(b==0) return a;
        
        return gcd(b,a%b);
    }
    
    
    int findLCM(vector<int> &v){											// Calc. LCM of all denom. values.
        int res=v[0];
        for(int i=1;i<v.size();i++){
            res=(res*v[i])/gcd(v[i],res);
        }
        return res;
    }
    
    
    string fractionAddition(string s) {
        vector<int>numer,denom;												// Stores numer and denom. values in the array.
        int temp=0;
        int sign=1;															// Stores the sign of curr. numer.
        for(int i=0;i<s.length();i++){
            // cout<<"CUrr. index is; "<<i<<endl;
            if((s[i]=='+' || s[i]=='-')){									// Extract the denom. value.
                if(temp!=0)
                    denom.push_back(temp);
                if(s[i]=='-') sign=-1;										// Store the sign for the next num.
                else sign=1;
                temp=0;
            }
            else if(s[i]=='/'){												// Storing the numer.
                numer.push_back(sign*temp);
                temp=0;
            }
            else{
                // cout<<"Curr. num is; "<<stoi(s.substr(i,1))<<endl;
                temp=temp*10+stoi(s.substr(i,1));							// Updating the curr. num.
            } 
        }
        if(temp!=0) denom.push_back(temp);									// Storing the last denom.
        int lcm= (denom.size()==1)?denom[0]:findLCM(denom);					// Calc. LCM of all denoms.
        int up=0;															// Stores the updated sum of all inc. numer values.	
        for(int i=0;i<numer.size();i++)
            up+=numer[i]*(lcm/denom[i]);									// Updating the numer values to match the LCM of denoms.
        
        // cout<<"up: "<<up<<endl;
        int result=gcd(abs(up),lcm);										// Calc. the GCD of the sum of updated numer. values and LCM of denom.
        // cout<<"The gcd of numer and denom: "<<result<<endl;
        string res="";
        res+=to_string(up/result)+"/"+to_string(lcm/result);				// Forming the result value.
        return res;
    }
};