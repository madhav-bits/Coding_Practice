/*

//*************************************************MST - Minimum Spanning Tree.****************************************************
https://www.spoj.com/problems/MST/




Time Complexity:O(eloge).                                                   // e-edges, n-nodes in the graph.                                                                                                                                                                                         
Space Complexity:O(e).                                                      

*/


//*********************************************************Solution 1.***********************************************************
//***************************THIS SOLUTION IS GOOD EXAMPLE OF USING UNION-FIND BY RANK AND PATH COMPRESSION.*********************
// Time Complexity:O(eloge)                                                 // e-edges, n-nodes in the graph.                                                  
// Space Complexity:O(e).                                                   
// This is KRUSKAL'S ALGORITHM IMPLEMENTED USING UNION-FIND BY RANK AND PATH COMPRESSION TECHNIQUE.Here, we first gather all 
// edges, sort them based on their values, we iterate from least to highest valued edges, we accept only whose nodes are not part 
// of same group when we reach that edge in the iteration. Thus, in order to link any two nodes, we are making use of least 
// possible edge value. Thus, we get minm. cost while joining all the nodes in the graph.

// There are some efficiency issues according to SPOJ, for me this is the best Kruskal Algo. I can come up with. May be it can be
// solved easily with Prim's Algorithm.


// This algorithm: UNION-FIND BY RANK AND PATH COMPRESSION is explained in this link:
// https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/








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
    int start;
    int close;
    int dist;

    Node(int x, int y,int z){
        start=x;
        close=y;
        dist=z;
    }
};



struct comp{
    bool operator()(Node &lt, Node &rt){
        return lt.dist<rt.dist;
    }
};



int getParent(vector<int>&parent, int node){
    if(parent[node]!=node)
        parent[node]=getParent(parent, parent[node]);
    return parent[node];
}


long long int kruskalAlgo(vector<Node>&v, vector<int>&parent, vector<int>&rank, int nodes){
    int used=0;
    int res=0;
    for(int i=0;i<v.size() && used<nodes-1;i++){
        int node1=v[i].start, node2=v[i].close;
        int parL=getParent(parent, node1);
        int parR=getParent(parent, node2);
        if(parL==parR) continue;
        used++;
        res+=v[i].dist;
        if(rank[parL]>rank[parR]){
            parent[parR]=parL;
        }else if(rank[parR]>rank[parL]){
            parent[parL]=parR;
        }else{
            parent[parR]=parL;
            rank[parL]++;    
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

    int nodes, edges;
    // cin>>nodes>>edges;
    scanf("%d%d", &nodes,&edges);
    vector<int>parent(nodes+1,0),rank(nodes+1,0);
    for(int i=1;i<=nodes;i++) parent[i]=i;
    vector<Node>v;
    int node1, node2, gap;
    for(int a=0;a<edges;a++){
        // cin>>node1>>node2>>gap;
        scanf("%d%d%d", &node1, &node2, &gap);
        v.push_back(Node(node1, node2, gap));
    }
    sort(v.begin(), v.end(), comp());
    long long int res=kruskalAlgo(v,parent,rank, nodes);
    cout<<res<<endl;
    return 0;
}
