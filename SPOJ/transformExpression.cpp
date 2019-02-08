/*

//**************************************************ONP - Transform the Expression.************************************************
https://www.spoj.com/problems/ONP/




Time Complexity:O(n^2).                                                     // Linear time for appending operands for each symbol.                                                                                                                                         
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  // Linear time for appending operands for each symbol.
// Space Complexity:O(n).                                                   
// This is Stack based solution. Append operands symbols and operands as we iterate through. Once, we encounter ')' symbol, we
// we extract symbols and operands corresponding to this closed paren, append them and push them back into stack. At the end of 
// iter. we have the resulting RPN form on top of stack.(In fact, that would be the only elem. left in Stack).




#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>





using namespace std;



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        string s="";
        cin>>s;
        stack<string>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') continue;
            else if(s[i]==')'){
                string s1=st.top();st.pop();
                string s2=st.top(); st.pop();
                string s3=st.top(); st.pop();
                s3+=s1;
                s3+=s2;
                st.push(s3);
            }else{
                st.push(s.substr(i,1));
            }
        }
        cout<<st.top()<<endl;
    }
    return 0;
}