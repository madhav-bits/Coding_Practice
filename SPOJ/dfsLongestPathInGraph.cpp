/*

//*****************************************************************PT07Z - Longest path in a tree*************************************************************
https://www.spoj.com/problems/PT07Z/


Time Complexity:O(n).
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).
// Space Complexity:O(n).
// This is DFS based solution. Here, we iterate over all nodes, collect longest path in those nodes and try to add them with max. dist. collected 
// from a node to it's children till then, such that we get max. path passing through that curr. node. We return the max. depth possible to 
// travel from that node(#edges on path)+1 from that node to parent. We keep on updating final result at each step, after all iter. we get the max.
// number of edges b/w nodes.







#include <iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;


int findDepth(int node, vector<bool>&visited, vector<vector<int>>&graph, int&res){
	int maxLen=0;
	visited[node]=true;
	for(int i=0;i<graph[node].size();i++){
		if(visited[graph[node][i]]) continue;
		int len=findDepth(graph[node][i], visited,graph, res);
		res=max(res,maxLen+len);
		maxLen=max(maxLen,len);
	}
	res=max(res,maxLen);
	visited[node]=false;
	return maxLen+1;
}

int main() {
	// your code here
	int num=0;
	cin>>num;
	vector<vector<int>>graph(num+1);
	for(int i=1;i<num;i++){
		int u,v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool>visited(num+1,false);
	int res=0;
	findDepth(1,visited,graph, res);
	cout<<res<<endl;
	return 0;
}