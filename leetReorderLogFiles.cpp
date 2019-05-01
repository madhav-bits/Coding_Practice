/*
*
//********************************************************937. Reorder Log Files.*************************************************

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring 
identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Note:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","f1 zct car"]


["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","z1 zct car"]



// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Custom sorting based.Here, we first iter. over given list of strs and divide them into two sets, one is of letter logs, where
// first elem. in remaining str except identifier and the identifier, second is list of indices of digit logs. Then we sort letter logs, first
// based on remaining str, if they are equal we compare entire string. Then, we add entire






class Solution {
public:
    
    struct comp{															// Custom sorting letter logs.
      bool operator()(vector<string>&lt, vector<string>&rt){
          return (lt[1]<rt[1] ||(lt[1]==rt[1] && lt[0]<rt[0]));
      }  
    };
    
    vector<string> reorderLogFiles(vector<string>& v) {
        if(v.size()<=1) return v;
        vector<int>digits;													// Stores indices of digit logs.
        vector<vector<string>>letters;										// Stores split part of letter logs.
        vector<string>res;													// Final result array.
        for(int i=0;i<v.size();i++){
            string token="";
            int j=0;
            while(j<v[i].length() && v[i][j]!=' '){// isalnum(v[i][j])
                token+=v[i][j];
                j++;    
            } 
            j++;
            // cout<<"token: "<<token<<" curr. char: "<<v[i][j]<<endl;
            if(isalpha(v[i][j])){											// If rem. str contains alpha, add {rem. str, token} into letters.
                letters.push_back({token, v[i].substr(j)});
            }else digits.push_back(i);										// ELse, add index into digits array.
        }
        sort(letters.begin(), letters.end(), comp());						// Custom sort based on rem. str, if matches based on token+rem.str.
        for(int i=0;i<letters.size();i++){									// Add letter logs to final result array.
            res.push_back(letters[i][0]+" "+letters[i][1]);
        }
        for(int i=0;i<digits.size();i++){									// Add digit logs in the seq. they are encountered.
            res.push_back(v[digits[i]]);
        }
        return res;															// Return the final sorted list of logs.
    }
};