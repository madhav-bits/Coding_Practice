/*
5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

//***********************************************************THIS IS LEET ACCPETED CODE.**********************************************
*/
class Solution {
public:
    string longestPalindrome(string s) {
          stack<char> st; int begin=0;int end=0;int longest=0;
          string ans="";
        if(s.length()==0)
            return ans;
          int size=s.length();
          int arr[size][size]={0};
          for(int i=0;i<size;i++)//Initializing all the base cases.
              arr[i][i]=1;
        
          for(int i=size-2;i>=0;i--){
              for(int j=i+1;j<size;j++){
                  if(s[i]==s[j] && (arr[i+1][j-1]>0 || i+1==j)){
                      arr[i][j]=2+arr[i+1][j-1];
                      if(arr[i][j]>longest ){
                          longest=arr[i][j];
                          begin=i;// Stores the beginning and the end of the longest palindrome till then.  
                          end=j;
                      }
                  }
                  else
                    arr[i][j]=0;
              }
          }
        //cout<<"Longest is: "<<longest<<endl;
        if(longest==0)
            return s.substr(0,1);
        else
            return s.substr(begin,(end-begin+1));// Directly prints the longest palindromic substring.
    }
};