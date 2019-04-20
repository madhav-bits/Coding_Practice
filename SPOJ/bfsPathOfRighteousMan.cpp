/*

//*********************************************RIOI_2_3 - Path of the righteous man.*************************************************
https://www.spoj.com/problems/RIOI_2_3/




Time Complexity:O(m*n*2^k).                                                 // k- #apologies allowed.                                                                                                                                                                                         
Space Complexity:O(m*n*2^k).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n*2^k).                                              // k- #apologies allowed. 
// Space Complexity:O(m*n*2^k).                                                   
// This is BFS+Bitmasking based solution. Here, we start from the starting point, for each move we track whethter next index had been
// visited with same list of apologies made(tracked using bitmasks). If we revisit a index, which had been already visited with same
// pattern of apologies, we skip visiting that index. We also skip/don't push that step into queue in case we reach dest. index(As, 
// any later moves would be increase apologies to reach dest. index once again). If overlap curr. mask and (1<<val. of next index) to 
// get apologies sequence for next index. There are different sequences to reach dest. index, we return path with minm. #apologies.



// So, for each index, we have (2^10)->[0,1023] states.







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



struct Node{
    int row;
    int col;
    int apologies;
    int mask;

    Node(int row, int col, int apologies, int mask){
        this->row=row;
        this->col=col;
        this->apologies=apologies;
        this->mask=mask;
    }
};



// struct comp{

//     bool operator()(Node&lt, Node& rt){                                     // Return Nodes with least apologies.
//         return lt.apologies>rt.apologies;               
//     }
// };


int travel(int startX, int startY, int closeX, int closeY, vector<vector<int>>&graph){
    if(startX==closeX && startY==closeY) return 1;
    vector<vector<vector<bool>>>visited(graph.size(), vector<vector<bool>>(graph.size(), vector<bool>(1024, false)));
    vector<int>dirs({-1,0,1,0,-1});
    // priority_queue<Node, vector<Node>, comp>pq;
    queue<Node>pq;
    Node src= Node(startX, startY,1,(1<<graph[startX][startY]));
    visited[startX][startY][(1<<graph[startX][startY])]=true;
    int res=INT_MAX;
    pq.push(src);
    while(!pq.empty()){
        Node curr=pq.front();
        // cout<<"row: "<<curr.row<<" and col: "<<curr.col<<" and apologies: "<<curr.apologies<<endl;
        pq.pop();
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            int mask=curr.mask, row=curr.row, col=curr.col;
            if(row+dx<0 || row+dx>=graph.size() || col+dy<0 || col+dy>=graph[0].size()) continue;
            int newMask=mask |(1<< graph[row+dx][col+dy]);
            if(visited[row+dx][col+dy][newMask]==true) continue;

            visited[row+dx][col+dy][newMask]=true;
            if((mask & (1<< graph[row+dx][col+dy]))==0){
                if(row+dx==closeX && col+dy==closeY) res=min(res, curr.apologies+1);
                else pq.push(Node(row+dx, col+dy, curr.apologies+1, newMask));
            }else{
                if(row+dx==closeX && col+dy==closeY) res=min(res, curr.apologies);
                else pq.push(Node(row+dx, col+dy, curr.apologies, newMask));
            }
        }
    }
    return res;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, width, startX, startY, closeX, closeY;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>width;
        vector<vector<int>>graph(width, vector<int>(width,0));
        for(int i=0;i<width;i++){
            for(int j=0;j<width;j++){
                cin>>graph[i][j];
            }
        }
        cin>>startX>>startY>>closeX>>closeY;
        int apologies=travel(startX, startY, closeX, closeY, graph);
        cout<<apologies<<endl;
    }

    return 0;
}
