/*

//*******************************************************SGAME - SHAPE GAME.***********************************************************
https://www.spoj.com/problems/SGAME/




Time Complexity:O(1).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(1).                                                  
// Space Complexity:O(1).                                                   
// This is Graph based solution. Here, we need to find an euler circuit. The path should start, close at same vertex covering
// all nodes/edges. Since, we need to start, finish at same vertex, we need even edges on all vertices, if any node has odd edges,
// the path sinks there. In case of two odd edged vertices exist, we can have euler path but not circuit. If more than 2 odd edged
// vertices exist, then neither of them exist. 
// FOR EULER CIRCUIT, ALL NODES SHOULD HAVE EVEN EDGES.
// FOR EULER PATH, ALL NODES CAN HAVE EVEN EDGES/ TWO NODES CAN HAVE ODD EDGES, STARTING AT ONE OF THEM AND FINISHING AT ONE OF THEM.









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


    for(int a=0;a<tests;a++){
        int src;
        vector<int>edges(300+1,0);
        cin>>src;
        int node1, node2;
        cin>>node1>>node2;
        while(node1!=-1){
            edges[node1]++;
            edges[node2]++;
            // cout<<"node1: "<<node1<<" and node2: "<<node2<<endl;
            cin>>node1>>node2;
        }
        int odds=0;
        for(int i=1;i<=300;i++){
            if(edges[i]%2==1) odds++;
        }
        // cout<<"odds nodes: "<<odds<<endl;
        if(odds>0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }

    return 0;
}