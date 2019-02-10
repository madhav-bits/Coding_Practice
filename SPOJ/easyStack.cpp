/*

//*******************************************************STACKEZ - Easy Stack.************************************************************
https://www.spoj.com/problems/STACKEZ/



Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Implementing the stack functinalities.






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
    int tests;
    cin>>tests;
    // cout<<tests<<endl;
    stack<int>st;
    for(int a=0;a<tests;a++){
        int oper,val;
        cin>>oper;
        if(oper==1){
            cin>>val;
            st.push(val);
        }else if(oper==2){
            if(!st.empty()) st.pop();
        }else if(oper==3){
            if(st.empty()) cout<<"Empty!"<<endl;
            else cout<<st.top()<<endl;
        }
    }
    return 0;
}