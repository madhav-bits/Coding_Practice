/*

//***************************************************DCEPC706 - Meeting For Party.***************************************************
https://www.spoj.com/problems/DCEPC706/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we find the indices of three people in the question. We start BFS form each of them and mark 
// the distance of each of indices form each person and try to maximize the distance saved in each index, we also mark how many
// people can reach each index by updating the count at each index. After 3 BFS, we iter. over distance matrix and skip those indices
// which have '#'/ which isn't reachable by three people and return the minm. value among values in remaining indices, which gives
// minimum time for all of them to meet.






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

void iterSpace(int row, int col, vector<vector<int>>&v, vector<string>&graph, vector<vector<int>>&reach){
    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
    queue<pair<int,int>>q;
    q.push({row, col});
    visited[row][col]=true;
    reach[row][col]++;
    int dist=0;
    // cout<<"starting iter from row: "<<row<<" and col: "<<col<<endl;
    while(!q.empty()){
        int len=q.size();
        dist++;
        for(int i=0;i<len;i++){
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int dx=dirs[j], dy=dirs[j+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=graph[0].length() || visited[x+dx][y+dy] || graph[x+dx][y+dy]=='#') continue;
                visited[x+dx][y+dy]=true;
                reach[x+dx][y+dy]++;
                q.push({x+dx, y+dy});
                v[x+dx][y+dy]=max(v[x+dx][y+dy], dist);
            }
        }
    }

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
        int rows, cols;
        cin>>rows>>cols;
        vector<string>v(rows+2);
        v[0]=string(cols+2,'.');
        pair<int,int>p1, p2, p3;
        for(int i=1;i<=rows;i++){
            string s=".", temp="";
            cin>>temp;
            s+=temp+".";
            v[i]=s;  
            // cout<<"temp str: "<<v[i]<<endl;
            for(int j=0;j<v[i].length();j++){
                if(v[i][j]=='1'){
                    p1.first=i;p1.second=j;
                }
                if(v[i][j]=='2'){
                    p2.first=i;p2.second=j;
                }
                if(v[i][j]=='3'){
                    p3.first=i;p3.second=j;
                }
            }
        }
        v.back()=string(cols+2,'.');

        vector<vector<int>>iter(rows+2, vector<int>(v[0].length(),0));
        vector<vector<int>>reach(rows+2, vector<int>(v[0].length(),0));
        iterSpace(p1.first, p1.second, iter, v, reach);
        iterSpace(p2.first, p2.second, iter, v, reach);
        iterSpace(p3.first, p3.second, iter, v, reach);

        int res=INT_MAX;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                // cout<<iter[i][j]<<" ";
                if(v[i][j]=='#' || reach[i][j]!=3) continue;
                res=min(res, iter[i][j]);
            }
            // cout<<endl;
        }
        cout<<res<<endl;
    }    

    return 0;
}