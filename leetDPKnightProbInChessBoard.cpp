/*
*
//****************************************************688. Knight Probability in Chessboard.*********************************************

On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and 
columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then 
one square in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off 
the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the 
knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.

//These are the examples I had created and worked on.
1)
15
15
1
2

2)
2
2
0
0

3)
24
14
1
1



// Time Complexity: O(N*m*n).
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(K*N*N).
// Space Complexity: O(N*N).
// This algorithm works on logic that probability of Horse being in that index in a step is summation of (1/8) times of Prob. of Horse being 
// the indexes from where one can reach the index under observation. We will sum all the probabilities of horse being on all the indices on
// the board after "K" steps.


class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> v(2,vector<vector<double>>(N, vector<double>(N,0)));
        v[0][r][c]=1;
        double pres=0;
        for(int i=1;i<=K;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    v[i%2][j][k]=0;
                    if(j-2>=0 && k-1>=0)                    //Top 1 Left.
                    v[i%2][j][k]+=v[(i-1)%2][j-2][k-1]*(0.125);//Calc. the prob. of horse being in that index from prev. step.
                    if(j-1>=0 && k-2>=0)                    //Top 2 Left.
                    v[i%2][j][k]+=v[(i-1)%2][j-1][k-2]*(0.125);
                    
                    if(j-2>=0 && k+1<N)                     //Top 1 Right.
                    v[i%2][j][k]+=v[(i-1)%2][j-2][k+1]*(0.125);
                    if(j-1>=0 && k+2<N)                     //Top 2 Right.
                    v[i%2][j][k]+=v[(i-1)%2][j-1][k+2]*(0.125);
                    
                    if(j+2<N && k-1>=0)                    //Bottom 1 Left.
                    v[i%2][j][k]+=v[(i-1)%2][j+2][k-1]*(0.125);
                    if(j+1<N && k-2>=0)                    //Bottom 2 Left.
                    v[i%2][j][k]+=v[(i-1)%2][j+1][k-2]*(0.125);
                    
                    if(j+2<N && k+1<N)                     //Bottom 1 Right.
                    v[i%2][j][k]+=v[(i-1)%2][j+2][k+1]*(0.125);
                    if(j+1<N && k+2<N)                     //Bottom 2 Right.
                    v[i%2][j][k]+=v[(i-1)%2][j+1][k+2]*(0.125);
                    //cout<<v[i%2][j][k]<<" ";
                }
                //cout<<endl;
            }
            //cout<<endl<<endl;
        }
       
        //cout<<"The final matrix is: "<<endl;
       for(int i=0;i<N;i++){
           for(int j=0;j<N;j++){
				pres+=v[K%2][i][j];					//Summation of prob. over all indices of the board after "K" steps.
               //cout<<v[K%2][i][j]<<" ";
           }
           //cout<<endl;
       }
        
       //cout<<"The result is: "<<pres<<endl;
       return pres;                       			//Returning the summation of probabilities of horse being on the board.        
    }
};