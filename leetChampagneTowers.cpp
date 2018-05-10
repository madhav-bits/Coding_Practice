/*
*
//********************************************************799. Champagne Towers.*************************************************

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds 
one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.  When the top most glass is full, any excess liquid poured will fall equally 
to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and 
right of those glasses, and so on.  (A glass at the bottom row has it's excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the 
second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After 
four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured 
below.



Now after pouring some non-negative integer cups of champagne, return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)

 

Example 1:
Input: poured = 1, query_glass = 1, query_row = 1
Output: 0.0
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the 
glasses under the top glass will remain empty.

Example 2:
Input: poured = 2, query_glass = 1, query_row = 1
Output: 0.5
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The 
glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
 

Note:

poured will be in the range of [0, 10 ^ 9].
query_glass and query_row will be in the range of [0, 99].



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


6
2
2



8
1
1


23
4
4




// Time Complexity: O(n^2).  
// Space Complexity: O(n^2).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).	
// This algorithm is Dynamic Programming based problem. It iterates through all rows in the arrangement. At each row's glasses it checks whether
// it has excess volume or not, if yes then split the excess volume into it's child glasses. Thus we reach the target row and target clmn.



class Solution {
public:
    double champagneTower(int poured, int row, int clmn) {
        vector<vector<double>>cont(101,vector<double>(101,0));				// Maintains liquid volume of all rows and clmns.
        cont[0][0]=poured;													// Top of the arrangement.
        for(int i=0;i<=row;i++){
            for(int j=0;j<=i;j++){
                if(cont[i][j]>=1){
                    cont[i+1][j]+=(cont[i][j]-1)/2;							// Splitting the excess volume into it's two child glasses.
                    cont[i+1][j+1]+=(cont[i][j]-1)/2;						// Splitting the excess volume into it's two child glasses.
                }
            }
        }
        
        return cont[row][clmn]>=1?1:cont[row][clmn];						// If excess vol. exists, return 1, else the exact volume.
    }
};












//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based problem. It iterates through all rows in the arrangement. At each row's glasses it checks whether
// it has excess volume or not, if yes then split the excess volume into it's child glasses. Thus we reach the target row and target clmn.

// This algo. utilizes space effectivley. As we need values from prev. row to calculate values for the curr. row. We create "Max Row" number of 
// vector contents, we create next row contents and pass the remain. excess volume into the same index in the next row. We return after "Row"
// number of iterations.



class Solution {
public:
    double champagneTower(int poured, int row, int clmn) {
        vector<double>cont(101,0);													// Maintains the vol. at all clmns of each iter's curr. row.
        cont[0]=poured;
        for(int i=1;i<=row;i++){
            for(int j=i;j>0;j--){
                double extra=cont[j-1]>1?cont[j-1]-1:0;								// To fill value at index-"i" we need excess value from "i-1" 
                cont[j]+=extra/2;													// - from prev. row.
                cont[j-1]=extra/2;													// Pass the rem. excess value of prev. row to the same index
            }																		// in the curr. row.
        }
        
        return cont[clmn]>=1?1:cont[clmn];											// Returning the volume in glass at target row and clmn.
    }
};








