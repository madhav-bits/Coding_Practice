/*

//**********************************************SOCNETC - Social Network Community.**************************************************
https://www.spoj.com/problems/SOCNETC/




Time Complexity:O(logn).                                           // Since we are doing path compression and Union by size(Hueristics).                                                                                                                                                                              
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                        // Since we are doing path compression and Union by size(Hueristics). 
// Space Complexity:O(n).                                                   
// This is Union-Find solution. Here, we are supposed to join groups, if their combined group size doesn't exceed given limit. For 
// query 'E', we get the parent of both the nodes, if they are equal, we print true else print false. While calculating the parent
// of a node, we make the core parent, the parent of all nodes in the path from curr. node to core parent, which compresses the path.
// In case of query 'S', we will find it's core parent, get the total #elem. in it's group by using vol array, where we store #nodes
// under all core parents. 







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




void joinGroups(vector<int>&parent, vector<int>&vol, int node1, int node2, int limit){
    int par1=getParent(parent, node1);
    int par2=getParent(parent, node2);
    int vol1=vol[par1], vol2=vol[par2];
    if(par1==par2 || vol1+vol2>limit) return ;
    if(vol1>=vol2){
        parent[par2]=par1;
        vol[par1]+=vol[par2];
    }else{
        parent[par1]=par2;
        vol[par2]+=vol[par1];
    }
    return;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int users, limit;
    cin>>users>>limit;

    vector<int>parent(users+1,0), vol(users+1,1);
    for(int i=1;i<=users;i++) parent[i]=i;
    int queries;
    cin>>queries;

    string s="";
    int node1, node2;
    for(int i=0;i<queries;i++){
        cin>>s;
        if(s=="E"){
            cin>>node1>>node2;
            int par1=getParent(parent, node1);
            int par2=getParent(parent, node2);
            if(par1==par2) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else if(s=="S"){
            cin>>node1;
            int par1=getParent(parent, node1);
            cout<<vol[par1]<<endl;
        }else{
            cin>>node1>>node2;
            joinGroups(parent, vol, node1, node2, limit);
        }
    }

    return 0;
}
