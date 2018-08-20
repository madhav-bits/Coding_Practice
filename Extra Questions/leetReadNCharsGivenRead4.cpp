/*
*
//******************************************************157. Read N Characters Given Read4.***********************************************

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Example 1:

Input: buf = "abc", n = 4
Output: "abc"
Explanation: The actual number of characters read is 3, which is "abc".
Example 2:

Input: buf = "abcde", n = 5 
Output: "abcde"
Note:
The read function will only be called once for each test case.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcdefghijklmnop" 11

"abcdefghi" 7


"" 2



// Time Complexity: O(n).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).	
// This algorithm is iteration based. We tracks #chars read, #chars read in previous iter., Here, there are two imp. cases to think about. One is
// we are asked to read less than length of string, other is to read more than length of string. When we are asked to read less than string's len
// we don't satisfy len<n prop. then len-4+read would give more than target len, so we return target len. In case of reading more than length of 
// str. we read<4 at the end of str, so we stop iter.. len-4+read gives total readable chars, we return it.








// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len=0;															// Tracks total chars read till now.
        int read=4;															// Chars read in prev. iter.
        while(len<n && read==4){											// Iter. till taget len isn't reached and there is str to be read.
            read=read4(buf+len);											// Extract #chars read in this iter.
            len+=4;															// Inc. the #chars read by 4.
        }
        return min(len-4+read,n);											// Returning the min of target len/len of chars readable.
    }
};