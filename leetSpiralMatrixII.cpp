/*
*
//**********************************************************59. Spiral Matrix II.***************************************************

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]




//These are the examples I had created, tweaked and worked on.
[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]	
[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
[[1,2,3],[4,5,6],[7,8,9]]
[]
[[1,2,3]]
[[1],[2],[3],[4],[5],[6],[7],[8],[9],[10]]
[[1,11],[2,12],[3,13],[4,14],[5,15],[6,16],[7,17],[8,18],[9,19],[10,20]]
[[7],[9],[6]]


// Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// This algorithm iterates through the matrix in four different aspects left to right, top to bottom, right to left, bottom to top. Thus
// covering all elements of the matrix and pushing the values to the corresponding places.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n,0));
        int top=0, bottom=n-1, left=0, right=n-1;
        int count=1;
        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                //cout<<"Inside loop1 with i: "<<top<<" j: "<<j<<" with value: "<<count<<endl;
                v[top][j]=count;			//Placing the values in the corresponding places as per the question.
                count++;
            }
            top++;
            if(top>bottom) break;
            for(int i=top;i<=bottom;i++){
               //cout<<"Inside loop2 with i: "<<i<<" j: "<<right<<" with value: "<<count<<endl; 
               v[i][right]=count;			//Placing the values in the corresponding places as per the question.
                count++;	
            }
            right--;
            if(left>right) break;
            
            for(int j=right;j>=left;j--){
                //cout<<"Inside loop3 with i: "<<bottom<<" j: "<<j<<" with value: "<<count<<endl;
                v[bottom][j]=count;			//Placing the values in the corresponding places as per the question.
                count++;
            }
            bottom--;
            if(top>bottom) break;
            
            for(int i=bottom;i>=top;i--){
                //cout<<"Inside loop4 with i: "<<i<<" j: "<<left<<" with value: "<<count<<endl;
                v[i][left]=count;			//Placing the values in the corresponding places as per the question.
                count++;
            }
            left++;
            if(left>right) break;
        }
        return v;							//Returning the vector containing the all the required values in their respective places.
    }
};