/*
*
//**********************************************************498. Diagonal Traverse.***************************************************

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
[[1,2,3,],[4,5,6],[7,8,9],[10,11,12],[13,14,15]]
[[1],[4]]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm is- iteration over the 2D Array. Moving diagonally upwards and downwards, and carefully choosing the indices to travel and
// setting up the conditions(exceeding row and clmn limits after the end of iteration).



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        vector<int> u;													// To store the iterated values order.
        int len=v.size();
        if(len==0) return u;											// If empty array is given.
        int bre=v[0].size();
        int row=0, clmn=0;
        while(1){
            while(row>=0 && clmn<bre){									// Diagonally traversing upwards.
                //cout<<"Upwards and i: "<<row<<" and j: "<<clmn<<endl;
                u.push_back(v[row][clmn]);
                row--; clmn++;
            }
            //cout<<"Outside upwards and i: "<<row<<" and j: "<<clmn<<endl;
            if(row==-1 && clmn==bre){									// If row and clmn bounds are exceeded at the same time.
                row+=2;													// Setting the indices for the next iteration.
                clmn--;
            }
            else if(clmn<bre){											// If row bound is exceeded.
                clmn;
                row=0;
            }
             else if(row>=0){											// If clmn bound is exceeded.
                row+=2;
                 clmn--;
            }
            if(row>=v.size() || clmn>=bre) break;						// If the to be iterated indices are out of bound, then exit the loop.
            while(row<len && clmn>=0){									// Diagonally traversing downwards.
                //cout<<"Downwards and i: "<<row<<" and j: "<<clmn<<endl;
                u.push_back(v[row][clmn]);
                row++; clmn--;
            }
            if(row==len && clmn==-1){									// If row and clmn bounds are exceeded at the same time. 
                row--;													// Setting the indices for the next iteration.
                clmn+=2;
            }
            else if(row<len){											// IF clmn bound is exceeded.
                row;
                clmn=0;
            }
            else if(clmn>=0){											// If row bound is exceeded.
                clmn+=2;
                row=len-1;
            }
            if(row>=v.size() || clmn>=bre) break;						// If the to be iterated indices are out of bound, then exit the loop.
            //cout<<"Outside downwards and i: "<<row<<" and j: "<<clmn<<endl;
        }
        return u;														// Returning the values reflecting the order of iteration.
    }
};