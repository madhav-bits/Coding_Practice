/*

//*************************************************DEPEND - Dependency Problems.*****************************************************
https://www.spoj.com/problems/DEPEND/




Time Complexity:O(edges).                                                                                                                                                                                             
Space Complexity:O(edges).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(edges).                                                  
// Space Complexity:O(edges).                                                   
// This is Topological Sort based. Here, since we are given that #nodes are<10000, we can change the problem to work on indices in a 
// vector rather than strings on maps, making it effective time complexity wise. So, we assign every string an unique integer<10000,
// by checking in map and assigning values to each string if encountered for first time. We form dependency graph, where ith row 
// contains nodes, which depend on node 'i'. We collect all independent nodes while reading input and push them into Queue. We
// also keep track of #dependencies each depending node has. We work on each independent node and remove the dependency count of 
// depending nodes, if their dependency has become zero, we push that into Queue to work on it. Thus, all downloadable gets pushed 
// into Queue eventually. Where we maintain the count of #nodes that's been pushed into queue and return the count at the end of 
// Topological Sorting.







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
#include<sstream>



using namespace std;



void topologicalSort(vector<vector<int>>graph, vector<int>inside, queue<int>&q, int &res){
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res++;
        for(int i=0;i<graph[node].size();i++){
            int adj=graph[node][i];
            inside[adj]--;
            if(inside[adj]==0) q.push(adj);
        }
    }

}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    unordered_map<string,int>m;
    int elem=0;
    vector<vector<int>>graph(10001);
    queue<int>q;
    string curr;
    cin>>curr;
    vector<int>inside(10001,0);
    while(!cin.eof()){
        // cout<<"curr; "<<curr<<endl;
        if(m.count(curr)==0) m[curr]=elem++;
        string adj="";
        int in=0;
        cin>>adj;

        while(adj!="0"){
            if(m.count(adj)==0) m[adj]=elem++;
            graph[m[adj]].push_back(m[curr]);
            in++;
            cin>>adj;
        }
        inside[m[curr]]=in;
        if(in==0) q.push(m[curr]);
        cin>>curr;
    }
    
    // for(auto it=m.begin();it!=m.end();it++){
    //     cout<<"str: "<<it->first<<" and second: "<<it->second<<endl;
    // }
    // for(int i=0;i<10;i++){
    //     cout<<"i: "<<i<<endl;
    //     for(int j=0;j<graph[i].size();j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"start size: "<<q.size()<<endl;
    int count=0;
    topologicalSort(graph, inside, q, count);
    cout<<count<<endl;
    return 0;
}