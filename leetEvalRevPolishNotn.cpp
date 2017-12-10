/*

//***************************************************150. Evaluate Reverse Polish Notation.**********************************************

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6



//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
   
class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int> s;
        int sum=0;
        int temp; 
        for(int i=0;i<v.size();i++){			
            if(s.size()>0 && (v[i]=="+")){			//When + sign is encountered, adding it's related terms and pushing it to stack, so that-
                int num2=s.top();					// It might get added to other term, bound to a operation.(+/-/*/"/").
                s.pop();
                int num1=s.top();
                s.pop();
                temp=num1+num2;
                s.push(temp);
                //cout<<"Inside + condition with temp: "<<temp<<endl;
            }
            else if(s.size()>0 && (v[i]=="-")){		//Calc the result and pushing it to stack.
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                temp=num1-num2;
                s.push(temp);
                //cout<<"Inside - condition with temp: "<<temp<<endl;
            }
            else if(s.size()>0 && (v[i]=="*")){		//Calc the result and pushing it to stack.
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                temp=num1*num2;
                s.push(temp);
                //cout<<"Inside * condition with temp: "<<temp<<endl;
            }
            else if(s.size()>0 && (v[i]=="/")){		//Calc the result and pushing it to stack.
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                temp=num1/num2;
                s.push(temp);
                //cout<<"Inside / condition with temp: "<<temp<<endl;
            }
            else{									//In the case of encountering an integer, simply converting it to int. and push into stack.
                int a=stoi(v[i]);
                s.push(a);
                //cout<<"Inside else condition with integer: "<<a<<endl;
            }
        }
        return s.top();								//Finally stack contains only one elem. which is the final result of all the operations.
    }
};