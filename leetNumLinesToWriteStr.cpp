/*
*
//******************************************************806. Number of Lines To Write String.***********************************************

We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a 
letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where 
widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your 
answer as an integer list of length 2.

 

Example :
Input: 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
Output: [3, 60]
Explanation: 
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.
Example :
Input: 
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
Output: [2, 4]
Explanation: 
All letters except 'a' have the same length of 10, and 
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.
 

Note:

The length of S will be in the range [1, 1000].
S will only contain lowercase letters.
widths is an array of length 26.
widths[i] will be in the range of [2, 10].




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"


widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"


// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is linear, dec. the avai. width in the curr. line accordingly at each time step, If the curr. char causes the line's width to be 
// completed, then move to the next line and dec. it's avai. width.



class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
        if(s.length()==0) return vector<int>(1,0);
        vector<int> res(2,0);
        int len, lines=1;
        int rem=100;																// Width of each line.
        for(int i=0;i<s.length();i++){
            //cout<<"the index is; "<<i<<endl;
            if(rem-w[s[i]-'a']>=0){
                rem-=w[s[i]-'a'];													// Updating the avai. width in the curr. line.
                //cout<<"Line is: "<<lines<<"The char is: "<<s[i]<<" and the length used by this word is: "<<w[s[i]-'a']<<endl;
            }
            else{
                lines++;															// Moving onto next line.
                rem=100-w[s[i]-'a'];												// Updating the avai. width in the new line.
            }
        }
        //cout<<"The length in the last line is: "<<100-rem<<endl;
        res[0]=lines;																// #lines used.
        res[1]=100-rem;																// Width occupied in the last line.
        return res;																	//Returning the final res. vector.
        
    }
};