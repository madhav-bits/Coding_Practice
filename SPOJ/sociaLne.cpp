/*

//*************************************************SOCIALNE - Possible Friends.*****************************************************
https://www.spoj.com/problems/SOCIALNE/




Time Complexity:O(n^2).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  
// Space Complexity:O(n).                                                   
// This is Hashing based solution. Here, we want to #friends which are at distance of 1 from each node. We need to return node with
// maxm. #such friends. To keep track of those friends, we use boolean array to mark all those nodes. We iter. over boolean array to 
// get count of all such friends.



// First, I thought that the requirement is to get all indirectly connected nodes, so, I did an Union-Find solution. Where, I would
// subtract (group size-1-#adj. nodes) for each node to get indirect connected nodes for each node. Return the maxm. value of them.
// Later, I had changed the code according to question's requirement.




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




int getParent(vector<int>&parent, int node){
    if(parent[node]!=node)
        parent[node]=getParent(parent, parent[node]);
    return parent[node];
}



void joinGroups(vector<int>&parent, vector<int>&vols, int node1, int node2){
    int parA=getParent(parent, node1);
    int parB=getParent(parent, node2);
    if(parA==parB) return ;
    parent[parB]=parA;
    vols[parA]+=vols[parB];
    return ;
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nodes;
    cin>>tests;
    string s;
    cin.ignore();
    for(int a=1;a<=tests;a++){
        getline(cin, s);
        // cout<<s<<endl;
        nodes=s.length();
        vector<vector<int>>graph(nodes);
        vector<int>parent(nodes,0), vols(nodes,0);
        for(int i=0;i<nodes;i++){
            parent[i]=i;
            vols[i]=1;
        }

        for(int j=0;j<nodes;j++){
            if(s[j]=='Y'){
                graph[0].push_back(j);
                // joinGroups(parent, vols,0,j);    
            } 
        }
        for(int i=1;i<=s.length()-1;i++){
            getline(cin,s);
            for(int j=0;j<nodes;j++){
                if(s[j]=='Y'){
                    // if(i<j) joinGroups(parent, vols, i, j);
                    graph[i].push_back(j);    
                } 
            }
            // cout<<s<<endl;
        }
        // for(int i=0;i<nodes;i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         cout<<"i: "<<i<<" and adj: "<<graph[i][j]<<endl;
        //     }
        //     // cout<<endl;  
        // }
        

        int res=-1, resNode=-1,count=0;
        for(int i=0;i<nodes;i++){
            // int par=getParent(parent, i);
            // int adj=vols[par]-1-graph[i].size();
            // cout<<"i: "<<i<<" and adj: "<<adj<<endl;
            // if(adj>res){
            //     res=adj;
            //     resNode=i;
            // }
            count=0;
            vector<bool>mask(nodes, false);
            for(int j=0;j<graph[i].size();j++){
                int adj=graph[i][j];
                for(int k=0;k<graph[adj].size();k++){
                    int fr=graph[adj][k];
                    mask[fr]=true;
                }
            }
            mask[i]=false;
            for(int j=0;j<graph[i].size();j++){
                int adj=graph[i][j];
                mask[adj]=false;
            }
            for(int i=0;i<nodes;i++){
                if(mask[i]) count++;
            }
            if(count>res){
                res=count;
                resNode=i;
            }
        }
        cout<<resNode<<" "<<res<<endl;
    }

    return 0;
}
