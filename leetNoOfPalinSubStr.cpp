/*

//*************************************************647. Palindromic Substrings.*****************************************************

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.

//Time Complexity: O(n^2).
// Space Complexity: O(n^2).
//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    int countSubstrings(string s) {
        int result, len=s.length(), count=0;
        if(s.length()==0)
            return 0;
        int arr[len][len]={0};// Initializing a 2D array to 0.
        for(int i=0;i<len;i++)
            arr[i][i]=1;// Initializing base cases(Substrings of length 1).
        count=len;
        for(int i=1;i<len;i++){//i var. stands for (diff. b/w indices of begin and end of substring ex: i for "ab" is 1.).
            for(int j=0;j+i<len;j++){// Iterating the beginning of substring through out the string.
                if(s[j]==s[j+i] && (arr[j+1][j+i-1]>0 || i==1)){// Finding whether the pres. indices form a palin. substring or not.
                    arr[j][j+i]=2+arr[j+1][j+i-1]; 
                    count++;// If they are palindrome increasing the count. 
                }
            }
        }
        //cout<<"the count is: "<<count<<endl;
        return count;//Returning the final count fo palin. substrings.
    }
};