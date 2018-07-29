/*
*
//************************************************************533. Lonely Pixel II.*****************************************************

Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R 
and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

Note:
The range of width and height of the input 2D array is [1,200].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


[["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","B","W","B","B","W"],["W","W","B","W","B","W"]]
3


[["W","B","W","B","B","W"],
 ["W","B","W","B","B","W"],
 ["W","B","W","B","B","W"],
 ["B","W","B","W","W","B"]]
2







// Time Complexity: O(n*m).  
// Space Complexity: O(n*m).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).
// Space Complexity: O(n*m).	
// This algorithm is Hash Map based. In the first iteration, we store the #black pixels in each row, clmn. We also keep track of chars in each row,
// and store all the rows with same seq under same str key. In the strList array, we store the char seq in each row. We also keep track of rows
// with char-'B' in each clmn. 

// In the second iteration, we iterate through cols array, at each row, we check the first entry(row value)'s seq key has all the curr. row's 
// entries, since all the rows with 'B's in that clmn, has to have same seq for any of 'B's to be counted. I compare first 'B's seq list to all
// rows with 'B's in this clmn. We, iterate through all values in colL and those satisfying cdns are counted and count is returned.






class Solution {
public:
    int findBlackPixel(vector<vector<char>>& v, int N) {
        vector<int>rows(v.size(),0),cols(v[0].size(),0);					// Keeps track of #'B' chars in each row, clmn.
        vector<vector<int>>colL(v[0].size());								// Stores row with 'B' in each clmn.
        vector<string>strList;												// Stores seq of chars of each row.
        unordered_map<string,vector<int>>seq;								// Stores rows with same seq under same seq key.
        for(int i=0;i<v.size();i++){										// ITerating through all rows, clmns.
            string str="";													// To store seq. in this row.
            for(int j=0;j<v[0].size();j++){
                str+=v[i][j];
                if(v[i][j]=='B'){											// If 'B' found.
                    rows[i]++;												// Inc. the count for that row.
                    cols[j]++;
                    colL[j].push_back(i);									// Storing rows with 'B's in that clmn.
                }
            }
            strList.push_back(str);											// Storing the seq. in a list.
            seq[str].push_back(i);											// Storing row nums with same seq under same seq key.
        }
		
        int res=0;															// #indices satisfying cdns.
        for(int i=0;i<v[0].size();i++){										// Iterating through all clmns.
            if(colL[i].size()==0 || seq[strList[colL[i][0]]]!=colL[i]) continue;// If the rows with same seq doesn't match with clmns list, skip it.
            for(int j=0;j<colL[i].size();j++){								// Iterating through curr. clmn and checking for cdns.
                if(rows[colL[i][j]]==cols[i] && cols[i]==N){				
                    // cout<<"INc. at row: "<<colL[i][j]<<" and clmn: "<<cols[i]<<endl;
                    res++;
                } 
            }
        }
        return res;															// Returning #indices satisfying the given cdns.
        
    }
};