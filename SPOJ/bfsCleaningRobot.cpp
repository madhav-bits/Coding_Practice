/*

//***************************************************CLEANRBT - Cleaning Robot.*******************************************************
https://www.spoj.com/problems/CLEANRBT/




Time Complexity:O(m*n*2^k).                                                                                                                                                                                             
Space Complexity:O(m*n*2^k).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(m*n*2^k).                                                  
// Space Complexity:O(m*n*2^k).                                                   
// This algorithm is BFS and Bitmasking based solution. Here, since we need shortest path we use BFS, and it has cover all keys, while traver-
// -sing at a point, it can move through multiple keys and reach that index, so we can have pow(2,keys) states possible for each index, so
// we keeps track of pow(2,keys) per each index, if we revisit an index with same state once again, we stop search. If an index state is
// target state (all keys have been collected), we return #steps taken till that step. Since, we may have diff keys not in sequence, we create
// target key state based on keys encountered.

// visited[i][j][mask] indicates whether [i,j] index had been visited with mask state or not?
// If mask is 001010, it says second key('b) and fourth key('d') had been visited till now in the path.
// This question is similar to #864 problem in Leetcode, Shortest path to collect all keys.







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



    vector<int>dirs({0,-1,0,1,0});
    int rows, cols;
    cin>>cols>>rows;
    int dirty=0;
    while(rows!=0 || cols!=0){
        vector<vector<char>>v(rows, vector<char>(cols, '.'));
        // cout<<"row: "<<rows<<" and cols: "<<cols<<endl;
        int sRow=-1, sCol=-1;
        char ch;
        dirty=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cin>>ch;
                if(ch=='o'){
                    sRow=i; sCol=j;
                }
                if(ch=='*'){
                    ch=dirty+'0';
                    dirty++;
                }
                v[i][j]=ch;
            }
        }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if(dirty==0){
            cout<<0<<endl;
            cin>>cols>>rows;
            continue;
        }
        // cout<<"dirty: "<<dirty<<endl;
        // cout<<"sRow: "<<sRow<<" and sCol: "<<sCol<<endl;
        int target=pow(2,dirty)-1;
        vector<vector<vector<bool>>>visited(rows, vector<vector<bool>>(cols, vector<bool>(target+1,false)));
        queue<pair<int,int>>q;
        q.push({0,sRow*cols+sCol});
        visited[sRow][sCol][0]=true;
        int len=1, res=-1,steps=0;
        bool found=false;
        while(!q.empty()){
            steps++;
            len=q.size();
            for(int i=0;i<len;i++){
                int mask=q.front().first, row=q.front().second/cols, col=q.front().second%cols;
                q.pop();
                for(int j=0;j<4;j++){
                    int dx=dirs[j], dy=dirs[j+1];
                    if(row+dx<0 || row+dx>=rows || col+dy<0 || col+dy>=cols || v[row+dx][col+dy]=='x') continue;
                    int newMask=mask;
                    if(v[row+dx][col+dy]>='0' && v[row+dx][col+dy]<='9'){
                        int shift=v[row+dx][col+dy]-'0';
                        newMask=(mask|(1<<shift));
                    }
                    if(newMask==target){
                        found=true;
                        res=steps;
                    }
                    if(visited[row+dx][col+dy][newMask]) continue;
                    q.push({newMask, (row+dx)*cols+col+dy});
                    visited[row+dx][col+dy][newMask]=true;

                    if(found) break;
                }
                if(found) break;
            }
            if(found) break;
        }

        if(found) cout<<res<<endl;
        else cout<<-1<<endl;
        visited.clear();
        v.clear();
        cin>>cols>>rows;
    }


    return 0;
}
