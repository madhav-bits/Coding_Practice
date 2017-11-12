/*

//********************************************583. Delete Operation for Two Strings.**********************************************

Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where 
in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.

//Time Complexity: O(n^2).
// Space Complexity: O(n^2).

//********************************THIS QUESTION CAN ALSO BE CONSIDERED AS LONGEST COMMON SUBSEQUENCE.***************************
//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    int minDistance(string s1, string s2) {
        int result=0, count=0;
        if(s1.length()==0)
            return s2.length();
        if(s2.length()==0)
            return s1.length();
        int arr[s1.length()][s2.length()]={0};
        //*******************Base Cases.
        for(int i=0;i<s2.length();i++){// Iterating over s2 contents and matching with first char. of s1.
            if(s1[0]==s2[i])
                arr[0][i]=2;
            else if(i>=1)// First the case of comparing 0 and 0 indices, it shouldn't go back causing index access error.
                arr[0][i]=arr[0][i-1];
        }
        //*******************Base Cases.
        for(int i=0;i<s1.length();i++){// Iterating over s1 contents and matching with first char. of s2.
            if(s2[0]==s1[i])
                arr[i][0]=2;
            else if(i>=1)// First the case of comparing 0 and 0 indices, it shouldn't go back causing index access error.
                arr[i][0]=arr[i-1][0];    
        }
        
        for(int i=1; i<s1.length();i++){
            for(int j=1;j<s2.length();j++){
                if(s1[i]==s2[j])
                    arr[i][j]=2+arr[i-1][j-1];
                else
                    arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
                //cout<<"Inside else and the val is: "<<arr[i][j]<<endl;
            }
        }
        //cout<<"the result is: "<<arr[s1.length()-1][s2.length()-1]<<endl;// This is the Longest Common Subsequence.	
        return s1.length()+s2.length()-arr[s1.length()-1][s2.length()-1];
    }
};