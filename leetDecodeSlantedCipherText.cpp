/*
*
//******************************************************2075. Decode the Slanted Ciphertext.******************************************************

https://leetcode.com/problems/decode-the-slanted-ciphertext/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"adgjmps  behknqt  cfilor"
3
"adgjm  behkn  cfil"
3
"adgjmps  behknq   cfilor"
3
"ch   ie   pr"
3
"iveo    eed   l te   olc"
4
"coding"
1
"ch    e   pr"
3
"aei   bf    cg    dh"
4



// Time Complexity: O(m*n).																				// n-#rows of the matrix, m-#cols in the matrix form.
// Space Complexity: O(m*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*n).																				// n-#rows of the matrix, m-#cols in the matrix form.
// Space Complexity: O(m*n).	
// This algorithm is iteration based. Here, since the ciphered text is stored diagonally, we also take our row, col ptrs and keep incrementing it to reflect diagonal iteration one at a time. We append all these chars to the 
// res and remove some trailing space chars which we append in the process and return the resulting res string.







class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        string res="";
        int cols=s.length()/rows;																		// Calc. #cols of the matrix form.
        for(int j=0;j<cols;j++) {																		// Setting the start col for the diagonal iteration.
            int i=0, k=j;
            while(i<rows && k<cols) {																	// Iterating diagonally and ensuring we dont go out of bounds of the matrix.
                res+=s[i*cols+k];																		// Appending the resulting char to res.
                i++;																					// Inc. the row, col iterators.
                k++;
            }
        }
        while(!res.empty() && res.back()==' ') res.pop_back();											// Removing the trailing space chars.
        return res;																						// Returning the original string.
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(m*(n-m+1))~O(m*n)(If n is large).													// n-#rows of the matrix, m-#cols in the matrix form.
// Space Complexity: O(m*n).
// This approach is same as the above one, except that a small optimization is applied to ensure unwanted diagonal iterations are prevented. As, we have fully filled diagonals except probably the last diagonal, so while 
// iterating the last non-full diagonal, we go out of bounds of matrix when we reach the last row, we use this situation and place condition accordingly to catch the moment and stop the iteration, as this is a non-full 
// diagonal, we still have few trailing space chars(far less compared to above algo.), we remove those trailing space chars and return the res at the end of iter.


 


class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        string res="";
        int cols=s.length()/rows;// Needs some refinment to prevent iterating over unessential diagonals.
        for(int j=0;j<cols;j++) {
            int i=0, k=j;
            bool found=false;
            while(i<rows && k<cols) {
                res+=s[i*cols+k];
                i++;
                k++;
                if(i*cols+k==s.length()) {																// Condition to identify the moment we reach the last row when iterating over non-full diagonal.
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        while(!res.empty() && res.back()==' ') res.pop_back();
        return res;
    }
};

