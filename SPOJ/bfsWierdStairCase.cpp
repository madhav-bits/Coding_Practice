/*

//*************************************************STAR3CAS - THE WEIRD STAIRCASE.***************************************************
https://www.spoj.com/problems/STAR3CAS/




Time Complexity:O(edges).                                                                                                                                                                                             
Space Complexity:O(nodes).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(edges).                                                  
// Space Complexity:O(nodes).                                                   
// This is BFS based solution. We first from first node, mark visited nodes as we move, if a node is with in bounds and unvisited
// then next step would be it's shortest path from src. We mark visited nodes, so that we won't revisit them. Once target value is 
// obtained, we break from BFS loop. 







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

    
    int tests, steps;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>steps;
        vector<int>v(steps,0);
        vector<bool>visited(steps, false);
        for(int i=0;i<steps;i++) cin>>v[i];
        int res=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        bool found=false;
        int target=steps;
        while(!q.empty()){
            int len=q.size();
            res++;
            for(int i=0;i<len;i++){
                int curr=q.front();
                q.pop();
                int dx=v[curr];
                if(curr+dx==target || curr+1==target){
                    found=true;
                    break;
                }
                if(curr+dx>=0 && curr+dx<target && visited[curr+dx]==false){
                    q.push(curr+dx);
                    visited[curr+dx]=true;
                }
                if(curr+1>=0 && curr+1<target && visited[curr+1]==false){
                    q.push(curr+1);
                    visited[curr+1]=true;
                }
            }
            if(found) break;
        }
        cout<<res<<endl;
    }

    return 0;
}
