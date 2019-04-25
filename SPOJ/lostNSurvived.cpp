/*

//**********************************************LOSTNSURVIVED - Lost and survived.***************************************************
https://www.spoj.com/problems/LOSTNSURVIVED/




Time Complexity:O(mlogm).                                                   // m queries in DSU Data structure.                                                                                                                                                                                             
Space Complexity:O(m+n).                                                    // m- #edges in graph, n-#nodes in graph.

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(mlogm).                                                // m queries in DSU Data structure.      
// Space Complexity:O(m+n).                                                 // m- #edges in graph, n-#nodes in graph.
// This is Union-Find and Priority Queue based solution. Here, we use Union-Find to keep track of groups and their volumes. On
// joining two groups, we check whether if all nodes are joined, if joined return 0, if two nodes two be joined are already of 
// same group, we return prev. result value. On joining two groups, we remove minHeap, maxHeap top elements which don't actually
// represent their current state. We push updated group with {size, node of group} into both heaps, now we can be certain that the
// top elements would be actually representing their curr. states, we return maxHeap top element-minHeap top element.







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







struct comp{                                                                // Implements Min. Heap.
    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first>rt.first;
    }
};





struct comp2{                                                               // Implements Max. Heap.
    bool operator()(pair<int,int>&lt, pair<int,int>&rt){
        return lt.first<rt.first;
    }
};





int getParent(vector<int>&parent, int node){
    if(parent[node]!=node)
        parent[node]=getParent(parent, parent[node]);
    return parent[node];
}




int joinGroups(vector<int>&parent, vector<int>&vols, int node1, int node2){
    int parA=getParent(parent, node1);
    if(vols[parA]==(parent.size()-1)) return 0;
    int parB=getParent(parent, node2);
    if(parA==parB) return -1;
    if(parA<parB){
        parent[parB]=parA;
        vols[parA]+=vols[parB];
        return vols[parA];
    }else{
        parent[parA]=parB;
        vols[parB]+=vols[parA];
        return vols[parB];
    }
    return 1;
}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nodes, queries;
    cin>>nodes>>queries;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp>minHeap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp2>maxHeap;
    vector<int>parent(nodes+1,0), vols(nodes+1,0);
    for(int i=1;i<=nodes;i++){
        minHeap.push({1,i});
        maxHeap.push({1,i});
        parent[i]=i;
        vols[i]=1;
    }

    int node1, node2, prev=0;
    for(int a=1;a<=queries;a++){
        cin>>node1>>node2;
        int res=joinGroups(parent, vols, node1, node2);
        if(res==0) cout<<0<<endl;                                           // Entire graph is connected.
        else if(res==-1) cout<<prev<<endl;                                  // Two nodes are already connected.
        else{                                                               // Removing top elements which contains old state values.
            while(!minHeap.empty() && vols[getParent(parent, minHeap.top().second)]!=minHeap.top().first) minHeap.pop();
            while(!maxHeap.empty() && vols[getParent(parent, maxHeap.top().second)]!=maxHeap.top().first) maxHeap.pop();
            minHeap.push({res,node1});                                      // Pushing latest state of groups into heaps.
            maxHeap.push({res,node1});
            cout<<maxHeap.top().first-minHeap.top().first<<endl;            // Returning size diff. b/w largest and smallest group.
            prev=maxHeap.top().first-minHeap.top().first;
        }
    }

    return 0;
}
