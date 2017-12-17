/*

//************************************************************120. Triangle.*******************************************************

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

//7,9,1,2 -4.5				min- 7,1   max-9,2  


//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/

// Solution 1: 
//Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// This is a Dynamic Programming Solution.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int min2=INT_MAX;
        int len=v.size();
        int arr[v.size()][v.size()]={};					// Declaring the array of size (O(n^2)).
        
        for(int i=0;i<v.size();i++){					//Initializing all the contents of Array to INT_MAX value.
            for(int j=0;j<v.size();j++)
                arr[i][j]=INT_MAX;
        }
        
        for(int i=0;i<v[0].size();i++)					// Initializing all the values in the arr's front row to their values in the vector.
            arr[0][i]=v[0][i];
        
        for(int i=1;i<v.size();i++){					// 
            for(int j=0;j<v[i].size();j++){				// Array's values at index "i" depends on previous row's values at index "i-1", "i". 
                if(j-1>=0 && j-1<v[i-1].size() && arr[i-1][j-1] !=INT_MAX)
                    arr[i][j]=min(arr[i][j], v[i][j]+arr[i-1][j-1]);
    
                if(j>=0 && j<v[i-1].size() && arr[i-1][j] !=INT_MAX)
                    arr[i][j]=min(arr[i][j], v[i][j]+arr[i-1][j]);
                
            }
        }
        
        for(int i=0;i<v[len-1].size();i++)				//Checking the min value of the last row, which contains all path's sum to the last row.	
            min2=min(min2,arr[len-1][i]);
        
        return min2;
    }
};



//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

// Solution 2: 
//Time Complexity: O(n^2).
// Space Complexity: O(n).
// This is a Dynamic Programming Solution.
// This solutin optimizes the Space Complexity to O(n) needing only two rows to store the path sum.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int min2=INT_MAX;
        int len=v.size(), len2=2;
        int arr[len2][v.size()]={};
        
        for(int i=0;i<2;i++){
            for(int j=0;j<v.size();j++)
                arr[i][j]=INT_MAX;
        }
        
        for(int i=0;i<v[0].size();i++)
            arr[0][i]=v[0][i];
        //cout<<"After sorting."<<endl;
        
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(j-1>=0 && j-1<v[i-1].size() && arr[0][j-1] !=INT_MAX)
                    arr[1][j]=min(arr[1][j], v[i][j]+arr[0][j-1]);
    
                if(j>=0 && j<v[i-1].size() && arr[0][j] !=INT_MAX)
                    arr[1][j]=min(arr[1][j], v[i][j]+arr[0][j]);
                
            }
            for(int k=0;k<v.size();k++){
                arr[0][k]=arr[1][k];
                arr[1][k]=INT_MAX;
            }
        }
        
        for(int i=0;i<v[len-1].size();i++)
            min2=min(min2,arr[0][i]);
        
        return min2;
    }
};