/*

//*******************************************************UCV2013H - Slick.***********************************************************
https://www.spoj.com/problems/UCV2013H/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   // Assuming getting areas from map won't be larges time complexity wise.                                     
// This is BFS/DFS based solution. Here, we iterate over given array and whenever we find an spill index, we start BFS from there
// and mark all indices part of that spill and also measure the area of the spill in BFS. We mark them, so that same spill won't be
// revisited. We push the spill's area into a map, we also keep track of #spills with same area using map. This way we iterate over 
// entire array covering all spills and pushing their areas and it's occurance into map. At the end of iteration, we print the 
// #spills, we iter. over map, that is from smallest to largest area of the spills, we print the area and #spills with that area.









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
#include<map>



using namespace std;






vector<int>dirs;

int markSpill(vector<vector<int>>&graph, int row, int col, vector<vector<bool>>&visited){
    int area=1;
    queue<pair<int,int>>q;
    q.push({row, col});
    visited[row][col]=true;
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(x+dx<0 || y+dy<0 || x+dx>=graph.size() || y+dy>=graph[0].size() || visited[x+dx][y+dy] || graph[x+dx][y+dy]==0) continue;
            visited[x+dx][y+dy]=true;
            q.push({x+dx, y+dy});
            area++;
        }
    }
    return area;
}








int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    dirs=vector<int>({-1,0,1,0,-1});
    int rows, cols;
    cin>>rows>>cols;
    while(rows!=0 || cols!=0){
        vector<vector<int>>graph(rows, vector<int>(cols,0));
        vector<vector<bool>>visited(rows, vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>graph[i][j];
            }
        }

        map<int,int>m;
        int total=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(graph[i][j]==0 || visited[i][j]) continue;
                total++;
                int area=markSpill(graph,i,j, visited);
                m[area]++;
            }
        }
        cout<<total<<endl;
        for(auto it=m.begin();it!=m.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
        cin>>rows>>cols;
    }

    return 0;
}