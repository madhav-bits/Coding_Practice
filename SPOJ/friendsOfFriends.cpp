/*

//************************************************FACEFRND - Friends of Friends.*****************************************************
https://www.spoj.com/problems/FACEFRND/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(k).                                                      // k- Maxm. range of friends allowed.         

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(k).                                                   // k- Maxm. range of friends allowed.                                      
// This is Hasing based solution. We use a bool array to keep track of friends visited, we return total friends- directly linked
// friends.







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

    int friends, adj, others;
    cin>>friends;
    vector<bool>visited(10000,false);
    for(int i=0;i<friends;i++){
        cin>>adj;
        visited[adj]=true;
        cin>>others;
        for(int j=0;j<others;j++){
            cin>>adj;
            visited[adj]=true;
        }
    }
    int res=0;
    for(int i=0;i<10000;i++){
        if(visited[i]) res++;
    }
    cout<<res-friends<<endl;
    return 0;
}
