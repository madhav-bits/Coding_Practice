/*
*
//********************************************************************Flip.***********************************************************

https://www.interviewbit.com/problems/flip/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


01101011001


0010111001


111111

00011111100000111100001100




// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is Sliding Window based. We maintain a window, which gives positive number of ones at any instant. If at any instant, we 
// get negative ones, then we empty the window and continue iterating. If we encounter a '1', we dec. the count by one, we accept ones as long
// as we have positive ones(Upon inverting), and dec. the #effective ones. At every step of encountering zero, we try to update the maxm var.
// If curr. count is maxm, we update the maxm var., we also update the start, end var. If the start, end var is -1, we return emtpy vector, else
// return the obtained indices.








vector<int> Solution::flip(string s) {
    vector<int>res;															// Stores the final result.
    int start=-1,close=-1;
    int maxm=0, count=0;													// Tracks maxm size of window, effective ones in curr. window.
	int st=-1;																// Tracks beginning of curr. window.
    for(int i=0;i<s.length();i++){											// Iter. through array.
        if(s[i]=='0'){														// If zero encountered.
			if(st==-1) st=i;												// If st is -1(empty window), init. the start of window.
            count++;														// INc. the count.
            if(count>maxm){													// Update the maxm var.
                start=st;													// Update the start, close var.
                close=i;
                maxm=count;							
            }
        } 
        else{																// If '1' encountered.
            count--;														// Dec. the count.
            if(count<0){													// If count is <0.
                count=0;													// Empty the window.
				st=-1;														// Mark start as -1 for empty window.
            }
        }
    }
    if(start==-1) return res;												// If maxm. window's start is -1, then there is no answer.
    else return vector<int>({start+1,close+1});								// Return the obtained start, close index/psn values.
}
