/*

//*****************************************************ELEVTRBL - Elevator Trouble.***************************************************
https://www.spoj.com/problems/ELEVTRBL/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Breadth first based solution. Here, we store the floors in the queue which are possible to reach starting from source
// floor in 'k' moves, we also make sure not to include dulicate floor values by tracking visited floors using unordered set and the
// first time we see the target floor, we return the #moves made till then. 







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

    int floors, start, dest, up, down;
    cin>>floors>>start>>dest>>up>>down;

    if(start==dest){
        cout<<0<<endl;
        return 0;
    }

    queue<int>q;
    unordered_set<int>st;
    q.push(start);
    st.insert(start);
    int dist=0;
    bool found= false;
    while(!q.empty()){
        int len=q.size();
        dist++;
        for(int i=0;i<len;i++){
            int curr=q.front();
            q.pop();
            int fol=curr+up;
            if(fol==dest){
                found=true;
                break;
            }
            if(st.count(fol)==0 && fol<=floors){
                q.push(fol);
                st.insert(fol);
            }
            fol=curr-down;
            if(fol==dest){
                found=true;
                break;
            }
            if(st.count(fol)==0 && fol<=floors && fol>=0){
                q.push(fol);
                st.insert(fol);
            }
        }
        if(found) break;
    }
    if(found) cout<<dist<<endl;
    else cout<<"use the stairs"<<endl;

    return 0;
}