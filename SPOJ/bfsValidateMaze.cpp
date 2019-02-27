/*

//*************************************************MAKEMAZE - VALIDATE THE MAZE.*****************************************************
https://www.spoj.com/problems/MAKEMAZE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we scan the given strings and get the count of conrer indices and also push two of them into
// vector. If the #corner indices>2, print "invalid" else we validate the maze by doing an BFS from the start index, till we reach the
// dest/other corner index or all reachable '.'s from source are visited. If we visite dest. index we print "valid" else "invalid".









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

bool validate(vector<string>&v, vector<vector<bool>>&visited, pair<int,int>&start, pair<int,int>&close){
  visited[start.first][start.second]=true;
  queue<pair<int,int>>q;
  q.push(start);
  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int dx=dirs[i], dy=dirs[i+1];
      if(x+dx<0 || y+dy<0 || x+dx>=v.size() || y+dy>=v[0].size() || v[x+dx][y+dy]=='#' || visited[x+dx][y+dy]) continue;
      q.push({x+dx, y+dy});
      if(close==make_pair(x+dx,y+dy)) return true;
      visited[x+dx][y+dy]=true;
    }

  }
  return false;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    dirs=vector<int>({-1,0,1,0,-1});
    int rows, cols;
    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
      cin>>rows>>cols;
      vector<string>v(rows);
      vector<vector<bool>>visited(rows,vector<bool>(cols, false));
      vector<pair<int,int>>starts;
      int corners=0;
      for(int i=0;i<rows;i++){
         cin>>v[i];
         for(int j=0;j<v[i].length();j++){
          if((i==0 || i==rows-1) && v[i][j]=='.'){
            corners++;
            starts.push_back({i,j});
          }else if((j==0 || j==cols-1) && v[i][j]=='.'){
            corners++;
            starts.push_back({i,j});
          }
         }
      }
      if(corners!=2){
        cout<<"invalid"<<endl;
        continue;
      }
      if(validate(v,visited,starts[0], starts[1])) cout<<"valid"<<endl;
      else cout<<"invalid"<<endl;

    }

    return 0;
}