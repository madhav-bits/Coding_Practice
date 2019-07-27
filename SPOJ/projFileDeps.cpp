/*

//**********************************************PFDEP - Project File Dependencies.***************************************************
https://www.spoj.com/problems/PFDEP/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Topological Sorting and Priority Queue based solution. Here, we will be BFS Topological sorting but since the reqruired
// output needs to be in increasing order of node values if they are indepenedent of each other, we will be using  a priority queue
// to get the least valued node out of queue.







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







int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, nodes;
    cin>>nodes>>tests;
    vector<vector<int>>graph(nodes+1);
    vector<int>inCount(nodes+1,0);
    for(int i=0;i<tests;i++){
        int node, numDeps, dep;
        cin>>node>>numDeps;
        inCount[node]=numDeps;
        for(int j=0;j<numDeps;j++){
            cin>>dep;
            graph[dep].push_back(node);
        }
    }

    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int>res;
    for(int i=1;i<=nodes;i++){
        if(inCount[i]==0) pq.push(i);
    }

    while(!pq.empty()){
        int node=pq.top();
        pq.pop();
        res.push_back(node);
        for(int i=0;i<graph[node].size();i++){
            int fol=graph[node][i];
            inCount[fol]--;
            if(inCount[fol]==0) pq.push(fol);
        }

    }

    for(auto num:res) cout<<num<<" ";
    cout<<endl;


    return 0;

}