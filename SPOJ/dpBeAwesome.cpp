/*

//**********************************************BEHAPPY - Be Awesome As Barney Stinson.**********************************************
https://www.spoj.com/problems/BEHAPPY/




Time Complexity:O(m*n).                                                     // m- #gifts, n-#sum of all girls gift's ranges.                                                                                                                                             
Space Complexity:O(m).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n).                                                  // m- #gifts, n-#sum of all girls gift's ranges.                                          
// Space Complexity:O(m).                                                   
// This is Dynamic Programming based solution. Here for every girl, we iter. gifts which are possible to be distributed among all 
// previous girls. We ignore those coin combinations, which doesn't involve using all girls. At the end of iter. we return #possib.
// to distirbute all gifts involving all girls.








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

    
    int girls, gifts;
    cin>>girls>>gifts;
    while(girls!=0 || gifts!=0){
        vector<long long int>v(gifts+1,0);
        vector<vector<bool>>valid(2, vector<bool>(gifts+1,false));
        valid[0][0]=true;
        v[0]=1;
        int low, high, gl=0;
        // cin>>low>>high;
        for(int gl=1;gl<=girls;gl++){
            cin>>low>>high;
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            for(int j=0;j<=gifts;j++) valid[gl%2][j]=false;
            for(int i=gifts;i>=0;i--){
                if(valid[(gl-1)%2][i]==false) continue;
                int val=v[i];
                for(int j=low;j<=high;j++){
                    if(i+j>gifts) break;
                    if(valid[gl%2][i+j]==false){
                        v[i+j]=val;
                        valid[gl%2][i+j]=true;
                    } 
                    else v[i+j]+=val;
                }
            }
            // for(int k=0;k<=gifts;k++){
            //     cout<<"k: "<<k<<" and possib: "<<v[k]<<endl;
            // }
            // cout<<endl;
        }
        cout<<v[gifts]<<endl;
        cin>>girls>>gifts;
    }

    return 0;
}