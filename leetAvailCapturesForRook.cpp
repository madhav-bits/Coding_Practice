/*
*
//**************************************************999. Available Captures for Rook.***********************************************

https://leetcode.com/problems/available-captures-for-rook/description/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


Worked with the examples provided in the question.



// Time Complexity: O(1).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(1).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, we first find the index of Rook. We iter. in four directions till we reach a pawn or bishop
// of the same color. We count the #pawns encountered in four directions.







class Solution {
public:
    
    void getCount(vector<vector<char>>& v, int i, int j, int dx, int dy, int&res){// Func. to iter. in four directions.
        while(i>=0 && j>=0 && i<8 && j<8){
            if(v[i][j]=='.'){
                i+=dx;
                j+=dy;
                continue;
            }else if(v[i][j]=='B') break;
            else if(v[i][j]=='p'){
                res++;
                break;
            }
        }
        
    }
    
    int numRookCaptures(vector<vector<char>>& v) {
        int row=-1, col=-1;
        bool found=false;
        for(int i=0;i<8;i++){												// Finding index of Rook.
            for(int j=0;j<8;j++){
                if(v[i][j]=='R'){
                    row=i; col=j;
                    found=true;
                    break;
                }
            }
            if(found) break;
        }
        
        int res=0;
        // cout<<"row: "<<row<<" and col: "<<col<<endl;
        int i=row, j=col;
        getCount(v,i-1,j, -1,0, res);										// Func. call to iter. in four directions.
        getCount(v, i+1, j, 1, 0, res);
        getCount(v, i,j-1, 0, -1, res);
        getCount(v,i,j+1, 0, 1, res);
        return res;															// Return the #pawns encountered.
    }
};