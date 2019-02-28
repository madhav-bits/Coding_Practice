/*

//************************************************BLINNET - Bytelandian Blingors Network.********************************************
https://www.spoj.com/problems/BLINNET/




Time Complexity:O(eloge + e*nodes)=e*nodes.                              // e-edges, n-nodes in the graph.                                                                                                                                                                                          
Space Complexity:O(e).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(eloge + e*nodes)=e*nodes.                              // e-edges, n-nodes in the graph.                                                  
// Space Complexity:O(e).                                                   
// This is KRUSKAL'S ALGORITHM IMPLEMENTED USING UNION-FIND TECHNIQUE.Here, we first gather all edges, sort them based on their 
// values, we iterate from least to highest valued edges, we accept only whose nodes are not part of same group when we reach that 
// edge in the iteration. Thus, in order to link any two nodes, we are making use of least possible edge value. Thus, getting
// minm. cost while joining all the nodes in the graph.







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
    int dist;
    int src, dest;

    Node(int x, int y, int z){
        dist=x;
        src=y;
        dest=z;
    }

};


struct comp{
    bool operator()(Node* &lt, Node* &rt){
        return lt->dist<rt->dist;
    }
};



int findParent(vector<int>&parent, int node){
    while(parent[node]!=node) 
        node=parent[node];
    return node;
}


int kruskalAlgo(vector<Node*>&edges, int nodes){
    vector<int>parent(nodes+1,0);
    for(int i=1;i<=nodes;i++) parent[i]=i;
    int used=0, cost=0;
    for(int i=0;i<edges.size() && used<(nodes-1) ;i++){
        int node1=edges[i]->src, node2=edges[i]->dest;
        int parX=findParent(parent, node1);
        int parY=findParent(parent, node2);
        if(parX==parY) continue;                                            // Skipping joining nodes which are already connected.
        used++;
        cost+=edges[i]->dist;
        parent[parY]=parX;
    }
    return cost;
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
        int cities;

        cin>>cities;
        vector<Node*>edges;
        for(int i=1;i<=cities;i++){
            string city="";
            cin>>city;
            int neigh;
            cin>>neigh;
            int fol, dist;
            for(int j=0;j<neigh;j++){
                cin>>fol>>dist;
                if(fol<i) continue ;
                edges.push_back(new Node(dist,i,fol));    
            }
            
        }
        sort(edges.begin(), edges.end(), comp());
        // for(auto it:edges){
        //     cout<<"dist: "<<it->dist<<" and src; "<<it->src<<" and dest: "<<it->dest<<endl;
        // }
        int cost=kruskalAlgo(edges,cities);        
        cout<<cost<<endl;
    }

    return 0;
}