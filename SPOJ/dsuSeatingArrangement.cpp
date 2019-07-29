/*

//**************************************************QN02 - Seating Arrangement.******************************************************
https://www.spoj.com/problems/QN02/




Time Complexity:O((m+n)logn).											// m-#queries, n-#students.                                                                                                                                                                                              
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O((m+n)logn).										// m-#queries, n-#students.                                                  
// Space Complexity:O(n).                                                   
// This is Disjoing Set based solution. Here, we form sets while iterating over the pairs, while iterating over queries, we check 
// from the graph, whether two given nodes belong to the same group or not? If true, we print true, else we print false.
// We had implemented Path Compression by Length Technique here.






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




vector<int>parent(100000, 0);



int findParent(int node){
	if(parent[node]!=node) parent[node]=findParent(parent[node]);
	return parent[node];
}




void joinGroups(int node1, int node2){
	int par1=findParent(node1);
	int par2=findParent(node2);
	parent[par1]=par2;
	return ; 
}




bool isSameGroup(int node1,int node2){
	int par1=findParent(node1);
	int par2=findParent(node2);
	return (par1==par2);
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    

    int students, pairs, queries;
    cin>>students>>pairs;
    for(int i=0;i<100000;i++) parent[i]=i;
    int node1, node2;
    for(int a=0;a<pairs;a++){
    	cin>>node1>>node2;
    	joinGroups(node1, node2);
    }


    cin>>queries;
    for(int a=0;a<queries;a++){
    	cin>>node1>>node2;
    	if(isSameGroup(node1, node2)) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
    }


    return 0;
}
