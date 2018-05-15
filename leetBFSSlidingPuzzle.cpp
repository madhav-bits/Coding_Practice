/*
*
//********************************************************773. Sliding Puzzle.*************************************************

On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state 
of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[0,1,2],[5,3,4]]
[[2,1,0],[5,3,4]]
[[3,1,2],[0,5,4]]
[[1,2,3],[4,5,0]]



// Time Complexity: O(6!).  
// Space Complexity: O(6!).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(6!).
// Space Complexity: O(6!).	
// This algorithm is BFS based. We do BFS, as number of states are less. We start from the src. travel to all possible non-duplicate moves. Also 
// keeps track of curr. state to the src. state in the second elem. of pair. The instant we encounter the target, we return the dist. from src.
// to that node, as it's the smallest. We keep track of all nodes which were travelled in map named "travel".

// This is sort of slow, cause lot of iterations were made to find "0", also lot of conditions are used to find the valid next states.




class Solution {
public:
    
    
    int slidingPuzzle(vector<vector<int>>& v) {
        vector<vector<int>> target(2,vector<int>(3,0));
        for(int i=1;i<=6;i++) target[(i-1)/3][(i-1)%3]=i%6;								// Setting the target vector.
        if(v==target) return 0;
        map<vector<vector<int>>, int>travel;											// Stores the vector states travelled.
        queue<pair<vector<vector<int>>, int>> pq;										// Queue to store BFS states.
        pq.push(make_pair(v,0));														// Pushing src vector into queue.
        travel[v]=1;																	// Marking src as visited.
        while(!pq.empty()){
            //cout<<"Inside the while. "<<p.second<<endl;
            pair<vector<vector<int>>, int> p;											// The second of pari contents is dist. from src to curr.
            vector<vector<int>> psn;
            int row, clmn;
            p=pq.front();
            pq.pop();
            psn=p.first;
            
            //cout<<"Inside the while with dist is: "<<p.second<<endl;
            for(int i=0;i<2;i++){                                                       //Extracting indices of "0" value.
                for(int j=0;j<3;j++){													// I guess this is the costliest step, we check linearly
                    //cout<<" old Value: "<<psn[i][j]<<" ";								// for the occurance of "0".
                    if(psn[i][j]==0){
                        row=i; clmn=j;
                    }
                }
                //cout<<endl;
            }
            //cout<<endl;
            for(int i=-1;i<=1;i++){															// This cdn allows only 4 directional moves(No Diag. moves).
                for(int j=-1;j<=1;j++){
                    if(row+i>=0 && row+i<=1 && clmn+j>=0 && clmn+j<=2 && !(i==1 &&j==1) && !(i==-1 &&j==-1) && !(i==0 &&j==0) && !(i==-1 &&j==1) && !(i==1 &&j==-1)){
                        //cout<<"i: "<<i<<" and j: "<<j<<endl;
                        vector<vector<int>> temp=psn;
                        swap(temp[row+i][clmn+j], temp[row][clmn]);							// Creating the next state.
                        if(temp==target) return p.second+1;									// If target reached, return distance.
                        
                        if(travel.count(temp)==0){											// If the next move isn't travelled once.
                            pq.push(make_pair(temp,p.second+1));
                            travel[temp]=1;													// Prevents duplicate entries into Queue.
                        }
                    }
                }
            }
            
            
        }
        return -1;																			// If target not reachable, then return -1.
        
    }
};