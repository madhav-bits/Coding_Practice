/*
*
//**************************************************************443. String Compression.*****************************************************

Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["a","b","c"]

["a","a","b","c"]

["a"]


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Two pointer based. First pointer iterates and gets the count of all conse. chars. Second ptr. appends the curr. char. and 
// curr. char's count to the modified str(if count>1). At the end of first pointer's iteration, we return the length of the modified str(value
// of second pointer).








class Solution {
public:
    int compress(vector<char>& v) {
        int index=0;														// Tracks the last index of modified string.
        for(int i=0;i<v.size();i++){										// Iterate the curr. array.
            int count=0;													// Clac. count of chars in array.
            char c=v[i];													// Note curr. tracking char.
            // cout<<"CUrr. char: "<<c<<endl;
            while(i<v.size() && v[i]==c){									// Get #conse. occur. of curr. char.
                i++;
                count++;
            } 
            i--;															// Setting iterator for next iteration.
            v[index++]=c;													// Adding curr. char to modified str.
            // cout<<"Num. count: "<<count<<endl;
            if(count>1){													// If #occurances>1.
                string str1=to_string(count);								// Get str. format of count.
                // cout<<"Count: "<<str1<<endl;
                for(auto ch:str1) v[index++]=ch;							// Append str format of count to modified str.
            }
        }
        
        return index;														// Return the length of the modified str.
    }
};