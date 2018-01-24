/*
*
//****************************************************576. Out of Boundary Paths.*********************************************

There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent 
cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the 
number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
Explanation:

Example 2:
Input:m = 1, n = 3, N = 3, i = 0, j = 1
Output: 12
Explanation:

Note:
Once you move the ball out of boundary, you cannot move it back.
The length and height of the grid is in range [1,50].
N is in range [0,50].


// Time Complexity: O(N*m*n).
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(N*m*n).
// Space Complexity: O(N*m*n).
// This algortihm is that we have to calculate the no. of ways to move out of the field. We approach it in reverse direction, starting from 
//the edge of field for where no. of possiblities to reach from outside box is "1" to the starting index in the qsn after "N" steps.


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        //size_t v[N+1][m][n]={0};                  //Don't know why array is not functioning.
        //vector<vector<vector<size_t>>>v(N+1, vector<vector<size_t>>(m,vector<size_t>(n,0)));
        vector<vector<vector<long>>>v(N+1, vector<vector<long>>(m,vector<long>(n,0)));
        for(int i=1;i<=N;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    v[i][j][k]+= (j==0)?1:v[i-1][j-1][k];//From Top.
                    v[i][j][k]+= (j==m-1)?1:v[i-1][j+1][k];//From Bottom.
                    
                    v[i][j][k]+= (k==0)?1:v[i-1][j][k-1];//From left.
                    v[i][j][k]+= (k==n-1)?1:v[i-1][j][k+1];//From right.
                    v[i][j][k]%=1000000007;
                }
            }
        }
        
        //cout<<"The result is: "<<v[N][i][j]<<endl;
        return v[N][i][j];
    }
};




//************************************************************Solution 2:************************************************************
// Time Complexity: O(N*m*n).
// Space Complexity: O(m*n).
// This algortihm is that we have to calculate the no. of ways to move out of the field. We approach it in reverse direction, starting from 
//the edge of field for where no. of possiblities to reach from outside box is "1" to the starting index in the qsn after "N" steps.



class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        //size_t v[N+1][m][n]={0};                  //Don't know why array is not functioning.
        //vector<vector<vector<size_t>>>v(N+1, vector<vector<size_t>>(m,vector<size_t>(n,0)));
        vector<vector<vector<long>>>v(N+1, vector<vector<long>>(m,vector<long>(n,0)));
        for(int i=1;i<=N;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    v[i% 2][j][k]+= (j==0)?1:v[(i-1)% 2][j-1][k];//From Top.//(i-1)%2
                    v[i% 2][j][k]+= (j==m-1)?1:v[(i-1)% 2][j+1][k];//From Bottom.//i%2
                    
                    v[i% 2][j][k]+= (k==0)?1:v[(i-1)% 2][j][k-1];//From left.
                    v[i% 2][j][k]+= (k==n-1)?1:v[(i-1)% 2][j][k+1];//From right.
                    v[i% 2][j][k]%=1000000007;
                }
            }
        }
        
        //cout<<"The result is: "<<v[N][i][j]<<endl;
        return v[N%2][i][j];
    }
};