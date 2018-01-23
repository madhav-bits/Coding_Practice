/*
*
//****************************************************712. Minimum ASCII Delete Sum for Two Strings.*********************************************

Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
Note:

0 < s1.length, s2.length <= 1000.
All elements of each string will have an ASCII value in [97, 122].


// Time Complexity: O(n^2).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n^2).
// The algorithm is building from the base cases. If two last elem. mismatch then two strings can be equated by removing the last two. We choose to 
//build from the combination that gives us the min. cost.


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>>v(m+1, vector<int>(n+1,0));
        for(int j=1;j<=n;j++)                       //The case when there are no elements in first string(s1).
            v[0][j]=v[0][j-1]+s2[j-1];
        for(int i=1;i<=m;i++){
            v[i][0]=v[i-1][0]+s1[i-1];              //The case when there are no elements in second string(s2).
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])                //If the elements match.
                    v[i][j]=v[i-1][j-1];
                else                                //If there is a mismatch of elem. either of the elem. can be removed to get the matched string.
                    v[i][j]=min(v[i][j-1]+s2[j-1], v[i-1][j]+s1[i-1]);
            }
        }
        cout<<"The result is: "<<v[m][n]<<endl;
        return v[m][n];
    }
};







//As we use only two lines of DP array at a time. We just initialize those two lines to implement properly.
//**************************************************************CAN DO.***************************************************************
//************************************************************Solution 2:************************************************************
//************************************************************NEED TO WORK ON.************************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>>v(2, vector<int>(n+1,0));
        for(int j=1;j<=n;j++)                       //The case when there are no elements in first string(s1).
            v[0][j]=v[0][j-1]+s2[j-1];
        for(int i=1;i<=m;i++){
            v[1][0]=v[0][0]+s1[i-1];              //The case when there are no elements in second string(s2).
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])                //If the elements match.
                    v[1][j]=v[0][j-1];
                else                                //If there is a mismatch of elem. either of the elem. can be removed to get the matched string.
                    v[1][j]=min(v[1][j-1]+s2[j-1], v[0][j]+s1[i-1]);
            }
			for(int i=1;i<=n;i++)
				v[0][i]=v[1][i];
        }
        cout<<"The result is: "<<v[1][n]<<endl;
        return v[m][n];
    }
};