/*
*
//******************************************************2810. Faulty Keyboard.******************************************************

https://leetcode.com/problems/faulty-keyboard/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"string"
"poiinter"
"abcideighjiklmniopirs"
"abcidefisifaiasdfisd"



// Time Complexity: O(n).													// Solution 2 has better Time complexity.  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is itration based. Here, we as we iterate over the string, we collect the chars we iterated till that time, when 'i' is encountered, we reverse the string 
// till then, when non 'i' chars are encountered, we append this new char to the end, we repeat this same process until the end of iter. and return the res string.







class Solution {
public:
    string finalString(string s) {
        string res="";
        for(char&ch:s) {
            if(ch=='i') reverse(res.begin(), res.end());					// Reverse the string formed until then.
            else res+=ch;													// Adding curr. char to the end.
        }
        return res;															// Returning the formed string.
    }
};





//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Deque based. Here, we append the chars to the deque based on the flips we enountered till then, in case of even flips we append chars to the end, in case
// of odd flips we add chars to the front. Based on the total flips, for odd total- we stringify the flipped deque and return it, whereas in case of even flips we stringify the 
// deque and return it.





// This discussion forum link has good explanation for this approach:
// https://leetcode.com/problems/faulty-keyboard/discuss/3870361/O(n)





class Solution {
public:
    string finalString(string s) {
        deque<char>dq;														// Stores the chars of the string temporarily during iteration.
        bool flip=false;													// Tracking even/odd #flips we had encountered.
        for(char&ch:s) {
            if(ch=='i') flip=!flip;											// Tracking #flips encountered.
            else flip?dq.insert(dq.begin(), ch):dq.insert(dq.end(), ch);	// Adding chars at front for odd #flips, adding at the back for even #flips.
        }
        return flip?string(dq.rbegin(), dq.rend()):string(dq.begin(), dq.end());// Returing flipped deque for odd #total flips, deque as it is for even #total flips.
    }
};


