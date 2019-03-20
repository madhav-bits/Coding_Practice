/*

//************************************************ALCATRAZ3 - THE HONEYCOMB MAZE.****************************************************
https://www.spoj.com/problems/ALCATRAZ3/




Time Complexity:O(3^m*n).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(3^m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is DFS based solution. We start travelling from start index and travel in 4 drns depth wise. We also keep track of distance 
// travelled in DFS. We mark the indices to make sure we won't revisit once again. If we visit the start index after taking >=k steps,
// we return true. If we are not able to reach start index once again, or able to reach it with lesser disance than that of target
// distance, we ingore.









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




bool dfs(vector<vector<char>>&v, int sRow, int sCol, int x, int y, int steps){
    v[x][y]='*';
    vector<int>dirs({-1,0,1,0,-1});
    for(int i=0;i<4;i++){
        int dx=dirs[i], dy=dirs[i+1];
        if(x+dx<0 || x+dx>=v.size() || y+dy<0 || y+dy>=v[0].size()) continue;
        if(steps<=1 && x+dx==sRow && y+dy==sCol) return true;
        if(v[x+dx][y+dy]=='*') continue;
        if(dfs(v,sRow, sCol, x+dx, y+dy, steps-1)) return true;
    }
    v[x][y]='.';
    return false;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols, steps, row, col;
    cin>>rows>>cols>>steps>>row>>col;
    vector<vector<char>>v(rows,vector<char>(cols,'.'));
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>v[i][j];
        }
    }

    bool res=dfs(v,row-1, col-1, row-1, col-1, steps);
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;    

    return 0;
}
