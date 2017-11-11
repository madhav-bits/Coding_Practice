/*

//******************************************************49. Group Anagrams.***************************************************
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

Time Complexity: O(nlogn).
Space Complexity: O(n).
//***********************************************THIS IS LEET ACCEPTED CODE.************************************************
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> v;// The solution variable.
        unordered_map<string, vector<int>> m;
        vector<string> t(s.begin(), s.end());//Creating a copy of question and sort it lexographically.
        for(int i=0;i<t.size();i++)
            sort(t[i].begin(), t[i].end());// Sorting the vector's elements( string).
        for(int i=0;i<t.size();i++)
            m[t[i]].push_back(i);// Creating a map with strings as keys and indices as values. Where anagrams would come under same key.
        
        unordered_map<string, vector<int>> ::iterator it;
        for(it=m.begin(); it!=m.end();it++){// Extracting the indices related to a anagram.
            //cout<<"key is: "<<it->first<<" and value is: "<<it->second[0]<<endl;
            vector<string> w;
            for(int j=0;j<it->second.size();j++)
                w.push_back(s[it->second[j]]);// Putting the unsorted original anagrams into a temp. vector and-
            v.push_back(w);//- pushing them in a single go into the final result.
        }
        return v;
    }
};