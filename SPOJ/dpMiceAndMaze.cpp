/*

//*******************************************************MICEMAZE - Mice and Maze.*******************************************************
https://www.spoj.com/problems/MICEMAZE/




Time Complexity:O(n^3).                                                                                                                                                                                             
Space Complexity:O(n^2).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^3).                                                  
// Space Complexity:O(n^2).                                                   
// This algorithm is Floyd Warshall based algorithm. Here, we form a adjacency matrix b/w nodes. At each step, we calc. min. dsit b/w
// two nodes via mediating node, we iter. over all nodes by making them as mediating nodes and calc. min. dist b/w pair of nodes. At the
// end of iteration, we have min. dist all pairs of nodes with all nodes as mediating nodes(Any nodes can be mediating nodes). We iter. 
// the matrix, we iter. indices exit is the target index, of all those indices we count #indices whose value<=timer and return the count.






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





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nodes, exit, timer,edges;
    cin>>nodes>>exit>>timer>>edges;
    vector<vector<long long int>>dp(nodes+1, vector<long long int>(nodes+1, INT_MAX));
    for(int i=1;i<=nodes;i++) dp[i][i]=0;
    for(int a=0;a<edges;a++){
        int in, out, dist;
        cin>>in>>out>>dist;
        dp[in][out]=dist;
    }

    bool cont=true;
    for(int k=1;k<=nodes;k++){
        for(int i=1;i<=nodes;i++){
            for(int j=1;j<=nodes;j++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    int res=0;
    for(int i=1;i<=nodes;i++){
        // cout<<"i: "<<i<<" and dist: "<<dp[i][exit]<<endl;
        if(dp[i][exit]<=timer) res++;
    }
    cout<<res<<endl;

    return 0;
}


















//***********************************************************Solution 2.*************************************************************
// Time Complexity:O(n^3).                                                  
// Space Complexity:O(n^2).         
// This algorithm is Dijkstra based algorithm. Since, here we need smallest dist. from all nodes to one node, we inverse the nodes and 
// translate the question as smallest dist. from one node to all nodes, which is Dijkstra's algo.











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





struct comp{
    bool operator()(pair<int, long long int>&lt, pair<int, long long int>&rt){
        return lt.second>rt.second;
    }
};




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nodes, exit, timer,edges;
    cin>>nodes>>exit>>timer>>edges;
    vector<vector<int>>dp(nodes+1, vector<int>(nodes+1, INT_MAX));          // Adjacency Matrix.
    for(int i=1;i<=nodes;i++) dp[i][i]=0;
    for(int a=0;a<edges;a++){
        int in, out, dist;
        cin>>in>>out>>dist;
        dp[out][in]=dist;                                                   // Reversing the edge to translate qsn to Dijkstra's.
    }

    priority_queue<pair<int,long long int>, vector<pair<int, long long int>>, comp>pq;
    pq.push({exit,0});
    vector<bool>visited(nodes+1, false);
    int res=0;

    while(!pq.empty()){
        pair<int,int>curr=pq.top();
        int node=curr.first;
        long long int dist=curr.second;
        // cout<<"curr. node: "<<node<<" and dist: "<<dist<<endl;
        res++;
        visited[node]=true;
        pq.pop();
        for(int adj=1;adj<=nodes;adj++){
            // cout<<"adj: "<<adj<<endl;
            if(dp[node][adj]==INT_MAX || visited[adj]==true || dist+dp[node][adj]>timer) continue;
            pq.push({adj, dist+dp[node][adj]});
        }
        while(!pq.empty() && visited[pq.top().first]==true) pq.pop();

    }
    cout<<res<<endl;

    return 0;
}