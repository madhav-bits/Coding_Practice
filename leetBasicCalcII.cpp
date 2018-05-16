/*
*
//**********************************************************227. Basic Calculator II.***************************************************

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate 
toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"    3+   5 / 2+2-3/12+2 "
"3+2*12/3"
"31+2-2/2*5*3*9*6/8/22-2"
"31+2-2/2*5*3*9   *6/8/  22-2"



// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the given string and preprocesses it by removing the spaces. In the second we process "*" and "/"s later "+" and "-"s
// in the second iteration precedence wise. We maintain two ptrs one pts to the first operand of the oper., other ptr points to the second
// operand of the operator. When a sign is encountered the second oper. is obtained from vector and combined with first operand ptd by first ptr
// and the result is pushed into the locatin of first oeprand. We push all the contents("+" and "-"s in the first iteration directly into 
// the vector again, to be used in the second iteration. 

// As "*" and "/" have same precedence, they are evaluated in the order of occurance, same goes for "+" and "-" also.




class Solution {
public:
    int calculate(string s) {
        int j=0, res=0, add, sub, mul, div;
        string temp="";
        vector<string> v;
        for(int i=0;i<s.length();i++){                                                  // Removes Spaces.
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                v.push_back(temp);
                v.push_back(s.substr(i,1));
                temp="";
            }
            else if(s[i]>='0' && s[i]<= '9'){
                temp+=s[i];
            }
        }
        v.push_back(temp);
        // for(auto str:v)
        //     cout<<"The vector elem: "<<str<<endl;
        int len=v.size();
        if(v.size()==1) return stoi(v[0]);
        for(int i=0;i<2;i++){															// Allows two iterations.
            int a=0,b=1;
            while(b<len){																// Iterating till the end.
                if( (i==0 && (v[b]=="/" || v[b]=="*")) || (i==1 && (v[b]=="+" || v[b]=="-"))){
                    //cout<<"The symbol found at: "<<b<<endl;
                    int res;
                    if(i==0){															// In the first iter.		
                        //cout<<"Inside 0"<<endl;
                        if(v[b]=="/")													// Div. value is calc.
                            res=stoi(v[a])/stoi(v[b+1]);
                        else
                            res=stoi(v[a])*stoi(v[b+1]);    
                    }
                    else if(i==1){														// In the second iter.
                        if(v[b]=="+")
                            res=stoi(v[a])+stoi(v[b+1]);								// Calc. the addn value.
                        else
                            res=stoi(v[a])-stoi(v[b+1]); 
                    }
                    v[a]=to_string(res);
                    b++;
                }
                else{																	// Passing values for next iteration.
                    a++;
                    v[a]=v[b];
                }
                b++;																	// Updating the iterator.
            }
            //v.resize(a+1);
            len=a+1;																	// Setting the length for the next iteration.
            // for(auto str:v)
            //     cout<<"The vector elem after addn: "<<str<<endl;
            // cout<<endl;
        }
        
        return stoi(v[0]);																// Returning the result.
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm iterates the array, it treats "+" and "-" as values not as operator b/w two nonzero ints. So, we have primarily two oper. "*" and 
// "/"s. When "+" and "-" encountered there next values are evaluated wrto them. When "*" and "/" are encountered the sign is stored, when next
// operand is completely scanned and another sign is encountered, value is evlauted from curr. and previously stored value from stack and the
// result is stored back on to stack. Thus, we get the final result.







class Solution {
public:
    int calculate(string s) {
        int temp=0, i=0, ans=0;
        string sign="+";																// Stores the sign for the next operation.
        stack<int> st;																	// Stores the ints.
        while(i<=s.length()){
            if(s[i]>='0' && s[i]<='9')													// Calc. the ints.
                temp=temp*10+s[i]-'0';
            
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==s.length()){		// When sign encountered or end of string is reached.
                //cout<<"Inside the sign cdn with temp: "<<temp<<endl;
                if(sign=="+")st.push(temp);												// +/- are simply evaluated against single operand
                else if(sign=="-") st.push(-temp);
                else{																	// Evaluted are against curr. and prev. operands.
                    int res=0;
                    res=(sign=="*")?st.top()*temp:st.top()/temp;
                    st.pop();															// Removing first oper. from stack.
                    st.push(res);														//  Pushing the result onto stack.
                    //cout<<"Pushing res: "<<res<<endl;
                }
                temp=0;																	// Updating the operand value.
                sign=s[i];																// Storing the curr. sign.
            }
            
            i++;																		// INc. the iterator.
        }
        
        while(!st.empty()){																// Adding all the rem. values.
            ans+=st.top();
            st.pop();
        }
        
        return ans;																		// Returning the result.
    }
};


