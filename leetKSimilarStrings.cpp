/*
*
//************************************************************854. K-Similar Strings.*****************************************************

Strings A and B are K-similar (for some non-negative integer K) if we can swap the positions of two letters in A exactly K times so that the 
resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:

Input: A = "ab", B = "ba"
Output: 1
Example 2:

Input: A = "abc", B = "bca"
Output: 2
Example 3:

Input: A = "abac", B = "baca"
Output: 2
Example 4:

Input: A = "aabc", B = "abca"
Output: 2
Note:

1 <= A.length == B.length <= 20
A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}





*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


"ddeeffabc"
"cbafededf"



"aabbccddee"
"dcacbedbae"


"dcba"
"abcd"




// Time Complexity: O(2^(n/2)).
// Space Complexity: O(n*2^(n/2)).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^(n/2)).
// Space Complexity: O(n*2^(n/2)).	
// This algorithm is BFS based. Here, we start from given string, at each step, we make sure that atleast one char gets into it's proper place.
// We set a char into it's proper place and push the modified string into Queue for setting else chars. As, we do this process in BFS way, the
// first instant the modified string as target string, we return the moves taken till then.

// Here, at each step, we set the leftmost unset char. in given string.




class Solution {
public:
    int kSimilarity(string s, string t) {
        if(s==t) return 0;
        unordered_set<string>m;												// Used to store state/tracks visited till then.
        int dist=0;															// #Swaps made to get curr. string.
        queue<string>q;														// Stores states which need to be further modified to get target string.
        q.push(s);															// Starting from given string.
        while(!q.empty()){													// Until there are stores to be modified.
            int len=q.size();												// #States obtained for curr. #moves.
            dist++;															// Inc. the moves count.
            for(int i=0;i<len;i++){											// Iter. over states attainable after same #moves.
                string s=q.front();											// Get curr. state.
                q.pop();
                // cout<<"Curr. string: "<<s<<endl;
                int index=0;
                while(index<s.length() && s[index]==t[index]) index++;		// Skipping first chars which are set to that of target string.
                for(int j=index+1;j<s.length();j++){						// Iter. over rest indices to find char to set index -'index'.
                    if(s[j]==t[j] || s[j]!=t[index]) continue;				// If 'i' index is already set, isn't a match for curr. index, skip it.
                    swap(s[j], s[index]);									// Swap the curr. char with char at index 'j'.
                    // cout<<"swapped string: "<<s<<endl;
                    if(s==t) return dist;									// If modified str matches target string, return moves.
                    if(m.count(s)==0){										// If this state/string isn't visited earlier push into queue.
                        q.push(s);
                        m.insert(s);										// Mark this state as visited.
                    }
                    swap(s[j], s[index]);									// Revert back the chars to accomodate else swaps if any.
                }
            }
        }
       return 0; 
    }
};








//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(2^(n/2)).												// Would be lesser than this, as Pruning is done.
// Space Complexity: O(n*2^(n/2)).
// This algorithm is DFS based. Same logic as BFS, here, Pruning also used, that whenever because of a swap if chars are set, that's the best that
// can happen because of a single swap, instead of comparing results from all possible moves from that state, we take this double matching 
// swap and give recursive call on it, we get the best result.

// But, strangely when I had employed Pruning in BFS, I didn't get the proper results, it's failing in some test cases.


// This solution including Pruning is clearly explained, in this link:
// https://leetcode.com/problems/k-similar-strings/discuss/140299/C++-6ms-Solution




class Solution {
public:
    int kSimilarity(string A, string B) {
      for (int i=0; i<A.size(); i++) {
        if (A[i]==B[i]) continue;
        vector<int> matches;
        for (int j=i+1;j<A.size();j++) { 
          if (A[j]==B[i] && A[j]!=B[j]) {
            matches.push_back(j);
            if (A[i]==B[j]) {												// Here is Pruning involving double matching of chars.
              swap(A[i],A[j]);												// As, this is the best move on this state of 'S'.
              return 1+kSimilarity(A.substr(i+1),B.substr(i+1));			// We just give recursive call on this state.
            }
          }
        }
        int best=A.size()-1;
        for (int j: matches) {												// If double move not found, iter. over all possible moves in this round.
            swap(A[i],A[j]);
            best = min(best, 1+kSimilarity(A.substr(i+1),B.substr(i+1)));
            swap(A[i],A[j]);
        }
        return best;
      }
      return 0;
    }
};
