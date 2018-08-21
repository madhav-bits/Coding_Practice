/*
*
//******************************************************351. Android Unlock Patterns.***********************************************

Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android 
lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:

Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the 
pattern. No jumps through non selected key is allowed.
The order of keys used matters.
 


Explanation:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:

Input: m = 1, n = 1
Output: 9




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1
3

4
7




// Time Complexity: O(n!).  												// Not sure Time complexity though.
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n!).
// Space Complexity: O(1).	
// Here, it's not sqaure keys but dots.
// This algorithm is Hashing and Backtracking based. The main concept is that we move through all possible paths, keep track of unique keys touc-
// -hed. We can form a link b/w 1 and 8 directly, without depending on any other keys/dots. ONe omre point is that two points with with dist. of 
// 2, can be connected only when they have a visited node in b/w them. The optimization step is that, as 1,3,7,9 are symmetrical, we calc. count
// for any one of them, multiply by 4. Same with symmetrical nature of 2,4,6,8. Here, 5 is unique it's count is added to final result.









class Solution {
public:
    int minm,maxm;															// Minm, maxm allowed unique nums in pattern.
    
    bool jump(int x,int y, int dx, int dy, vector<vector<bool>>&visited){	// Checking whether two nodes of dist 2 can be connected.
        if(dx==0){
            if(dy==2 && visited[x][y+1]==false) return true;				// The middle node is unvisited. Return can't be connected.
            if(dy==-2 && visited[x][y-1]==false) return true;
        }    
        if(dy==0){
            if(dx==2 && visited[x+1][y]==false) return true;
            if(dx==-2 && visited[x-1][y]==false) return true;
        }
        
        if(dy==-2){
            if(dx==2 && visited[x+1][y-1]==false) return true;
            if(dx==-2 && visited[x-1][y-1]==false) return true;
        }
        
        if(dy==2){
            if(dx==2 && visited[x+1][y+1]==false) return true;
            if(dx==-2 && visited[x-1][y+1]==false) return true;
        }
        
        
        
        if(dx==-2){
            if(dy==2 && visited[x-1][y+1]==false) return true;
            if(dy==-2 && visited[x-1][y-1]==false) return true;
        }
        
        if(dx==2){
            if(dy==2 && visited[x+1][y+1]==false) return true;
            if(dy==-2 && visited[x+1][y-1]==false) return true;
        }
			
        return false;														// Returning two nodes can be connected.
    }
    
    int calcPatterns(int row, int clmn, vector<vector<bool>>&visited, int &count){
        // cout<<"curr. row: "<<row<<" and clmn: "<<clmn<<endl;
        visited[row][clmn]=true;											// Marking curr. index as visited.
        count++;															// Inc. the count of visited nodes.
        int res=0;
        if(count>maxm){														// If count>maxm allowed stop recursion.
            visited[row][clmn]=false;
            count--;
            return 0;
        } 
        else if(count>=minm && count<=maxm) res++;							// If count within range, inc. the overall result value.
        int x=row, y=clmn;
        for(int dx=-2;dx<=2;dx++){											// Iter. through all possible values.
            for(int dy=-2;dy<=2;dy++){
                // if((dx==0 && (dy==-2 ||dy==2)) || (dy==0 && (dx==-2 ||dx==2)) || ((dy==-2 ||dy==2) && (dx==-2 ||dx==2))) continue;
                if(x+dx>=0 && x+dx<3 && y+dy>=0 && y+dy<3 && visited[x+dx][y+dy]==false){// If next node is valid and univisited.
                    bool res2=jump(x,y,dx,dy,visited);						// Checking for valid jump.
                    if(res2) continue;										// If jump isn't allowed, skip that jump.
                    int temp=calcPatterns(x+dx,y+dy,visited,count);			// Go for recursive call to further explore possib.
                    res+=temp;												// Extract the count from call, add it to final result.
                }
            }
        }
        visited[row][clmn]=false;											// Marking curr. node as univisted, so that backtracking is done.
        count--;															// Dec. the visited nodes count.
        return res;															// Returning the #valid patterns passing through this node, this count.
    }
    
    int numberOfPatterns(int m, int n) {
        int total=0;
        vector<vector<bool>>visited(3,vector<bool>(3,false));				// Tracks nums visited.
        int count=0,res=0;													// Tracks count of unique nums visited.
        minm=m; maxm=n;														// Minm, Maxm unique nums allowed.
        // res=calcPatterns(0,0,visited,count);
        // cout<<"res for 0 and 0 is: "<<res<<endl;
        total+=4*calcPatterns(0,0,visited,count);							// Calc. count for 1 number.
        // res=calcPatterns(0,1,visited,count);
        // cout<<"res for 0 and 1 is: "<<res<<endl;
        total+=4*calcPatterns(0,1,visited,count);							// Calc. count for 2 number.
        // res=calcPatterns(1,1,visited,count);
        // cout<<"res for 1 and 1 is: "<<res<<endl;
        total+=calcPatterns(1,1,visited,count);								// Calc. count for 5 number.
        return total;
        
        
        // for(auto nums:visited){
        //     for(auto num:nums)
        //         cout<<num<<" ";
        //     cout<<endl;
        // }
        // cout<<"Count: "<<count<<endl;
    }
};