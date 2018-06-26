/*
*
//**********************************************************772. Basic Calculator III.***************************************************

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The 
integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

Some examples:

"1 + 1" = 2
" 6-4 / 2 " = 4
"2*(5+5*2)/3+(6/2+8)" = 21
"(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 

Note: Do not use the eval built-in library function.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"-2*(6*2/3+(2*3+1-2)*2)"
"(6*2/3)"
"6*2/3"
"1"
"1+2-2*2/4"




// Time Complexity: O(n).  
// Space Complexity: O(n).								// If array has all single digits, each enclosed in recur. parens).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).								// If array has all single digits, each enclosed in recur. parens).
// This algorithm iterates the array,whenever we extract a val, we add it to total sum in that scope, if we encounter a '(', we give a recursive
// call to extract sum of numbers inside the brackets, at the end of paran, we return the sum accumulated in it, and add it to the enclosing 
// scope's sum. We iterate till the end of the array.








class Solution {
public:
    int extractVal(string s, int &i){
        // cout<<"INside the fn. with index i: "<<i<<endl;
        int sum=0, temp=0, prev=0;
        char sign='+';
        for(;i<=s.length();i++){
            // cout<<"Curr. index is: "<<i<<endl;
            if(i<s.length() && s[i]>=48 && s[i]<=57){						// Calc. curr. num value.
                temp=temp*10+stoi(s.substr(i,1));
            }
            else if(i<s.length() && s[i]=='('){								// If '(' encountered, we give recursive call to extract sum.
                i++;
                temp=extractVal(s,i);
                //i++;
            }
            
            if(i<s.length() && s[i]=='+' || s[i]=='-'|| s[i]=='*'|| s[i]=='/'){
                // cout<<"Curr. extraceted value: "<<temp<<"with prev: "<<prev<<endl;
                if(sign=='*'){												// If curr. num has to get multiplied to prev. num, then extract
                    sum=sum-prev+(prev*temp);								// num, remove from total, add prev*curr. num to total.
                    prev=prev*temp;
                }
                else if(sign=='/'){											// Same as multiplying, use prev. value.
                    sum=sum-prev+(prev/temp);
                    prev=prev/temp;
                }
                else if(sign=='+'){											// Add, curr. value to total.
                    sum=sum+temp;
                    prev=temp;
                }
                else if(sign=='-'){
                    sum=sum-temp;
                    prev=-temp;
                }
                sign=s[i];
                // prev=temp;
                temp=0;														// Setting default value for next int.
            }
            
            if(i==s.length() || s[i]==')'){									// If end of paren/string is reached, return the sum.
                // cout<<"Curr. extraceted value: "<<temp<<endl;
                if(sign=='*'){
                    sum=sum-prev+(prev*temp);
                }
                else if(sign=='/'){
                    sum=sum-prev+(prev/temp);
                }
                else if(sign=='+'){
                    sum=sum+temp;
                }
                else if(sign=='-'){
                    sum=sum-temp;
                }
                // cout<< "Returned  value: "<< sum<<endl; 
                i++;														// Move to next int outside paren.
                // temp=0;
                return sum;													// Accum. sum in curr. scope/paren.
            }
            
        }
        return sum;
    }
    
    int calculate(string s) {
        int index=0;														// Index tracking iteration through the string.
        return extractVal(s,index);											// Calling fn. to extract sum.
    }
};










//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).								// If array has all single digits, each enclosed in recur. parens).
// This algorithm iterates the array,whenever we extract a val, we add it to total sum in that scope, if we encounter a '(', we give a recursive
// call to extract sum of numbers inside the brackets, at the end of paran, we return the sum accumulated in it, and add it to the enclosing 
// scope's sum. We iterate till the end of the array.



// This is the same as the above one, just that I had removed redundnat if conditions, execution time significantly removing if cdns.



class Solution {
public:
    int extractVal(string s, int &i){
        // cout<<"INside the fn. with index i: "<<i<<endl;
        int sum=0, temp=0, prev=0;
        char sign='+';
        for(;i<=s.length();i++){
            // cout<<"Curr. index is: "<<i<<endl;
            if(i<s.length() && s[i]>=48 && s[i]<=57){
                temp=temp*10+stoi(s.substr(i,1));
            }
            else if(s[i]=='('){
                i++;
                temp=extractVal(s,i);
                //i++;
            }
            
            if((i<s.length() && s[i]=='+' || s[i]=='-'|| s[i]=='*'|| s[i]=='/') || i==s.length() || s[i]==')'){
                // cout<<"Curr. extraceted value: "<<temp<<"with prev: "<<prev<<endl;
                if(sign=='*'){
                    sum=sum-prev+(prev*temp);
                    prev=prev*temp;
                }
                else if(sign=='/'){
                    sum=sum-prev+(prev/temp);
                    prev=prev/temp;
                }
                else if(sign=='+'){
                    sum=sum+temp;
                    prev=temp;
                }
                else if(sign=='-'){
                    sum=sum-temp;
                    prev=-temp;
                }
                if(i==s.length() || s[i]==')'){
                    i++;
                    return sum;
                }
                sign=s[i];
                // prev=temp;
                temp=0;
                
            }
            
        }
        return sum;
    }
    
    int calculate(string s) {
        int index=0;
        return extractVal(s,index);
    }
};