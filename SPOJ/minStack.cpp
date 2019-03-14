/*

//***********************************************MINSTACK - Smallest on the Stack.***************************************************
https://www.spoj.com/problems/MINSTACK/




Time Complexity:O(1).                                                       // O(1) for each operation.                                                                                                                                                                                        
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                    // O(1) for each operation.
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, since we need to maintain minm. values, we iter. over given values and push them onto stack,
// while pushing curr. value we also push minm. of minm. till then, curr. value  on to top of stack. Now, while popping, since
// it shouldn't effect bottom values, we just remove top pair, the bottom values and their minm. would be stored intact. 







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

    int oper;
    cin>>oper;
    string s="";
    int val;
    stack<pair<int,int>>st;
    for(int a=0;a<oper;a++){
        cin>>s;
        if(s=="PUSH"){
            cin>>val;
            if(st.empty()) st.push({val, val});
            else st.push({val, min(st.top().second, val)});
        }else if(s=="MIN"){
            if(st.empty()) cout<<"EMPTY"<<endl;
            else cout<<st.top().second<<endl;
        }else if(s=="POP"){
            if(st.empty()) cout<<"EMPTY"<<endl;
            else st.pop();
            // else cout<<st.top().second<<endl;
        }
    }

    return 0;
}
