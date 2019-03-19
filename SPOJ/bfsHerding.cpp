/*

//*******************************************************HERDING - Herding.***********************************************************
https://www.spoj.com/problems/HERDING/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we iter. over all indices that are reachable from an index, and color them with some value. If in
// the next iter. where we color new set of indices with increased color value. If we stop that iter., because of encountering an 
// already encountered in prev. DFS iter.(it has lower color value).Then the curr. set of indices will also lead to prev. set of indices
// so, we need not count these set as independent. If we stop becuase of encountering an index, which has been already visited in this 
// iter., it's that this set of indices are independent. At the end of iter., we return the #independent index groups formed.








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




void coverIndices2(vector<string>&v,vector<vector<bool>>&visited, int row, int col, int&res, int color){
    vector<vector<bool>>vst(visited.size(), vector<bool>(visited[0].size(),false));
    vst[row][col]=true;
    visited[row][col]=true;
    queue<pair<int,int>>q;
    q.push({row, col});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        int dx, dy;
        if(v[x][y]=='E'){dx=0;dy=1;}
        if(v[x][y]=='W'){dx=0;dy=-1;}
        if(v[x][y]=='N'){dx=-1;dy=0;}
        if(v[x][y]=='S'){dx=1;dy=0;}
        if(x+dx<0 || x+dx>=visited.size() || y+dy<0 || y+dy>=visited[0].size() || vst[x+dx][y+dy]){
            res++;
            return ;
        }
        if(visited[x+dx][y+dy]) return ;
        q.push({x+dx, y+dy});
        vst[x+dx][y+dy]=true;
        visited[x+dx][y+dy]=true;
    }   // I had TLE as I was init. temp. visited array for each DFS.
}



void coverIndices(vector<string>&v,vector<vector<int>>&visited, int row, int col, int&res, int color){
    visited[row][col]=color;
    queue<pair<int,int>>q;
    q.push({row, col});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        int dx, dy;
        if(v[x][y]=='E'){dx=0;dy=1;}
        if(v[x][y]=='W'){dx=0;dy=-1;}
        if(v[x][y]=='N'){dx=-1;dy=0;}
        if(v[x][y]=='S'){dx=1;dy=0;}
        if(x+dx<0 || x+dx>=visited.size() || y+dy<0 || y+dy>=visited[0].size() || visited[x+dx][y+dy]==color){
            res++;
            return ;
        }
        if(visited[x+dx][y+dy]<color) return ;
        q.push({x+dx, y+dy});
        visited[x+dx][y+dy]=color;
    }
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols;
    cin>>rows>>cols;
    // scanf("%d%d", &rows, &cols);
    vector<string>v(rows, string(cols,'*'));
    string s="";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++) cin>>v[i][j];
    }
    vector<vector<int>>visited(rows, vector<int>(cols,INT_MAX));
    int res=0, color=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(visited[i][j]!=INT_MAX) continue;
            coverIndices(v,visited,i,j, res, color++);
            // cout<<"i: "<<i<<" and j: "<<j<<" and res: "<<res<<endl;
        }
    }
    cout<<res<<endl;
    return 0;
}
