/*

//*****************************************************************NAKANJ - Minimum Knight moves !!!*************************************************************
https://www.spoj.com/problems/NAKANJ/



Time Complexity:O(n^2).
Space Complexity:O(n^2).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).
// Space Complexity:O(n^2).
// This is BFS based problem. At each step, we save unviisted indices and store them in queue making sure that we won't revisit visited nodes again.
// Once, we reach target str, we return dist. till then.










#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>


using namespace std;

int main() {
    // your code goes here
    int tests;
    cin>>tests;
    vector<int>dirs({-1,-2,-2,-1,-2,1,-1,2,1,-2,2,-1,2,1,1,2});
    for(int k=0;k<tests;k++){
        string start, close;
        cin>>start>>close;
        if(start==close){
            cout<<0<<endl;
            continue;
        }
        // vector<vector<int>>dp(8,vector<int>(8,INT_MAX));
        int tRow=close[0]-'a';
        int tClmn=close[1]-'1';
        string tar=to_string(tRow)+to_string(tClmn);
        int sRow=start[0]-'a';
        int sClmn=start[1]-'1';
        queue<pair<int,int>>q;
        q.push({sRow, sClmn});
        unordered_set<string>st;
        st.insert(to_string(sRow)+to_string(sClmn));
        int steps=0;
        while(!q.empty()){
            int len=q.size();
            steps++;
            // cout<<"dist: "<<steps-1<<endl;
            for(int j=0;j<len && !q.empty();j++){
                pair<int,int>curr=q.front();
                q.pop();
                int x=curr.first, y=curr.second;
                // cout<<"x: "<<x<<" and y: "<<y<<endl;
                for(int i=0;i<dirs.size();i+=2){
                    int dx=dirs[i], dy=dirs[i+1];
                    if(x+dx<0 || x+dx>=8 || y+dy<0 || y+dy>=8) continue;
                    string temp=to_string(x+dx)+to_string(y+dy);
                    if(temp==tar){
                        cout<<steps<<endl;
                        q=queue<pair<int,int>>();
                        break;
                    }
                    if(st.count(temp)==0){
                        q.push({x+dx,y+dy});
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return 0;
}