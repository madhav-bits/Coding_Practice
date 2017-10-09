/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

//****************************************THIS IS LEET ACCEPTED CODE.******************************************
*/

class Solution {
public:
    int uniquePaths(int row, int column) {
        int arr[row][column]={};
        arr[0][0]=1;
        for(int i=1;i<column;i++){// Initializing first row.
            arr[0][i]=1;
            //cout<<"column is: "<<i<<" value is: "<<arr[0][i]<<endl;
        }
        for(int i=1;i<row;i++)// Initializing first column.
            arr[i][0]=1;
        cout<<"before double loops."<<endl;
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
                //cout<<"i: "<<i<<" j: "<<j<<"array value is: "<<arr[i][j]<<endl;
            }
        }
        return arr[row-1][column-1];
    }
};