/*
*
//******************************************************717. 1-bit and 2-bit Characters.***********************************************

We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will 
always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
Note:

1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



[1,1,1,1,1,0]


[1,0]



[0]



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. Here, there are three types of symbols. When iterating from front, if we have '1' in curr. char, we skip next
// char and move to 'i+2' index, if we have '0' at index 'i', we move to next char. If we are at (len-1) index with a value '0', we return true.
// If we iterate out of iterating entire array, then return false, as we haven't reached '0' char at last index.








class Solution {
public:
    
        
    bool isOneBitCharacter(vector<int>& v) {
        for(int i=0;i<v.size();){											// Iter. over given array.
            if(v[i]==0){													// If curr. char is '0'. 
                if(i==v.size()-1) return true;								// IF we are at last index with char '0', return true.
                i++;    													// Move to next index for other bits.
            } 
            else i+=2;														// If curr. char is '1', we skip next index.
        }
        return false;														// If we moved out of iterating array, then we haven't reached last '0'.
    }
};