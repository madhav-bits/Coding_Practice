/*
*
//********************************************************792. Number of Matching Subsequences.***********************************************

Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"abcde"
["a","bb","acdedfb","ace",""]




// Time Complexity: O(n).  
// Space Complexity: O(n*n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/








//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n*n).	
// This algorithm iterates the array and stores all the chars indices in a vector. After, that iterates through the dictionary's words, for each
// char of it, it checks for its corresponding index in vector using binary search(upper_bound), until it gets a index ">" prev. char's index.
// If not possible to get one, then we throw error. If we passed through the entire word, without any issues, then that word is a subsequence 
// of the given main word.






class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& v) {
        //cout<<"String is: "<<s<<endl;
        int count=0;
        vector<vector<int>> u(26);
        for(int i=0;i<s.length();i++) u[s[i]-'a'].push_back(i);								// Counting no. of occur. of chars in main string.
        for(int i=0;i<v.size();i++){
            int prev=-1;
            for(int j=0;j<v[i].length();j++){
                auto it=upper_bound(u[v[i][j]-'a'].begin(),u[v[i][j]-'a'].end(),prev);		// Bin. Search to get index of next char. in string.
                if(it==u[v[i][j]-'a'].end()) break;											// If not found, then go to next word in dict.
                else prev=*it;
                if(j==v[i].length()-1) count++;												// If iter. entire word, then add to count.
            }
        }
        return count;
    }
};







//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n*n).	
// This algorithm iterates the array and stores all the chars indices in a vector. After, that iterates through the dictionary's words, for each
// char of it, it checks for its corresponding index in vector, until it gets a index ">" prev. char's index. If not possible to get one, then 
// we throw error. If we passed through the entire word, without any issues, then that word is a subsequence of the given main word.
// This algorithm throws TIME LIMIT EXCEEDDED ERROR, the above code is inspired by some other algo. mentioned in the discussed in LeetCode. Almost,
// entirely similar to my algo.



class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& v) {
        //cout<<"String is: "<<s<<endl;
        map<char,queue<int>> m,n;											// To store, the indices of all chars of main string in a queue.
          for(int i=0;i<s.length();i++) m[s[i]].push(i);
          n=m;
          int count=0;
          for(int i=0;i<v.size();i++){
            //cout<<"Substring is: "<<v[i]<<endl;
            n=m;
            int curr,prev=-1;
            for(int j=0;j<v[i].length();j++){
                if(n.count(v[i][j])==1){
                    while(!n[v[i][j]].empty() && n[v[i][j]].front()<prev){	// To get index of curr. char of dict. word in the main string 
                        n[v[i][j]].pop();									// that is ">"  index of prev. char of dict. word in main string.
                    }
                  if(n[v[i][j]].empty()){									// If chars indices are over, then del. the char. entry from the map.
                      n.erase(v[i][j]);
                      break;
                  }
                  curr=n[v[i][j]].front();									// Updating the prev. index to the next char.
                    n[v[i][j]].pop();
                  //cout<<"Curr is: "<<curr<<" and for char is: "<<v[i][j]<<endl;
                  
                  //if(curr<=prev) break;
                  
                  prev=curr;
                }
                else break;													// If the char. is not found in main string, then conti. with next word.
                if(j==v[i].length()-1){
                    count++;
                    //cout<<"Matched substring is: "<<v[i]<<" and count is: "<<count<<endl;
                }
            }

          }
        return count;														// Returning the total count.
    }
};





