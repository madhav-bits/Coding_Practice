/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

//***************************************THIS IS LEET ACCEPTED CODE.**************************************************
*/
class Solution {
public:
    
    int uniqPath(vector<vector<int>> grid){
        int row= grid.size(); int column= grid[0].size();
        cout<<"Rows are: "<<row<<endl;
        cout<<"Columns are: "<<column<<endl;
        int arr[row][column]={};
        if(grid[0][0]==1)
            return 0;
        arr[0][0]=1;
        int a=0;
        for(int i=1;i<column;i++){// Initializing first row.
            if(grid[0][i]==1){
                arr[0][i]=0;
                a=1;
            }
            if(a==0)// This makes sure that once a blockade is encountered all the subsequent-
                arr[0][i]=1;//-values are automatically initialized to zero.
            else
                arr[0][i]=0;
            //cout<<"column is: "<<i<<" value is: "<<arr[0][i]<<endl;
        }
        int b=0;
        for(int i=1;i<row;i++){// Initializing first column.
            if(grid[i][0]==1){
                arr[i][0]=0;
                b=1;
            }
            if(b==0)// This makes sure that once a blockade is encountered all the subsequent- 
                arr[i][0]=1;//-values are automatically initialized to zero.
            else
                arr[i][0]=0;
        }
        
        cout<<"before double loops."<<endl;
        for(int i=1;i<row;i++){
            for(int j=1;j<column;j++){
                if(grid[i][j]==1)
                    arr[i][j]=0;
                else
                    arr[i][j]=arr[i-1][j]+arr[i][j-1];
                //cout<<"i: "<<i<<" j: "<<j<<"array value is: "<<arr[i][j]<<endl;
            }
        }
        return arr[row-1][column-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int answer=uniqPath(obstacleGrid);
        cout<<"The answer is: "<<answer<<endl;
        return answer;
    }
};