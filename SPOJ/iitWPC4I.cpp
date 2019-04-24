/*

//*********************************************IITWPC4I - Petya and the Road Repairs*************************************************
https://www.spoj.com/problems/IITWPC4I/




// Time Complexity:O(nlogn+nlogm).                                          // n- #edges given. (nlogm for querying on tree.)                                                 
// Space Complexity:O(m).                                                   // m- # nodes given.                                                     

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn+nlogm).                                          // n- #edges given. (nlogm for querying on tree.)                                                 
// Space Complexity:O(m).                                                   // m- # nodes given.
// This is Disjoin-Set based solution. Here, since we need to connect each citizen to atleast one milkman directly or indirectly with
// minimal cost. Since, we are doing sort of grouping here, we can use Disjoin-set technique here. Here, we first connect all milkman
// to an ephemeral node numbered '0', as a result they are all connected indirectly, now we want to add all else citizens into this
// group. Since, we need minimal cost, we sort the edges based on their values. Here, since we had already connected all milkman
// edges connecting milkman directly would be ignored. Now, edges which connect different groups would only be counted. So, as to make
// sure that all connected belong to same group, we connected group with greater parent value into group with smaller parent value. As
// a result, at the end of iteration, all the nodes connected to milkman would be pointed towards ephemeral node '0'. If the group size
// of '0' as parent is total #nodes given, we return the cost, else we print impossible.











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
    bool operator()(vector<int>&lt, vector<int>&rt){
        return lt[2]<rt[2];
    }
};




int getParent(vector<int>&parent, int node){
    if(parent[node]!=node)
        parent[node]=getParent(parent, parent[node]);
    return parent[node];
}



long long int unionGroups(vector<int>&parent, vector<int>&vols, int left, int right, int edge){
    int parLeft=getParent(parent, left);
    int parRight=getParent(parent, right);
    if(parLeft==parRight) return 0;
    if(parLeft<parRight){
        parent[parRight]=parLeft;
        vols[parLeft]+=vols[parRight];
    }else{
        parent[parLeft]=parRight;
        vols[parRight]+=vols[parLeft];
    }
    return edge;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nodes, paths;
    cin>>tests;
    for(int a=1;a<=tests;a++){
        cin>>nodes>>paths;
        vector<int>parent(nodes+1,0), vols(nodes+1,0);
        for(int i=1;i<=nodes;i++){
            parent[i]=i;
            vols[i]=1;
        }

        int sign=0;
        for(int i=1;i<=nodes;i++){
            cin>>sign;
            if(sign==1){
                unionGroups(parent, vols,0,i,0);
            }
        }
        vector<vector<int>>edges(paths);
        int node1,node2,cost;
        for(int i=0;i<paths;i++){
            cin>>node1>>node2>>cost;
            edges[i]={node1, node2, cost};
        }
        long long int res=0;
        if(vols[0]>0){
            sort(edges.begin(), edges.end(), comp());
            for(int i=0;i<paths;i++){
                res+=unionGroups(parent, vols, edges[i][0], edges[i][1], (long long int)edges[i][2]);
                if(vols[0]==nodes) break;
            }
        }
        
        if(vols[0]==nodes) cout<<res<<endl;
        else cout<<"impossible"<<endl;
    }

    return 0;
}
