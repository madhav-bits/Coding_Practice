/*
*
//**********************************************************422. Valid Word Square.***************************************************

Given a sequence of words, check whether it forms a valid word square.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

Note:
The number of words given is at least 1 and does not exceed 500.
Word length will be at least 1 and does not exceed 500.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
[
  "abcd",
  "bnrt",
  "crmy",
  "dtye"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crmy".
The fourth row and fourth column both read "dtye".

Therefore, it is a valid word square.
Example 2:

Input:
[
  "abcd",
  "bnrt",
  "crm",
  "dt"
]

Output:
true

Explanation:
The first row and first column both read "abcd".
The second row and second column both read "bnrt".
The third row and third column both read "crm".
The fourth row and fourth column both read "dt".

Therefore, it is a valid word square.
Example 3:

Input:
[
  "ball",
  "area",
  "read",
  "lady"
]

Output:
false

Explanation:
The third row reads "read" while the third column reads "lead".

Therefore, it is NOT a valid word square.






*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["abcd","bnrt","crm","dt"]


["ball","area","read","lady"]


["abcd","bnrt","crmy","dtye"]



// Time Complexity: O(n^2).  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n^2).
// Space Complexity: O(1).	
// This algorithm is iteration based. We iterate over all rows and clmns, check curr. char with the transposed index, whether they are equal or not?
// If a row has gretaer length than the previous length, then return false, as it's tranposed index won't exist, this avoids iterating the curr. 
// row to get to unreachable row to return false.








class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int len=0;															// Min. length of row encountered till now.
        for(int i=0;i<words.size();i++){
            if(len>0 && words[i].length()>len) return false;				// If curr. row's length>prev. one then return false.
            len=words[i].length();
            for(int j=0;j<len;j++){											// Iterating over curr. row.
                cout<<"Curr. scanning: "<<words[i][j]<<" and: "<<words[j][i]<<endl;
                if(j>words.size() || i>=words[j].length() || words[j][i]!=words[i][j]) return false;// When out of bounds/unmatched index encoun.
            }
        }
        return true;														// If no issues arises, then return true.
    }
};