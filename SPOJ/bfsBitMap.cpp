/*

//*******************************************************BITMAP - Bitmap.***********************************************************
https://www.spoj.com/problems/BITMAP/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we start BFS from all indices which have 1s in them. Here, the distances are Manhattan distance
// based. Start indices are marked with 0 in result vector, while performing BFS, we push only those indices whose marked dist in 
// final result vector is greater than curr. dist. reachable using BFS. If an index had already been reached then it's that it will
// have lower value filled in it, which is the requirement(smaller dist) of this problem. After the BFS, we iter. over result vector
// and print the values acc. to the requirements in the problem.









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


vector<int>dirs;

void fillGraph(vector<vector<int>>&graph, queue<pair<int,int>>&q){
    int dist=0;
    while(!q.empty()){
        int len=q.size();
        dist++;
        for(int i=0;i<len;i++){
            int x=q.front().first, y=q.front().second;
            q.pop();    
            for(int j=0;j<4;j++){
                int dx=dirs[j], dy=dirs[j+1];
                if(x+dx<0 || y+dy<0 || x+dx>=graph.size() || y+dy>=graph[0].size() || graph[x+dx][y+dy]<=dist) continue;
                q.push({x+dx, y+dy});
                graph[x+dx][y+dy]=dist;
            }
        }
    }
    return ;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");




    dirs=vector<int>({-1,0,1,0,-1});
    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        int num, len;
        cin>>num>>len;
        // vector<string>v(num);
        string s;
        queue<pair<int,int>>q;
        vector<vector<int>>graph(num,vector<int>(len,INT_MAX));
        for(int i=0;i<num;i++){
            cin>>s;
            // cout<<"str: "<<s<<endl;
            for(int j=0;j<len;j++){
                if(s[j]=='1'){
                    graph[i][j]=0;
                    q.push({i,j});
                }
            }    
        }
        fillGraph(graph, q);

        for(int i=0;i<graph.size();i++){
            for(int j=0;j<len;j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }

    }

    return 0;
}