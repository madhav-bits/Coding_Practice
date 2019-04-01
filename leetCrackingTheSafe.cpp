/*
*
//**********************************************************753. Cracking the Safe.***************************************************

There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

You can keep inputting the password, the password will automatically be matched against the last n digits entered.

For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.
Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.
Note:
n will be in the range [1, 4].
k will be in the range [1, 10].
k^n will be at most 4096.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

2
5


3
2

4
8




// Time Complexity: O(k^(k^n)).  
// Space Complexity: O(n*k^n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(k^(k^n)).
// Space Complexity: O(n*k^n).	
// This solution is Greedy algorithm based. Here, we iterate over resulting string,at each step we add next char so as to get a string from 
// the possible key combinations. Last 'n-1' chars of curr. string combines with newly added char and form one of unvisited keys. This greedy
// solution is guaranteed to work because we can assume the given scenario to be graph, where each node would be last 'n-1' chars of result
// string and newly added char to be one of 'k' outward edges. Since, we also have same number of inward edges. Each node has even number of 
// edges, so we can guarantee that Eulerian Cycle exists(Visited edge won't be visited once again), visited key won't be visited once again.
// So, we just focus on last 'n-1' chars and try to add new char to make new unvisited key. We keeep track of visited keys in map, once the
// size of map is equal to target(k^n), we return result string accumulated till then.



// This link has detailed explanation of the algorithm and some discussion on it.
// https://leetcode.com/problems/cracking-the-safe/discuss/110264/Easy-DFS


// This link has detailed explanation of the algorithm:
// https://www.youtube.com/watch?v=iPLQgXUiU14





class Solution {
public:
    
    bool findStr(string &s, unordered_set<string>&st, int target, int n, int k){
        if(st.size()==target) return true;
        // cout<<"s: "<<s<<" and count: "<<count<<endl;
        for(int i=0;i<k;i++){												// Iter. over possible next char.
            s+=i+'0';														// Form new result string with new char.						
            string temp=s.substr(s.length()-n,n);							// Extracting last 'n-1' chars.
            // cout<<"extracted val: "<<val<<" and count: "<<count<<endl;
            if(st.count(temp)==1){											// If key already visited, skip it.
                s.pop_back();
                continue;
            } 
            st.insert(temp);
            if(findStr(s, st, target, n, k)) return true;					// Give recursive call with new result string.
            st.erase(temp);
            s.pop_back();
        }
        return false;
    }
    
    string crackSafe(int n, int k) {
        int target=pow(k,n);												// Total #possible keys.
        string s="";														// Result string.
        for(int i=0;i<n;i++) s+='0';										// Setting up first key.
        unordered_set<string>st;											// Keeps track of visited keys.
        st.insert(s);
        findStr(s,st, target, n, k);										// Recursive call to get final string covering all keys.
        return s;															// Returning result string.
    }
};