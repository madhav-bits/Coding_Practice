/*

//***********************************************74. Search a 2D Matrix.*******************************************************
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

//******************************************************THIS IS LEET ACCEPTED CODE.*********************************************
//*******************************************************************************************************************************
//*******************************************************************************************************************************
// FOCUS ON THE VALUE THAT IS RETURNED FROM THE WHILE LOOP IN BINARY SEARCH(START/MID) IF MID+1&MID-1 IS USED, USE START<=CLOSE RETURN-
// MID IF POSSIBLE. IF MID-1 AND MID IS USED USE START<CLOSE AND RETURN START.********************************************************
//*******************************************************************************************************************************
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        if(v.size()==0)
            return false;
        int start=0, close=v.size()-1, mid, d=v[0].size()-1;
        while(start<close){//Finding the row in which the target might exist.
            //cout<<"The start is: "<<start<<" and the close is: "<<close<<endl;
            mid=(start+close)/2;
            //cout<<"The compared value is: "<<v[mid][d]<<endl;
            if(target>v[mid][d])
                start=mid+1;
            else
                close=mid;
        }
        //cout<<"The array is: "<<v[start][0]<<endl;
        int row=start;
        start=0; close=d;
        while(start<=close){// Narrowing down the area of interest, finding whether the target truly exists in this array.
            mid=(start+close)/2;// If not present, false statement at the end gets returned.
            if(v[row][mid]==target)
                return true;
            if(v[row][mid]<target)
                start=mid+1;
            else
                close=mid-1;
        }
        
        return false;
    }
};