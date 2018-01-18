/*
*
//**********************************************************764. Largest Plus Sign.******************************************************

In a 2D grid from (0, 0) to (N-1, N-1), every cell contains a 1, except those cells in the given list mines which are 0. What is the 
largest axis-aligned plus sign of 1s contained in the grid? Return the order of the plus sign. If there is none, return 0.

An "axis-aligned plus sign of 1s of order k" has some center grid[x][y] = 1 along with 4 arms of length k-1 going up, down, left, and 
right, and made of 1s. This is demonstrated in the diagrams below. Note that there could be 0s or 1s beyond the arms of the plus 
sign, only the relevant area of the plus sign is checked for 1s.

Examples of Axis-Aligned Plus Signs of Order k:

Order 1:
000
010
000

Order 2:
00000
00100
01110
00100
00000

Order 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
Example 1:

Input: N = 5, mines = [[4, 2]]
Output: 2
Explanation:
11111
11111
11111
11111
11011
In the above grid, the largest plus sign can only be order 2.  One of them is marked in bold.
Example 2:

Input: N = 2, mines = []
Output: 1
Explanation:
There is no plus sign of order 2, but there is of order 1.
Example 3:

Input: N = 1, mines = [[0, 0]]
Output: 0
Explanation:
There is no plus sign, so return 0.
Note:

N will be an integer in the range [1, 500].
mines will have length at most 5000.
mines[i] will be length 2 and consist of integers in the range [0, N-1].
(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)


//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//This algorithm basically iterates through the entire array in o(n^2) time while focusing on upward and downward dirn non-zeros parallely. Thus
//making it a clever and tricky algorithm.

//This can be done in O(n^3) time, which iterates through the entire array in O(n^2) time, at each index start searching in all drns until zero is 
// met in any drn and saving no. of non-zeros till then. After the iteration get the maxm. value(indicting non-zeros in all drns from there).

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>>v(N, vector<int>(N,N));						//Saves #conse. non-zeros in all drns from that index.
        
        for(auto temp:mines)
            v[temp[0]][temp[1]]=0;
        
        for(int i=0;i<N;i++){											//We want the min. no. of conse. non-zeros when compared from all dir.
            for(int j=0,l=0, r=0, u=0, d=0, k=N-1;j<N;j++, k--){
                v[i][j] = min(v[i][j], l = (v[i][j] == 0 ? 0 : l + 1));//This iterates in the right direction, thus summing non-zeros from the left.
                v[i][k] = min(v[i][k], r = (v[i][k] == 0 ? 0 : r + 1));
                v[j][i] = min(v[j][i], u = (v[j][i] == 0 ? 0 : u + 1));
                v[k][i] = min(v[k][i], d = (v[k][i] == 0 ? 0 : d + 1));
                
            }
        }
        
        int maxm=INT_MIN;
        for(int i=0;i<N;i++){                                           //Extracing the maxm value forming the "+" sign.
            for(int j=0;j<N;j++){
                cout<<v[i][j]<<" ";
                maxm=max(maxm,v[i][j]);
            }
            cout<<endl;
        }
        //cout<<"The result is: "<<maxm<<endl;
        return maxm;													//Returning the maxm. no. of non-zeros in all drns from an index in array.
    }
};