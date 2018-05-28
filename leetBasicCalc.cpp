/*
*
//**********************************************************224. Basic Calculator.***************************************************


Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"(1+(4+-5+2)-3)+(6+8)"
"(1+(4+-5+2)-3)+(6+8)-()+()"
"(1+(4+-5+2)-3)+(6+8)-(9)+()"
"(1-(4+21-5+2)-3)+(6+8)-(9)+()"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is stack based. At each step we extract pos/neg values and push them into stack. Whenever we enter a bracket we call a fn. 
// to extract summation of that bracket, once extracted that sum is pushed into stack. At the end of iteration, we scan through stack and sum
// all numbers and return result.

// The two fns are almost same except that top fn. also has case to handle close parens-")".


// As it involves many function calls(depending on braces), it takes very lengthier time to execute.





class Solution {
public:
    int calcValue(string s){
        //cout<<"The beginningof calcValue fn. with index: "<<i<<endl;
        //int res=0;
        stack<int> st;
        int temp=0, sign=0;
        for(;i<s.length();i++){
            if(s[i]>=48 && s[i]<=57){
                temp=(temp*10)+stoi(s.substr(i,1));
            }
            else if(s[i]=='+'){
                //cout<<"pushed val .into stack is: "<<temp<<endl;
                if(sign==1) st.push((-temp));
                else st.push(temp);
                temp=0;
                sign=0;
            }
            else if(s[i]=='-'){
                if(sign==1) st.push((-temp));
                else st.push((temp));
                temp=0;
                sign=1;
            }
            else if(s[i]=='('){
                i++;
                int res= calcValue(s);//s.substr(i+1)
                if(sign==1) st.push((-res));
                else st.push((res));
                //sign=0;
            }
            else if(s[i]==')'){														// If end of brace is reached, break from iteration.
                //i++;
                break;
            }
        }
        if(sign==1) st.push((-temp));
        else st.push((temp));
        
        int ans=0;
        while(!st.empty()){															// Calc. the value of expression and returning it.
            ans+=st.top();
            st.pop();
        }
        //cout<<"The result of calcValue fn. is: "<<ans<<"at index: "<<i<<endl;
        return ans;
    }
	
	
        
    int i=0;
    int calculate(string s) {
        //int res=0;
        stack<int> st;
        int temp=0, sign=0;												// Sign indicates prev. sign is +/-.
        for(;i<s.length();i++){
            if(s[i]>=48 && s[i]<=57){									// Calc. the value of int.
                temp=(temp*10)+stoi(s.substr(i,1));
            }
            else if(s[i]=='+'){											// Pushing the prev. value into stack.
                if(sign==1) st.push((-temp));
                else st.push(temp);
                temp=0;
                sign=0;
            }
            else if(s[i]=='-'){											// Pushing the prev. value into stack.
                if(sign==1) st.push((-temp));
                else st.push((temp));
                temp=0;
                sign=1;
            }
            else if(s[i]=='('){											// Extracting the summation from the brace enclosed expression.
                i++;
                int res= calcValue(s);									// Pushing the res from brace into stack.
                if(sign==1) st.push((-res));
                else st.push((res));
                i--;
                //sign=0;
            }
        }
        if(sign==1) st.push((-temp));									// Adding last present int. to stack.
        else st.push((temp));
        int ans=0;
        while(!st.empty()){												// Summing up all contents of stack to get result.
            ans+=st.top();
            st.pop();
        }
        //cout<<"The result of main. fn. is: "<<ans<<endl;
        return ans;														// Returning the total summation.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is stack based. At each step we sum up all values till then, if opeing brace encountered, sum till then is stored in stack and
// sign before brace is stored in stack. Inside the entire sum is calculated, after the brace the result is added to the previous summation and
// iterations goes ahead with the updated summation. Thus, at the end of iteration we get the total summation in res-variable.





class Solution {
public:
    int calculate(string s) {
        int res=0;
        stack<int> st;																	// To store the summation/sign values.
        int temp=0, sign=1;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48 && s[i]<=57){
                temp=(temp*10)+stoi(s.substr(i,1));
            }
            else if(s[i]=='+'){															// Updating the summation till then.
                res+=(sign*temp);
                //cout<<"Updated res. at add sign is: "<<res<<endl;
                sign=1;																	// Storing the sign of value.
                temp=0;
            }
            else if(s[i]=='-'){
                res+=(sign*temp);
                //cout<<"Updated res. at minus sign is: "<<res<<endl;
                sign=-1;
                temp=0;
            }
            else if(s[i]=='('){															
                //cout<<"Res to be stored: "<<res<<" ans sign: "<<sign<<endl;
                st.push(res);															// Sum till then, sign of brace is stored in stack.
                st.push(sign);
                sign=1;																	// Sign to be used for first int. in brace.
                res=0;																	// As, summation starts freshly in brace.
            }
            else if(s[i]==')'){															// If close brace is encountered.
                res+=sign*temp;															// Getting the summation of brace's contents.
                res=st.top()*res;														// Applying the sign prior to opening brace.
                st.pop();
                //cout<<"Brackets val. to be stored: "<<l<<" and top: "<<st.top()<<endl;
                res+=st.top();															// Adding the result from brace to prev. summation
                st.pop();
                temp=0;																	// As, summation b/w next ")" and +/- is 0.
            }
        }
        res+=sign*temp;																	// Adding the val. of last int. in expression.
        return res;																		// Returning the total summation.
    }
};