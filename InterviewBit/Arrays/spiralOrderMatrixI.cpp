/*
*
//************************************************************Spiral Order Matrix I.*****************************************************


https://www.interviewbit.com/problems/spiral-order-matrix-i/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


2 3 1 2 3 4 5 6

1 3 1 2 3

3 3 1 2 3 4 5 6 7 8 9


1 1 1


4 1 1 2 3 4




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Iteration based. Here, we set the max, min ROW, CLMNS that we are allowed to iter. in curr. iteration. We do a iter. from
// L->R, Top->Bottom, R->L, Bottom->Top iter. following the constraints. After iter. in every drn, we update the allowed indices range. Thus, at 
// the end of iter. we get the Spiral Order Iter. of matrix.








vector<int> Solution::spiralOrder(const vector<vector<int> > &v) {
    vector<int>res;
    if(v.size()==0) return res;
    int minRow=1,maxRow=v.size()-1,minCol=0, maxCol=v[0].size()-1;			// Setting the allowed rows, clmns range.
    int total=v.size()*v[0].size();											// Total num. of values expected(#elem. in matrix).
    int i=0,j=0;
    while(res.size()<total){
        while(j<=maxCol){   												// Rightwards.
            if(res.size()==total) return res;
            if(i>=0 && i<v.size() && j>=0 && j<v[0].size()) res.push_back(v[i][j]);
            j++;
        }
        j--;																// Setting row, clmn values for next iter.
        i++;
        maxCol--;															// Updating allowed row, clmn ranges.
        while(i<=maxRow){   												// Downwards.
            if(res.size()==total) return res;
            if(i>=0 && i<v.size() && j>=0 && j<v[0].size()) res.push_back(v[i][j]);
            i++;
        }
        i--;j--;
        maxRow--;
        
        while(j>=minCol){   												// Leftwards.
            if(res.size()==total) return res;
            if(i>=0 && i<v.size() && j>=0 && j<v[0].size()) res.push_back(v[i][j]);
            j--;
        }
        j++;
        i--;
        minCol++;
        
        while(i>=minRow){   												// Upwards.
            if(res.size()==total) return res;
            if(i>=0 && i<v.size() && j>=0 && j<v[0].size()) res.push_back(v[i][j]);
            i--;
        }
        i++;j++;
        minRow++;
        
    }
    return res;																// Returning the Spiral Order Matrix iter. values.
}
