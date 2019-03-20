/*

//*************************************************UOFTCE - A Brief Expedition.*****************************************************
https://www.spoj.com/problems/UOFTCE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we start our iter. from start and cover indices in the path, and calculate smallest dist. to all
// shops in the process. Since, we can skip the time to travel to one shop, we first travel to shop of longest distance. So, we calculate
// #shops, #maxm. distance to a shop, sum of distances of all shops. We, add (60*shops) to total sum and substract longest distance 
// to a shop to get the final result.







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





long long int getSum(vector<vector<char>>&v, int sRow, int sCol){
    // cout<<"start row: "<<sRow<<" and col: "<<sCol<<endl;
    long long int shops=0;
    long long int maxm=INT_MIN;
    vector<int>dirs({-1,0,1,0,-1});
    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(),false));
    visited[sRow][sCol]=true;
    queue<pair<int,int>>q;
    q.push({sRow, sCol});
    long long int dist=0, res=0;
    while(!q.empty()){
        int len=q.size();
        dist++;
        for(int a=0;a<len;a++){
            int x=q.front().first, y=q.front().second;
            // cout<<"row: "<<x<<" and col: "<<y<<endl;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size() || visited[x+dx][y+dy] || v[x+dx][y+dy]=='#') continue;
                visited[x+dx][y+dy]=true;
                if(v[x+dx][y+dy]=='S'){
                    shops++;
                    maxm=max(maxm, dist);
                    res+=2*dist;
                }
                q.push({x+dx, y+dy});
            } 
        }     
    }
    res+=-maxm+(60*shops);
    return res;
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    int rows, cols;
    for(int a=0;a<tests;a++){
        cin>>rows>>cols;
        vector<vector<char>>v(rows, vector<char>(cols,'.'));
        int sRow, sCol;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>v[i][j];
                if(v[i][j]=='C'){
                    sRow=i;
                    sCol=j;
                }
                // cout<<v[i][j];
            }
            // cout<<endl;
        }

        long long int res=getSum(v, sRow, sCol);
        cout<<res<<endl;
    }
    

    return 0;
}
