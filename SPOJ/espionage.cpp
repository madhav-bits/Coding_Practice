/*

//*******************************************************RPLE - Espionage.***********************************************************
https://www.spoj.com/problems/RPLE/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is HashMap based problem. Here, we have to mark the two nodes with diff. colors spy with (1) and citizen with (-1). While 
// we take nodes on the edges, we color them, if any of those already colored with diff. than the color that we are planning to 
// color now, we mark the test case as failed and don't process later edges. If two nodes are't colored, we color spy and citizen 
// accordingly.











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

    
    int tests;
    cin>>tests;

    int nodes, links;
    for(int a=0;a<tests;a++){
        cin>>nodes>>links;
        vector<int>graph(nodes+1,0);                                        // 1-> spy, -1 indicates citizen.
        int node1, node2;
        bool res=true;
        for(int j=0;j<links;j++){
            cin>>node1>>node2;
            if(res==false) continue;
            if(graph[node1]==-1 || graph[node2]==1){
                res=false;
                continue;
            }
            graph[node1]=1;graph[node2]=-1;
        }
        if(res) cout<<"Scenario #"<<a+1<<": spying"<<endl;
        else cout<<"Scenario #"<<a+1<<": spied"<<endl;
    }

    return 0;
}