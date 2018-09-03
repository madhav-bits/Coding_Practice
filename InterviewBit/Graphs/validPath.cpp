/*
*
//****************************************************************Valid Path.*********************************************************

https://www.interviewbit.com/problems/valid-path/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


10 20 3 4 3 2 4 8 3 3 5 1






// Time Complexity: O(n^2*circles).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2*circles).
// Space Complexity: O(n^2).	
// This algorithm is Hashing and BFS based. We start from (0,0) for making every move in 8 drns, we check whether next index is allowed or not?
// FOr being allowed, the index has to of dist>Rad from centres of all circles. We mark the visited indices, making sure we won't revisit them. 
// We iter. over all legal indices until we reach target. If we reach target, we return "YES", if not reached by the end of iter. we return "NO".








bool isValidIndex(vector<int>&row, vector<int>&clmn,int x,int y, int rad){	// Calc. whether curr. index is legal to move or not?
    for(int i=0;i<row.size();i++){											// Iter. over all circles.
        int dist=((row[i]-x)*(row[i]-x))+((clmn[i]-y)*(clmn[i]-y));
        if(dist<=(rad*rad)) return false;									// If dist.<=R, then illegal to move.
    }
    return true;															// If dist>R for all circles, then return true.
}

string Solution::solve(int A, int B, int C, int rad, vector<int> &row, vector<int> &clmn) {
    vector<vector<bool>>visited(A+1,vector<bool>(B+1,false));				// Marks visited indices.
    queue<pair<int,int>>q;													// Stores legal indices to be visited.
    if(!isValidIndex(row,clmn,0,0,rad)) return "NO";						// If start index isn't legal, return "NO".
    q.push({0,0});
    visited[0][0]=true;														// Marking the start as visited.
    while(!q.empty()){
        pair<int,int>curr=q.front();										// Storing the curr. index.
        int x=curr.first, y=curr.second;
        // cout<<"x: "<<x<<" y: "<<y<<endl;
        if(curr.first==A && curr.second==B) return "YES";   				// IF dest. reached, return "YES". 
        q.pop();
        for(int dx=-1;dx<=1;dx++){											// Iter. over the adj. indices.
            for(int dy=-1;dy<=1;dy++){
                if(x+dx>=0 && x+dx<=A && y+dy>=0 && y+dy<=B && visited[x+dx][y+dy]==false && isValidIndex(row,clmn,x+dx,y+dy,rad)){
                    visited[x+dx][y+dy]=true;								// If legal adj. index, push index to queue and mark as visited.
                    q.push({x+dx,y+dy});
                }
            }
        }
    }
    return "NO";															// If target isn't reachable, return "NO".
}
 