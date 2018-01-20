/*
*
//**********************************************************221. Maximal Square.**************************************************

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

//This is the example I had created and modified and worked on.
[["1","0","1","1","1"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]



// Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// The logic is that saving the product of elem. fromt the start and from the end in two seprate vectors and using when required to prod. excl
// a elem.by getting prod. of elem prior to it from front vector and prod. of elem .after it from the back vector and multi. it.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int row=v.size();
        if(row==0)
            return 0;
        int clmn=v[0].size();
        vector<vector<int>>u(row,vector<int>(clmn,0));//Stores min. no. of ones the current index has on top, left, diagonal towards start +1.
        int area=0;
        for(int i=0;i<clmn;i++){
            if(v[0][i]=='1'){			//An optimization possible here is: u[0][i]= v[0][i]-'0'.
                u[0][i]=1;				//1 says it has one no. of ones from index to top, left, diaognal towards start.
                area=1;
            }
        }
        for(int i=0;i<row;i++){
            if(v[i][0]=='1'){
                u[i][0]=1;
                area=1;
            }
        }
        
        for(int i=1;i<row;i++){
            for(int j=1;j<clmn;j++){
                int temp=min(u[i][j-1], u[i-1][j]);
                int minm=min(temp,u[i-1][j-1]);		//Getting the min. value from top, left, diagonal towards start.
                if(v[i][j]=='1'){
                    u[i][j]=minm+1;					//If the curr. value is one, inc. the no. of ones by one.
                    area=max(area,u[i][j]);			//This basically stores length of the square that is possible in this matrix.
                }
                //cout<<"Minm for i: "<<i<<" and j: "<<j<<" is: "<<minm<<" and u val. is: "<<u[i][j]<<endl;
            }
        }
        /*
        for(int i=0;i<row;i++){
            for(int j=0;j<clmn;j++)
                cout<<u[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<"The maxm. area is: "<<area<<endl;
        */
        
        return area*area;							//Returning the max. square area possible.
    }
};