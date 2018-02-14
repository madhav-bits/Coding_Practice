/*
*
//*************************************************************22. Generate Parentheses.****************************************************

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

[]
[1]
[1,2,3,4]
[1,1,1,2,2,3,3,4]
[0,1,0,0,4]
[1,1,1,2,2,3,3]
[-1,-1,0,0,1,1,2]

// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(n*n!).			
// This is dfs, the logic is that we add ")" or "(" at each step, inc. count accordingly, when sufficient length is reached, we check whether 
// balanced or not, if it is, then push into final result string vector.

class Solution {
public:
    void parenPerm(vector<string>&v, string s, int n, int count){
        if(s.length()==n){										// Once. the sufficient length is reached.
            //cout<<"Inside the return with s is: "<<s<<" and length is: "<<s.length()<<endl;
            if(count==0)										//Check whether it's balanced or not.
                v.push_back(s);
            return ;
        }    
        //cout<<"Inside the function with string s: "<<s<<" and count: "<<count<<endl;
        
        if(s.length()<n)
            parenPerm(v,s+"(",n,count+1);						// Count indicates #LPAREN - #RPAREN. 

        if(s.length()<n && count>0)								// As RPAREN is added count is decreased.
            parenPerm(v,s+")",n,count-1);
            
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if(n==0) return v;
        string s="";											// Temp. stores the parenthesis string.
        parenPerm(v,s,2*n,0);									// Calling the function.
        return v;
    }
};