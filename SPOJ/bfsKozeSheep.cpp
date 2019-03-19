/*

//*********************************************************KOZE - Sheep.*************************************************************
https://www.spoj.com/problems/KOZE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we iter. over each unvisited index and mrak all indices which are reachable from this index(Indices)
// of curr. sector and keep a count of curr. sector's wolves and sheeps and we also check whether current sector is bounded or not? If
// unbounded, as all animals can leave we inc. the count of sheep, wolves. If the sector is close, we inc. the count of spieces which
// greater head count.






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




bool getCount(vector<vector<char>>&v, vector<vector<bool>>&visited, int row, int col, int &sheep, int &wolf){
    // cout<<"start row: "<<row<<" and col: "<<col<<endl;
    bool open=false;
    // if(row==0 || row==v.size()-1 || col==0 || col==v[0].size()-1) open=true;
    queue<pair<int,int>>q;
    q.push({row, col});
    if(v[row][col]=='k') sheep++;
    else if(v[row][col]=='v') wolf++;
    visited[row][col]=true;
    vector<int>dirs({-1,0,1,0,-1});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size()){
                open=true;
                continue;
            }
            if(v[x+dx][y+dy]=='#' || visited[x+dx][y+dy]) continue;
            visited[x+dx][y+dy]=true;
            if(v[x+dx][y+dy]=='k') sheep++;
            else if(v[x+dx][y+dy]=='v') wolf++;
            q.push({x+dx,y+dy});
        }
    }
    return open;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols;
    cin>>rows>>cols;
    vector<vector<char>>v(rows, vector<char>(cols,'.'));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>v[i][j];
            // cout<<v[i][j];
        }
        // cout<<endl;
    }
    vector<vector<bool>>visited(rows, vector<bool>(cols, false));
    int resSheep=0, resWolf=0;
    int sheep=0, wolf=0;
    bool open=false;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(v[i][j]=='#' || visited[i][j]) continue;
            sheep=0; wolf=0;
            open=getCount(v,visited,i,j, sheep, wolf);
            // cout<<"sheep: "<<sheep<<" and wolf: "<<wolf<<endl;
            
            // if(!open){
            //     if(sheep>wolf) resSheep+=sheep;
            //     else resWolf+=wolf;
            // }else{
            //     resSheep+=sheep;
            //     resWolf+=wolf;
            // }
            if(open || sheep>wolf) resSheep+=sheep;
            if(open || wolf>=sheep) resWolf+=wolf;
        }
    }
    cout<<resSheep<<" "<<resWolf<<endl;

    return 0;
}
