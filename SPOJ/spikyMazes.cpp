/*

//*****************************************************SPIKES - Spiky Mazes.*********************************************************
https://www.spoj.com/problems/SPIKES/




Time Complexity:O(4^(m*n)).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(4^(m*n)).                                                  
// Space Complexity:O(m*n).                                                   
// This is DFS/BFS based solution. Here, we want to reach any treasure('x') from any of the sources with #spikes being <=limit/2, since
// he has to travel back to source indices. So, we here mark each index with min. #spikes b/w that index and any of the origin indices,
// since we aren't using priority queue, we are allowing few redundant iterations to take place(An index with updated with lower 
// cost when that index is already present in the queue). We also make sure that at any instant, the #skips are<=limit/2.


// This is quite a good problem on DFS.








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





bool canReach(vector<vector<char>>&graph, vector<vector<int>>&skips, int limit, queue<pair<int,int>>&q){
    int jumps=0;
    // vector<vector<int>>skips(graph.size(), vector<int>(graph[0].size(), INT_MAX));

    vector<int>dirs({-1,0,1,0,-1});
    // queue<pair<int,int>>q;
    // q.push({srcRow, srcCol});
    // skips[srcRow][srcCol]=0;
    // cout<<"row: "<<srcRow<<" and col: "<<srcCol<<endl;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(x+dx<0 || y+dy<0 || x+dx>=graph.size() || y+dy>=graph[0].size() || graph[x+dx][y+dy]=='#') continue;
            
            if( (graph[x+dx][y+dy]!='s' && skips[x+dx][y+dy]>skips[x][y]) || (graph[x+dx][y+dy]=='s' && skips[x+dx][y+dy]>skips[x][y]+1  && skips[x][y]+1<=limit/2)){ //graph[x+dx][y+dy]=='.' || 
                q.push({x+dx, y+dy});
                if(graph[x+dx][y+dy]=='s')
                    skips[x+dx][y+dy]=skips[x][y]+1;
                else skips[x+dx][y+dy]=skips[x][y];
            }
            if(graph[x+dx][y+dy]=='x') return true;
        }
        // while(!q.empty() && skips[q.front().first][q.front().second])
    }
    return false;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols, limit;
    cin>>rows>>cols>>limit;
    vector<vector<char>>graph(rows, vector<char>(cols,'.'));
    vector<vector<int>>skips(graph.size(), vector<int>(graph[0].size(), INT_MAX));
    queue<pair<int,int>>q;
    int srcRow=-1, srcCol=-1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='@'){
                // cout<<"srcRow: "<<i<<" and srcCol: "<<j<<endl;
                q.push({i,j});
                skips[i][j]=0;
            }
        }   
    }
    bool res=canReach(graph, skips, limit, q);
    if(res) cout<<"SUCCESS"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
