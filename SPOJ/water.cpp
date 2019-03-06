/*

//**************************************************WATER - Water among Cubes.******************************************************
https://www.spoj.com/problems/WATER/




Time Complexity:O(m*nlog(m*n)).                                                                                                                                                                                             
Space Complexity:O(m*n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity: O(m*n(m+n)).
// Space Complexity: O(m*n).    
// This algorithm is Priority Queue based. Here, we do BFS from corner indices. While traversing, if adj. index's height dec. then 
// it can affect it's neighbouring indices, so we push adj. index into queue while marking the curr. index with min. height of water
// it can store. Thus, at the end of iteration, all indices are marked with min. height of water they can maintain, we iter. over
// array, get total water stored in all indices and print it.




// These links contains good description of algo. used here:
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89495/How-to-get-the-solution-to-2-D-%22Trapping-Rain-Water%22-problem-from-1-D-case
// https://tinyurl.com/y6l776t5
// https://leetcode.com/problems/trapping-rain-water-ii/description/







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



void markHeight(vector<vector<int>>&v, vector<vector<int>>&res, int row, int col){
    int hei=v[row][col];
    res[row][col]=v[row][col];
    // vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
    // visited[row][col]=true;
    // cout<<"start: "<<row<<" and col: "<<col<<endl;
    res[row][col]=v[row][col];
    vector<int>dirs({-1,0,1,0,-1});
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        // hei=res[x][y];
        q.pop();
        for(int i=0;i<4;i++){
            int dx=dirs[i], dy=dirs[i+1];
            if(x+dx<=0 || x+dx>=v.size()-1 || y+dy<=0 || y+dy>=v[0].size()-1 ||  res[x+dx][y+dy]<=res[x][y]) continue;
            // cout<<"pushing row: "<<x+dx<<" and y: "<<y+dy<<endl;
            res[x+dx][y+dy]=min(res[x+dx][y+dy], max(res[x][y], v[x+dx][y+dy]));    // As least hei. of water is stone height in that index.
            q.push({x+dx, y+dy});
            // visited[x+dx][y+dy]=true;
        }
    }
}




int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests, rows, cols;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>rows>>cols;
        vector<vector<int>>v(rows, vector<int>(cols, 0)), res(rows, vector<int>(cols, INT_MAX));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++) cin>>v[i][j];
        }

        for(int j=0;j<cols;j++) markHeight(v,res,0,j);
        for(int j=0;j<cols;j++) markHeight(v,res,rows-1,j);   

        for(int i=1;i<rows-1;i++) markHeight(v,res, i,0);
        for(int i=1;i<rows-1;i++) markHeight(v,res, i,cols-1); 

        
        int vol=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // cout<<res[i][j]<<" ";
                if(i==0 || i==rows-1 || j==0 || j==cols-1) continue;
                // vol+=max(0, res[i][j]-v[i][j]);
                vol+=(res[i][j]-v[i][j]);
            } 
            // cout<<endl;
        }
        cout<<vol<<endl;
    }
    return 0;
}



















//***********************************************************Solution 2.*************************************************************
// Time Complexity: O(m*nlog(m*n)).
// Space Complexity: O(m*n).    
// This algorithm is Priority Queue based. Here, the main issue is that an index takes the min Height of water that can be supported 
// by four adj. sides. Here, indices on edges decides the height of water. So, we need min. height, so we start working from least
// height to greatest height on the edges. We extract indices from Priority Queue based on the water heights supported by them.
// We perform BFS, while working on an index, if it's adjacent index is visited, then this index's height would be the least height
// of water supported by adj. index, we calc. height for it and push it into Qeueue to visit indices, which it influences. Thus, at the
// end of iteration, we get the volume of water stored in all indices.





// These links contains good description of algo. used here:
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89495/How-to-get-the-solution-to-2-D-%22Trapping-Rain-Water%22-problem-from-1-D-case
// https://tinyurl.com/y6l776t5
// https://leetcode.com/problems/trapping-rain-water-ii/description/













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



struct Cell{
    int x,y,height;
    
    Cell(int a, int b, int c){
        x=a;
        y=b;
        height=c;
    }
};



struct comp{
    bool operator()(Cell &lt, Cell &rt){
        return lt.height>rt.height;
    }
};



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests, rows, cols;
    cin>>tests;

    for(int a=0;a<tests;a++){
        cin>>rows>>cols;
        vector<vector<int>>v(rows, vector<int>(cols, 0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++) cin>>v[i][j];
        }

        if(v.size()<=2){
            cout<<0<<endl;
            continue;
        }

        priority_queue<Cell,vector<Cell>, comp>pq;
        vector<vector<bool>>visited(v.size(), vector<bool>(v[0].size(), false));
        vector<int>dirs({-1,0,1,0,-1});
        for(int i=0;i<v.size();i++){
            pq.push(Cell(i,0, v[i][0]));
            pq.push(Cell(i,cols-1, v[i][cols-1]));
            visited[i][0]=true;
            visited[i][cols-1]=true;
        }
        for(int j=1;j<cols-1;j++){
            pq.push(Cell(0,j, v[0][j]));
            pq.push(Cell(v.size()-1,j, v[v.size()-1][j]));
            visited[0][j]=true;
            visited[v.size()-1][j]=true;
        }


        int res=0;
        while(!pq.empty()){
            Cell curr=pq.top();
            int x=curr.x, y=curr.y;
            pq.pop();
            for(int i=0;i<4;i++){
                int dx=dirs[i], dy=dirs[i+1];
                if(x+dx<0 || y+dy<0 || x+dx>=v.size() || y+dy>=cols || visited[x+dx][y+dy]) continue;
                res+=max(0, curr.height-v[x+dx][y+dy]);
                pq.push(Cell(x+dx, y+dy, max(curr.height, v[x+dx][y+dy])));
                visited[x+dx][y+dy]=true;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}