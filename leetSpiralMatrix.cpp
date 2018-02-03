/*
*
//**********************************************************54. Spiral Matrix.***************************************************

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].




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
// covering all elements of the matrix.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> u;
        if(v.size()==0)
            return u;
        int clmn=v[0].size(), row=v.size();
        int limit1, limit2;
        if(row%2==0)					//Setting the value for condition prevents crash of iterations from both the sides(left, right& top, bottom)
            limit1=row/2-1;
        else
            limit1=row/2;
            
        if(clmn==1)
            limit2=-1;
        else
            limit2=clmn/2-1;   
        //cout<<"limit1: "<<limit1<<endl;
        //cout<<"limit2: "<<limit2<<endl;
        for(int i=0;i<=limit1;i++){
            for(int j=i;j<clmn-i;j++){							//Covers the left to right iteration of the print.
                //cout<<"Inside iter1 with index of row: "<<i<<" and clmn: "<<j<<" and value: "<<v[i][j]<<endl;
                u.push_back(v[i][j]);
            }
            
            for(int j=i+1;j<row-i && (clmn-1-i)>limit2;j++){	//Covers the top to bottom iteration of the print.
                //cout<<"Inside iter2 with index of row: "<<j<<" and clmn: "<<clmn-1-i<<" and value: "<<v[j][clmn-1-i]<<endl;
                u.push_back(v[j][clmn-1-i]);
            }
            
            for(int j=clmn-2-i;j>=i && i!=(row-1-i) && (row-1-i)>=0;j--){//Covers the right to left iteration of the print.
                //cout<<"Inside iter3 with index of row: "<<row-1-i<<" and clmn: "<<j<<" and value: "<<v[row-1-i][j]<<endl;
                u.push_back(v[row-1-i][j]);
            }
            
            for(int j=row-2-i;j>i && i<(clmn-1-i);j--){			//Covers the bottom to top iteration of the print.
                //cout<<"Inside iter4 with index of row: "<<j<<" and clmn: "<<i<<" and value: "<<v[j][i]<<endl;
                u.push_back(v[j][i]);
            }
            
        }
        return u;
    }
};