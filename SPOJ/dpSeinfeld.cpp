/*

//*******************************************************ANARC09A - Seinfeld.*********************************************************
https://www.spoj.com/problems/ANARC09A/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, we iter. over given string, cancel out balanced parens, the resulting unbalanced parens would
// be of this form ("}}}}}{{{{{"), we invert the half of open parens to cancel out other half of unbalanced open parens, the same goes 
// with closed parent, if we have odd number of open, close parens, we invert the drn of those two last parens, so the formula would
// (open/2+close/2+(2*(even%2))).





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
#include<cmath>




using namespace std;




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    string s;
    cin>>s;
    int cases=0;
    while(s[0]!='-'){
        cases++;
        // cout<<"len: "<<s.length()<<endl;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{') st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='{') st.pop();
                else st.push('}');
            }
        }
        int open=0, close=0;
        while(!st.empty()){
            char ch=st.top();
            st.pop();
            if(ch=='{') open++;
            else close++;
        }
        int minm=min(open, close);
        int maxm=max(open, close);
        // int res=(2*minm+(maxm-minm)/2);
        int res=(open/2+close/2+(2*(open%2)));                              // Formula to get min #moves to balane unbalanced parens.
        cout<<cases<<". "<<res<<endl;
        cin>>s;
    }


    return 0;
}