/*
*
//**************************************************************306. Additive Number.*****************************************************

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence 
must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true 
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true 
Explanation: The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


1023




111


011



12312312321234234





// Time Complexity: O(2^n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^n).													// Not exactly, even though each index can form a number. 
// Space Complexity: O(1).	
// This algorithm is recursion based. Here, we extract nums from the string in the recursion while making sure that curr. num equals
// prev. 2 vals. For the first two values, we won't check the summation condition, we recurse this ways and reach end of string, if the 
// #extracted nums. is <3, then return false else return true.








class Solution {
public:
    
    bool getNums(string s, int index, long int prev1, long int prev2, int count){
        if(s.length()==index){												// If end of string is reached.
            return (count>=3);												// If >=3 nums. satisfy cdns.
        }   
        long long int num=0;												// Tracks val. of curr. num.
        for(int i=index;i<s.length();i++){									// Iter. extracting curr. num.
            if(i>index && s[index]=='0') break;								// Avoiding leading zeroes.
            num*=10;														// Forming integer.
            num+=(s[i]-'0');
            if(count==0 && getNums(s,i+1,num,prev2,1)) return true;			// IF first int. not extracted.
            else if(count==1 && getNums(s,i+1, prev1, num,2)) return true;	// IF second int. not extracted.
            else if(count>=2){												// If we have two ints already extracted.
                if(num>(prev1+prev2)) break;								// Pruning.
                if(num==(prev1+prev2) && getNums(s,i+1, prev2,num,count+1)) return true;// If curr. nums satisfied sum cdn give recur. call.
            }
        }
        return false;														// If not satisfying num. found/extracted.
    }
    
    bool isAdditiveNumber(string num) {
        return getNums(num,0, -1,-1,0);										// Give recur. call to extract nums and check sum cdns.
    }
};