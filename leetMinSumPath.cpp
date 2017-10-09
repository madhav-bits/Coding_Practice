/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

//****************************************THIS IS A LEET ACCEPTED CODE.***************************************
*/
class Solution {
public:
    int minSum(vector<vector<int>> grid){
        int row= grid.size(); int column= grid[0].size();
        cout<<"Rows are: "<<row<<endl;
        cout<<"Columns are: "<<column<<endl;
        int arr[row][column]={};
        arr[0][0]=grid[0][0];
        for(int i=1;i<column;i++){// Initializing first row.
            arr[0][i]=arr[0][i-1]+grid[0][i];
            //cout<<"column is: "<<i<<" value is: "<<arr[0][i]<<endl;
        }
        for(int i=1;i<row;i++)// Initializing first column.
            arr[i][0]=arr[i-1][0]+grid[i][0];
        cout<<"before double loops."<<endl;
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                arr[i][j]=((arr[i-1][j]<arr[i][j-1]?arr[i-1][j]:arr[i][j-1]))+grid[i][j];
                //cout<<"i: "<<i<<" j: "<<j<<"array value is: "<<arr[i][j]<<endl;
            }
        }
        return arr[row-1][column-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        cout<<grid[0].size()<<endl;
        int answer=minSum(grid);
        cout<<"The answer is: "<<answer<<endl;
        return answer;
    }
};