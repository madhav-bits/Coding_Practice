/*
*
//**********************************************************763. Partition Labels.***************************************************

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in 
at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.



*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.

"abcd"
"abcbadefged"
"a"


// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).	
// Space Complexity: O(n).	
// This algorithm iterates the array, at each index check it it's first occurance of a char, if it is update the index in start hashmap and update
// last hashmap which stores the last occurance's index. In the first iteration, at each index, we check whether that index is first/last index, if
// it is inc. the sum variable accordingly( which meant how many chars have first occured and are expected to come after this index. We want those
// indices, where the sum variable is zero. Store in vector, distance b/w consecutive sum=0 indices.



class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> start,close;
        vector<int> v;
        for(int i=0;i<s.length();i++){
            if(start.count(s[i])==0) start[s[i]]=i;
            close[s[i]]=i;
        }
        //for(auto it=start.begin();it!=start.end();it++)
        //    cout<<"key is: "<<it->first<<" and index is: "<<it->second<<endl;
        int sum=0;
        int st=0;
        for(int i=0;i<s.length();i++){
            if(start[s[i]]==i) sum++;						// If this is the first occurance of that char.
            if(close[s[i]]==i) sum--;						// If this is the last occurance of that char.
            if(sum==0){										// No, chars which first occured prior to this index, won't occur after this index.
                v.push_back(i-st+1);						// Pushing into vector, length b/w successive sum==0 indices(substring length).
                st=i+1;										// Marking the beginning of next substring, to calc. diff b/w succ. sum=0 indices.
            }
        }
        return v;											// Returning all those substrings lengths.
    }
};