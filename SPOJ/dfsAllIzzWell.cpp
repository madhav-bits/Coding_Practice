/*

//*******************************************************ALLIZWEL - ALL IZZ WELL.***********************************************************
https://www.spoj.com/problems/ALLIZWEL/




Time Complexity:O(4^(m+n)).                                                 // Not exactly true, but will be powers of (m+n).                                                                                                                                                                                       
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(4^(m+n)).                                               // Not exactly true, but will be powers of (m+n).   
// Space Complexity:O(m*n).                                                   
// This is DFS based solution. We start DFS the moment we find the start char of "ALLIZZWELL", we mark it as visited to avoid revistiting
// we do DFS in 8 drns looking for next indices, the instant we reach all chars in target string, we return true, if we are not able to 
// find total string after all DFS calls, we return false.






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


vector<vector<int>>dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool findStr(vector<vector<char>>&v, int row, int col, string&target, int index, vector<vector<bool>>&visited){
    if(index==target.length()-1) return true;


    visited[row][col]=true;
    for(int i=0;i<8;i++){
        int dx=dirs[i][0], dy=dirs[i][1];
        if(row+dx<0 || row+dx>=v.size() || col+dy<0 || col+dy>=v[0].size() || visited[row+dx][col+dy]==true || v[row+dx][col+dy]!=target[index+1]) continue;
        if(findStr(v,row+dx,col+dy, target, index+1, visited)) return true;
    }

    visited[row][col]=false;
    return false;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;
    
    string target="ALLIZZWELL";
    for(int a=0;a<tests;a++){
        int rows,cols;
        cin>>rows>>cols;
        // cout<<"rows: "<<rows<<" and cols; "<<cols<<endl;
        vector<vector<char>>v(rows,vector<char>(cols,'.'));
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>v[i][j];
            }
        }

        bool found=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(v[i][j]=='A' && findStr(v, i, j,target,  0, visited)){
                    cout<<"YES"<<endl;
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) cout<<"NO"<<endl;
        cin.ignore();
    }

    return 0;
}