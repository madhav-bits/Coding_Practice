/*

//***************************************************NATALIAG - Natalia Plays a Game.*********************************************************
https://www.spoj.com/problems/NATALIAG/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, we start our BFS iter. from start index to end index and marking visited indices along the way.
// So, that we won't reviist those indices. The first time we encounter destIndex, we return dist. travelled till then.







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





int findDist(vector<vector<char>>&v, int startRow, int startCol, int destRow, int destCol){
    if(startRow==destRow && startCol==destCol) return 0;
    int dist=0;
    vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
    vector<int>dirs({-1,0,1,0,-1});
    queue<pair<int,int>>q;
    q.push({startRow, startCol});
    visited[startRow][startCol]=true;
    while(!q.empty()){
        int len=q.size();
        dist++;
        for(int a=0;a<len;a++){
            int x=q.front().first, y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size() || visited[x+dx][y+dy] || v[x+dx][y+dy]=='*' ) continue;
                if(x+dx==destRow && y+dy==destCol) return dist;
                visited[x+dx][y+dy]=true;
                q.push({x+dx, y+dy});
            } 
        }
          
    }
    return -1;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");


    int tests;
    cin>>tests;
    int rows, cols, startRow, startCol, destRow, destCol;
    for(int a=0;a<tests;a++){
        cin>>rows>>cols;
        vector<vector<char>>v(rows, vector<char>(cols,'.'));

        for(int i=0;i<rows;i++){
            // cin>>v[i];
            // cout<<v[i]<<endl;
            for(int j=0;j<cols;j++){
                cin>>v[i][j];
                if(v[i][j]=='$'){
                    startRow=i;
                    startCol=j;
                }else if(v[i][j]=='#'){
                    destRow=i;
                    destCol=j;
                }
            }
        }
        // if(startRow==destRow && startCol==destCol){
        //     cout<<0<<endl;
        //     continue;
        // }
        // cout<<"sRow: "<<startRow<<" sCOl: "<<startCol<<" dRow: "<<destRow<<" dCol: "<<destCol<<endl;
        int res=findDist(v,startRow, startCol, destRow, destCol);
        cout<<res<<endl;

    }

    return 0;
}
