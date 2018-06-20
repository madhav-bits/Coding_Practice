/*
*
//******************************************************777. Swap Adjacent in LR String.***********************************************

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with 
"LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if 
there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"RXXXRLRXRXL"
"XRLXXXXRRLX"

"XXLXXLRX"
"LXLXXXXR"



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm iterates the array. The observation is that "L" in the source only moves to the left, "R" moves to the right. So, inorder
// for the end sequence to be possible. The "L" in the start can be at an index>=corresponding "L"'s index in target, "R"'s index in end
// can be at an index<=corresponding "R" in target. We actually need not bother about #x's b'w "L" and "R", but I had considered that factor also, 
// making my algo. to detect errors even faster.



// We need not bother to focus on #x's b/w 'L' and 'R's. That will be automatically checked by indices of 'L's and 'R's.




class Solution {
public:
    bool canTransform(string s, string t) {
        if(s.length()!=t.length()) return false;
        int lx=0,rx=0,lo=0,ro=0;
        int i=0,state=0;                                        			//1-Waiting for 'R', 2-waiting for 'L'.
        while(i<s.length()){
            if(state==0){													// 'L', 'R''s had been matched till now. checking next indices.
                // cout<<"Start of state0 at index: "<<i<<endl;
                while(i<s.length() && s[i]==t[i]) i++; 						// If curr. indices are equal.
                
                // cout<<"Outside of while in state0 at index: "<<i<<endl;
                if(i==s.length()) return true;								// If end of str. is reached.
                if(s[i]!='X' && t[i]!='X') return false;					// If two str's have 'L' and 'R' in curr. index.
                if(s[i]=='L' || t[i]=='R') return false;					// With These psns target can't be achieved.
                else if(s[i]=='R') state=1;									// We start looking for next 'L' in target. 
                else state=2;												// We start looking for next 'R' in src. 
                // cout<<"2"<<endl;
                lx=0;rx=0;lo=0;ro=0;										// Init. count variables.
                // cout<<"Out of state0 to state: "<<state<<" at index i: "<<i<<" and j: "<<j<<endl;
            }
            if(state==1){													// Searching for next occurance of 'L'.
                while(i<t.length() && t[i]!='L'){
                    if(s[i]=='L') return false;								// If 'L' in src had occured prior to 'L' in target, return false.
                    if(t[i]=='X') rx++;										// Counting #x's and R's till next 'L' in target.
                    else ro++;
                    if(s[i]=='X') lx++;
                    else lo++;
                    i++;
                }
                // cout<<"Outside while in state1 with lx: "<<lx<<" rx: "<<rx<<" lo: "<<lo<<" ro: "<<ro<<endl;
                if(lx!=rx || lo!=ro) return false;							// If count doesn't match, then return false.
                state=0;													// Change to Neutral state.
            }
            if(state==2){													// Searching for next occurance of 'R'.
                
                while(i<s.length() && s[i]!='R'){
                    if(t[i]=='R') return false;								// If 'R' in target had occured prior to 'R' in src, return false.
                    if(s[i]=='X') lx++;										// Counting #x's and L's till next 'R' in src.
                    else lo++;
                    if(t[i]=='X') rx++;
                    else ro++;
                    i++;
                }
                if((lx!=rx || lo!=ro)) return false;						// If count doesn't match, then return false.
                state=0;
            }
            
        }
        return true;														// If no issues found, return true.
    }
};