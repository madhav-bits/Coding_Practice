/*
*
//************************************************************Spiral Order Matrix II.*****************************************************


https://www.interviewbit.com/problems/spiral-order-matrix-ii/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1

2

3

4


5



// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is iteration based. Here, we keep track of legal rows, clmns we can iter.through. In each iter. we do Rightwards, Downwards,
// Leftwards, Upwards iter. in the legal indices, we stop when we have accumulated pow(num,2) #values in final result vector.







vector<vector<int> > Solution::generateMatrix(int num) {
    vector<vector<int>>res(num,vector<int>(num,0));							// Init. the 2D array.
    int curr=1,total=pow(num,2);											// Init. the target count, curr. pushed vals count.
    int minRow=0,maxRow=num-1,minCol=0,maxCol=num-1;						// Init. max and min legal Row, Clmn values.
    // cout<<"maxCol: "<<maxCol<<endl;
    int row=0,clmn=0;														// Init. the iter. values.
    while(curr<=total){
	
		if(curr>total) break;
        // cout<<"Inside R: minCOl "<<minCol<<" and maxCol: "<<maxCol<<endl;
        for(clmn=minCol; clmn<=maxCol;clmn++){        						// Rightwards.
            // cout<<"R: "<<curr<<endl;
            res[row][clmn]=curr++;
        }
        row++;																// Setting iter. values for next iter.
        clmn--;
        minRow++;															// As, this row is entirely covered, we inc. minRow to stop revisiting.
        
        
		if(curr>total) break;
		// cout<<"minRow: "<<minRow<<" and clmn: "<<clmn<<endl;
        for(row=minRow; row<=maxRow;row++){          						// Downwards.
            // cout<<"D: "<<curr<<endl;
            res[row][clmn]=curr++;
        }
        clmn--;
        row--;
        maxCol--;
        
		if(curr>total) break;
        for(clmn=maxCol;clmn>=minCol;clmn--){            					// Leftwards.
            // cout<<"L: "<<curr<<endl;
            res[row][clmn]=curr++;
        }
        row--;
        clmn++;
        maxRow--;
        
		if(curr>total) break;
        for(row=maxRow;row>=minRow;row--){               					// Upwards.
            // cout<<"T: "<<curr<<endl;
            res[row][clmn]=curr++;
        }
        clmn++;
        row++;
        minCol++;
        
    }
    return res;																// Returning the final result vector.
}
