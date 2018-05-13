/*
*
//**********************************************************38. Count and Say.***************************************************

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


50
100																				// Throws Time Limit Exceeded.
0
1
2
200																				// Throws Time Limit Exceeded.



// Time Complexity: O(n^2).  													// Approximately O(n^2).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).														// Approximately O(n^2).
// Space Complexity: O(n).	
// This algorithm is Dynamic Programming based, we maintain two states, the curr. string is obtained by counting the #consecutive same ints in the 
// prev. string and forming the chars in the curr. string-(using counts and the corresp. int). For the iteration we make the curr. string as
// prev. string, thus we iterate for "N" times.



class Solution {
public:
    string countAndSay(int n) {
        string prev="1";														// This is the base string.
        string curr="";
        if(n==1) return prev;													// Base case.
        for(int i=2;i<=n;i++){													// Starting the iterations.
            //cout<<"Starting of iteration i: "<<i<<endl;
            curr="";
            int ind=0;
            while(ind<prev.length()){											// Iterating through the prev. string.
                int count=1;
                ind+=1;
                while(ind<prev.length()){										// Counting the consec. ints in the prev. string.
                    if(prev[ind]!=prev[ind-1]) break;
                    count++;
                    ind++;
                }
                curr+=to_string(count)+prev[ind-1];								// Forming curr. string based on count and the corresp. int
            }
            prev=curr;															// Updating the prev. string for the next iteration.
            //cout<<"Next string formed is: "<<prev<<endl;
        }
        return curr;															// Returning the final result string.
    }
};