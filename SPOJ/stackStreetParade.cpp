/*

//*******************************************************STPAR - Street Parade.***********************************************************
https://www.spoj.com/problems/STPAR/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, we iterate over given buses. At every step, if we get the bus we are looking for we take the 
// bus and inc. the expected bus number. If not we check whether do we have any buses in  stack which might match the curr. required
// bus number. If it is, we pop it out of stack until stack is empty/stack's top bus isn't expected bus number. Later, we check for 
// curr. bus if it's required bus number, we inc. the expected bus number/ if it isn't expected bus number, we push the bus onto stack.
// After whole iteration, we once try to pop the buses out of stack. After this process, if the expected bus number is total buses+1,
// then all buses are obtained as expected, then return "yes", else return "no".









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

    
    while(true){
        int nums;
        cin>>nums;
        if(nums==0) break;
        int minm=1;
        stack<int>st;
        for(int i=0;i<nums;i++){
            // cout<<"curr. num: "<<v[i]<<endl;
            int num;
            cin>>num;
            if(num==minm) minm++;
            else{
                while(!st.empty() && minm==st.top()){
                    st.pop();
                    minm++;
                }
                if(minm!=num) st.push(num);
                else minm++; 
            }
        }
        while(!st.empty() && minm==st.top()){
            st.pop();
            minm++;
        }
        if(minm==nums+1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}