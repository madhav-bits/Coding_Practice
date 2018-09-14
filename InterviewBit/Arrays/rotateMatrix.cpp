/*
*
//*****************************************************************Rotate Matrix.*********************************************************


https://www.interviewbit.com/problems/rotate-matrix/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


3 3 1 2 3 4 5 6 7 8 9


4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16



5 5 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25


2 2 1 2 3 4

1 1 1




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. At each step, we rotate of values of a 4 group of nums from 4 corners in the matrix, to make a 90 deg
// rotation of those 4 values. This, way we iterate through all indices and rotate them. At the end of iter. ,we get the rotated matrix.


// We rotate 4 elem. at at time: Top Left, Top Right, Bottom Left, Bottom Right.





void Solution::rotate(vector<vector<int> > &v) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int mid=v.size()/2, len=v.size();										// Storing size of vector.
    for(int i=0;i<mid;i++){													// Iter. only half rows, as second half already swapped.
        // int tl, tr, bl, br;
        for(int j=i;j<len-1-i;j++){											// Iter. only len-1-row cols, as rest are already swapped.
            // tl=v[i][j];													// Stores Top Left value.
            // tr=v[j][len-1-i];											// Stores the Top Right.
            // bl=v[len-1-j][i];											// Stores the Bottom Left.
            // br=v[len-1-i][len-1-j];										// Stores the Bottom Right.
            int temp=v[i][j];												// Temp. storing Top Left value.
            v[i][j]=v[len-1-j][i];											// tl=bl (Copying Bottom Left into Top Left.)			
            v[len-1-j][i]=v[len-1-i][len-1-j];								// bl=br (Copying Bottom Right into Bottom Left.)
            v[len-1-i][len-1-j]=v[j][len-1-i];								// br=tr (Copying Top Right into Bottom Right.)
            v[j][len-1-i]=temp;												// tr=tl (Copying temp. stored Top Left into Top Right.)	
            
        }
    }
    
    return ;																// Returning the Modified/Rotated Matrix.
}
