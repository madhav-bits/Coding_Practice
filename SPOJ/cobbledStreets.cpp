/*

//***************************************************CSTREET - Cobbled streets.*****************************************************
https://www.spoj.com/problems/CSTREET/




Time Complexity:O(eloge).                                                   // e is #edges in the graph.                                                                                                                                                                                      
Space Complexity:O(e).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(eloge).                                                // e is #edges in the graph.                           
// Space Complexity:O(e).                                                   
// This is KRUSKAL ALGO IMPLEMENTATION WITH UNION FIND BY RANK AND PATH COMPRESSION TECHNIQUE. This is implementation of classic
// Kruskal algo. using which we gather the minm. length of street that connects all the given buildings, which is multiplied by 
// cost per each furlong and returned.











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
  int cost, src, dest;

  Node(int x, int y, int z){
    cost=x;
    src=y;
    dest=z;
  }

};




struct comp{

  bool operator()(Node* &lt, Node* &rt){
    return lt->cost<rt->cost;
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
    parent=0;
    rank=0;
  }

};


int findParent(vector<Subset>&subsets, int node){                           // Performing Path compression while querying for parent.
  if(subsets[node].parent!=node)
    subsets[node].parent=findParent(subsets, subsets[node].parent);
  return subsets[node].parent;
}




int kruskalAlgo(vector<Node*>&edges, int nodes){
  long long int minLen=0;
  int used=0;
  vector<Subset>subsets(nodes+1);
  for(int i=1;i<subsets.size();i++){
    subsets[i]=Subset(i,0);
  }

  for(int i=0;i<edges.size() && used<(nodes-1);i++){
    int node1=edges[i]->src, node2=edges[i]->dest;
    int parX=findParent(subsets, node1);
    int parY=findParent(subsets, node2);
    if(parX==parY) continue;
    used++;
    minLen+=edges[i]->cost;

    if(subsets[parX].rank>subsets[parY].rank)                               // Deciding upon resulting parent while merging using ranks.
      subsets[parY].parent=parX;
    else if(subsets[parY].rank>subsets[parX].rank)
      subsets[parX].parent=parY;
    else{
      subsets[parY].parent=parX;
      subsets[parX].rank++;
    }

  }
  return minLen;
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
      long long int perFurlong;
      cin>>perFurlong;
      int nodes, streets;
      cin>>nodes>>streets;
      vector<Node*>edges(streets,NULL);
      int dist, src, dest;
      for(int i=0;i<streets;i++){
        cin>>src>>dest>>dist;
        edges[i]=new Node(dist, src, dest);
      }
      sort(edges.begin(), edges.end(), comp());
      // for(auto it=edges.begin();it!=edges.end();it++)
      //   cout<<"edge: "<<(*it)->cost<<" src: "<<(*it)->src<<" and dest: "<<(*it)->dest<<endl;
      long long int minLength=kruskalAlgo(edges, nodes);
      cout<<minLength*perFurlong<<endl;
    }

    return 0;
}


