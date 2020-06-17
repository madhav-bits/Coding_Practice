/*
*
//**************************************************1476. Subrectangle Queries.*************************************************

https://leetcode.com/problems/subrectangle-queries/description/


Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and 
supports two methods:

1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is 
(row2,col2).
2. getValue(int row, int col)

Returns the current value of the coordinate (row,col) from the rectangle.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with examples provided with Question.



// Time Complexity: O(p).													
// Space Complexity: O(p).													// p- #Updates.	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(p).													
// Space Complexity: O(p).													// p- #Updates.	
// This algorithm is observation based. Here, we store all updates in an array. When queried, we iter. over updates in reverse order,
// if we encounter any subrectangle that covers queried index, we return that value.








class SubrectangleQueries {
public:
    vector<vector<int>>updates, rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        updates=vector<vector<int>>();										// Arr. to store the Updates.
        rect=rectangle;														// Assigning given rect. to global var.
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        updates.push_back({row1, row2, col1, col2, newValue});				// Storing all the update parameters.
    }
    
    int getValue(int row, int col) {
        for(int i=updates.size()-1;i>=0;i--){								// Reverse iter. over updates.
            if(row>=updates[i][0] && row<=updates[i][1] && col>=updates[i][2] && col<=updates[i][3])// If Update covering Query found.
                return updates[i][4];										// Return the updated value.
        }
        return rect[row][col];												// If index not updated, we return orig. value.
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */