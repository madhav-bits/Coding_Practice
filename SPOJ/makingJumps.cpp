/*

//****************************************************MKJUMPS - Making Jumps.********************************************************
https://www.spoj.com/problems/MKJUMPS/




Time Complexity:O(8^m*n).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(8^m*n).                                                  
// Space Complexity:O(m*n).                                                   
// This is Backtracking based problem. Here, we to find the path that covers the maxm. indices on the board. We perform Backtracking
// at every step, of all the possible steps to take, we choose the path that leads to maxm. indices being covered. We set the 
// visited indices to invalid, to prevent reaching same index once again in the path.After backtracking, we return total valid 
// indices-max. reachable indices in a single path.









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



vector<vector<int>>dirs;


int backTrack(vector<vector<bool>>&valid, int x, int y){
    valid[x][y]=false;
    // cout<<"x: "<<x<<" and y: "<<y<<endl;
    int res=1;
    for(int i=0;i<8;i++){
        int dx=dirs[i][0], dy=dirs[i][1];
        if(x+dx<0 || y+dy<0 || x+dx>=valid.size() || y+dy>=10 || valid[x+dx][y+dy]==false) continue;
        int val=backTrack(valid, x+dx, y+dy);
        res=max(res, 1+val);
    }
    valid[x][y]=true;
    // cout<<"x: "<<x<<" and y: "<<y<<" and res; "<<res<<endl;
    return res;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    dirs=vector<vector<int>>({{-2,-1},{-2,1},{-1,-2},{-1,2},{1, -2},{1,2},{2,-1},{2,1}});
    int tests=0;
    int rows, cols;
    cin>>rows;
    while(rows!=0){
        vector<vector<bool>>valid(rows, vector<bool>(10, false));
        bool set=false;
        int row, col;
        int offset, seq;
        tests++;
        int total=0;
        // cout<<"rows; "<<rows<<endl;
        for(int i=0;i<rows;i++){
            cin>>offset>>seq;
            // cout<<"offset; "<<offset<<" and seq: "<<seq<<endl;
            total+=seq;
            for(int j=0;j<seq;j++){
                if(i==0 && !set){
                    row=i;col=offset;
                    set=true;
                }
                valid[i][j+offset]=true;
            }
        }

        // for(int c=0;c<rows;c++){
        //     for(int d=0;d<10;d++)
        //         cout<<valid[c][d]<<" ";
        //     cout<<endl;
        // }
        // cout<<"Total: "<<total<<endl;
        int reached=0;
        if(set) reached=backTrack(valid, row, col);
        cout<<"Case "<<tests<<", "<<total-reached<<" square";
        if(total-reached!=1) cout<<"s";
        cout<<" can not be reached."<<endl; 
        cin>>rows;
    }

    return 0;
}