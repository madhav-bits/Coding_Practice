/*
*
//****************************************************302. Smallest Rectangle Enclosing Black Pixels.*********************************************

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only 
one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the 
smallest (axis-aligned) rectangle that encloses all black pixels.

Example:

Input:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2

Output: 6




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]]
0
2



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is BFS/DFS based. I had solved it in BFS way though. I start from the black pixel provided, we travel through all indices
// which were not covered previously. At each index we travel, we try to update the max,min index travelled along both drns. At the end of 
// iteration,we those values in calc. the area of rect. enclosing them. As, a rectangle constructed with those 4 pts as corners would cover all
// black pixels with min. area.


// We can even avoid the space related to creating the visited array by changing the values of all visited nodes '0'. But, I didn't want to 
// change the values of given array.






class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int xMin=x, xMax=x,yMin=y,yMax=y;									// Tracks min/max values of indices travelled in both drns.
        vector<vector<int>>visited(image.size(), vector<int>(image[0].size(),0));// Tracks all visited indices.
        visited[x][y]=1;													// Marking the start index as visited.
        vector<int>dirs({0,-1,0,1,0});										// Useful in pointing 4 drns.
        queue<pair<int,int>>q;												// Stores indices to be visited.
        q.push({x,y});														// Pushing start index into queue.
        while(!q.empty()){													// Iter. till no possible to be visited indices left.
            int row=q.front().first,clmn=q.front().second;					// Storing curr. row and clmn.
            q.pop();
            for(int i=0;i<4;i++){											// check indices in 4 drns.
                int dx=dirs[i], dy=dirs[i+1];
                if(row+dx>=0 && row+dx<image.size() &&clmn+dy>=0 && clmn+dy<image[0].size() && image[row+dx][clmn+dy]=='1' && visited[row+dx][clmn+dy]==0){
                    q.push({row+dx,clmn+dy});								// If it's valid, unvisited index, then visit it.
                    visited[row+dx][clmn+dy]=1;								// Mark next index as visited.
                    xMin=min(xMin,row+dx);									// Try to update the 4 min/ max values of 2 drns.
                    xMax=max(xMax,row+dx);
                    yMin=min(yMin,clmn+dy);
                    yMax=max(yMax,clmn+dy);
                }
            }
        }
        // cout<<"xmin: "<<xMin<<" and xMax: "<<xMax<<" and yMin: "<<yMin<<" and yMax: "<<yMax<<endl;
        return (xMax-xMin+1)*(yMax-yMin+1);									// Returning the min. area of rect. which covers all black pixels.
    }
};