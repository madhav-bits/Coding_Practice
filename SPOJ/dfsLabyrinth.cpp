/*

//**********************************************************LABYR1 - Labyrinth.**************************************************************
https://www.spoj.com/problems/LABYR1/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   // O(1) can be achieved by modifying visited indices and reverting them back at the end of recursive call.                                                   
// This is DFS based solution. HEre, since there is only one path from one node to another, this graph can be thought of as a tree. The
// problem gets converted to Maximum length of path between nodes. So, here we extract max. dist travelled from each adj. node and add 
// with max. dist. obtained from curr. adj. node(These two adj. nodes would form a path via curr. node), and update the final max. path
// dist with this sum and also we update max. adj. path and after giving recursive calls from all adj. nodes, we return max. adj. depth. 










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






int getLen(vector<vector<char>>&v, vector<vector<bool>>&visited, int row, int col, int&res){

    // cout<<"rows: "<<row<<" and cols: "<<col<<endl;
    vector<int>dirs({-1,0,1,0,-1});
    visited[row][col]=true;
    int tempMax=0;
    for(int i=0;i<4;i++){
        int dx=dirs[i], dy=dirs[i+1];
        if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || v[row+dx][col+dy]=='#' || visited[row+dx][col+dy]==true) continue;
        int len=getLen(v,visited,row+dx,col+dy,res);
        res=max(res,len+1+tempMax);
        tempMax=max(tempMax,len+1);
    }
    return tempMax;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
        int row,col;
        cin>>col>>row;
        // cout<<"rows: "<<row<<" and cols: "<<col<<endl;
        vector<vector<char>>graph(row,vector<char>(col,'#'));
        int blocks=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>graph[i][j];
            }
        }

        int res=0;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(graph[i][j]=='.' && visited[i][j]==false){
                    // cout<<"start from row: "<<i<<" and col: "<<j<<endl;
                    getLen(graph,visited,i,j,res);
                }
            }
        }
        cout<<"Maximum rope length is "<<res<<"."<<endl;
    }

    return 0;
}