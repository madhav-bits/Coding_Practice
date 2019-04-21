/*

//*****************************************************TOANDFRO - To and Fro.*********************************************************
https://www.spoj.com/problems/TOANDFRO/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Array manipulation based problem. I reverse the substring in each row of given string. Later, i iterate over string and
// gather chars coloumn wise.







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




bool getAncestor(vector<vector<int>>&graph, int node, int node1, int node2, int &res){
    
    bool found=false;

    bool isCurr=(node==node1 || node==node2)?true:false;
    for(int i=0;i<graph[node].size();i++){
        int child=graph[node][i];
        bool ans=getAncestor(graph, child, node1, node2, res);
        // cout<<"node: "<<node<<" child: "<<child<<" and found: "<<ans<<endl;
        if(found && ans) res=node;
        found|=ans;
    }
    if(found && isCurr) res=node;
    if(node==node1 && node==node2) res=node;
    found|=isCurr;
    return found;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int cols;
    string s="";
    cin>>cols;
    while(cols!=0){
        cin>>s;
        int rows=s.length()/cols;
        for(int i=0;i<s.length();i+=cols){
            if((i/cols)%2==0) continue;
            int j=i, k=i+cols-1;
            // cout<<"swapping substr: "<<s.substr(i,cols)<<endl;
            while(j<k){
                swap(s[j], s[k]);
                j++;k--;
            }
        }
        string res="";
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                res+=s[i*cols+j];
            }
        }
        cout<<res<<endl;
        cin>>cols;
    }

    return 0;
}
