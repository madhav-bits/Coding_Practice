/*

//************************************************BLINNET - Bytelandian Blingors Network.********************************************
https://www.spoj.com/problems/BLINNET/




Time Complexity:O(eloge)                                                    // e-edges, n-nodes in the graph.                                                                                                                                                                                          
Space Complexity:O(e).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(eloge)                                                 // e-edges, n-nodes in the graph.                                                  
// Space Complexity:O(e).                                                   
// This is KRUSKAL'S ALGORITHM IMPLEMENTED USING UNION-FIND BY RANK AND PATH COMPRESSION TECHNIQUE.Here, we first gather all 
// edges, sort them based on their values, we iterate from least to highest valued edges, we accept only whose nodes are not part 
// of same group when we reach that edge in the iteration. Thus, in order to link any two nodes, we are making use of least 
// possible edge value. Thus, we get minm. cost while joining all the nodes in the graph.




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
    int dist;
    int src, dest;

    Node(int x, int y, int z){
        dist=x;
        src=y;
        dest=z;
    }

};


struct Subset{
    int parent;
    int rank;

    Subset(int x, int y){
        parent=x;
        rank=y;
    }

    Subset(){
        parent=0;rank=0;
    }

};






struct comp{
    bool operator()(Node* &lt, Node* &rt){
        return lt->dist<rt->dist;
    }
};



int findParent(vector<Subset>&subsets, int node){
    if(subsets[node].parent!=node)
        subsets[node].parent=findParent(subsets, subsets[node].parent);
        
    return subsets[node].parent;
}


int kruskalAlgo(vector<Node*>&edges, int nodes){
    vector<Subset>subsets(nodes+1);
    for(int i=1;i<=nodes;i++){
        subsets[i]=Subset(i,0);    
    } 

    int used=0, cost=0;
    for(int i=0;i<edges.size() && used<(nodes-1) ;i++){
        int node1=edges[i]->src, node2=edges[i]->dest;
        int parX=findParent(subsets, node1);
        int parY=findParent(subsets, node2);
        if(parX==parY) continue;                                            // Skipping joining nodes which are already connected.
        used++;
        cost+=edges[i]->dist;

        if(subsets[parX].rank>subsets[parY].rank)                           // Making parX as the parent of parY(Larger rank).
            subsets[parY].parent=parX;
        else if(subsets[parY].rank>subsets[parX].rank)                     // Making parY as the parent of parX(Larger rank).
            subsets[parX].parent=parY;
        else{
            subsets[parY].parent=parX;
            subsets[parX].rank++;
        } 
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