/*

//***************************************************CATM - The Cats and the Mouse.*******************************************************
https://www.spoj.com/problems/CATM/




Time Complexity:O((m+n)*mn).                                                                                                                                                                                                                                         
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O((m+n)*mn).                                                  
// Space Complexity:O(n).                                                   
// This is BFS based solution. Here, at every step we keep track of all indices in which cats can be, we choose only those steps for 
// mouse in which cats doesn't present in that step. If in the next step, we move out of boundary, we return "YES", if after certain
// number of steps, we don't have any index adj. to curr. psns in which cats aren't there, then we return "NO".






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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int rows, cols;
    cin>>rows>>cols;
    int tests;
    cin>>tests;
    for(int a=0;a<tests;a++){
        int mRow,mCol, c1Row, c1Col, c2Row, c2Col;
        cin>>mRow>>mCol>>c1Row>>c1Col>>c2Row>>c2Col;
        mRow--;mCol--;c1Row--; c1Col--; c2Row--; c2Col--;
        // cout<<"mR: "<<mRow<<" mC: "<<mCol<<" c1R: "<<c1Row<<" c1C: "<<c1Col<<" c2R: "<<c2Row<<" c2C: "<<c2Col<<endl;
        queue<int>ms;
        ms.push(mRow*cols+mCol);
        queue<int>cat;
        cat.push(c1Row*cols+c1Col);
        cat.push(c2Row*cols+c2Col);
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        vector<vector<bool>>v2(rows, vector<bool>(cols, false));
        vector<int>dirs({-1,0,1,0,-1});
        bool found= false;

        while(!ms.empty()){

            int len=cat.size();
            for(int b=0;b<len;b++){
                int rep=cat.front();
                // cout<<"cat rep: "<<rep<<endl;
                cat.pop();
                int x=rep/cols, y=rep%cols;
                // cout<<"catR: "<<x<<" and catC: "<<y<<endl;
                visited[x][y]=false;
                for(int i=0;i<4;i++){
                    int dx=dirs[i], dy=dirs[i+1];
                    if(x+dx<0 || x+dx>=rows || y+dy<0 || y+dy>=cols || visited[x+dx][y+dy]) continue;
                    visited[x+dx][y+dy]=true;
                    cat.push(((x+dx)*cols)+(y+dy));
                }
            }


            len=ms.size();
            for(int b=0;b<len;b++){
                int rep=ms.front();
                ms.pop();
                int x=rep/cols, y=rep%cols;
                v2[x][y]=false;
                for(int i=0;i<4;i++){
                    int dx=dirs[i], dy=dirs[i+1];
                    if(x+dx<0 || x+dx>=rows || y+dy<0 || y+dy>=cols){
                        found=true;
                        cout<<"YES"<<endl;
                        break;
                    }
                    if(visited[x+dx][y+dy] || v2[x+dx][y+dy]) continue;
                    v2[x+dx][y+dy]=true;
                    ms.push(((x+dx)*cols)+(y+dy));
                }
                if(found) break;
            }


            if(found) break;
        }
        
        if(!found) cout<<"NO"<<endl;
    }
    return 0;
}