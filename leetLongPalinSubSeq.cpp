/*
516. Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".

//*********************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.length()==0)
            return 0;
          stack<char> st;
          string ans="";
          int size=s.length();
          int arr[size][size]={0};
          for(int i=0;i<size;i++)
              arr[i][i]=1;
          for(int i=size-2;i>=0;i--){
              for(int j=i+1;j<size;j++){
                  if(s[i]==s[j])
                      arr[i][j]=2+arr[i+1][j-1];
                  else
                      arr[i][j]=max(arr[i+1][j], arr[i][j-1]);
              }
          }
        /*
          cout<<"The array contents are: "<<endl;
          for(int a=0;a<size;a++){
              for(int b=0;b<size;b++)
                  cout<< arr[a][b]<<" ";
              cout<<endl;
          }
          */
        
          cout<<"The answer is: "<<arr[0][(size-1)]<<endl;
        return arr[0][(size-1)];
    }
};