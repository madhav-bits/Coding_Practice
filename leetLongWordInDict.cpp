/*
*************************************************720. Longest Word in Dictionary*****************************************************

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built 
one character at a time by other words in words. If there is more than one possible answer, return the longest word 
with the smallest lexicographical order.

If there is no answer, return the empty string.
Example 1:
Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
Example 2:
Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
Note:

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

//******************************************************THIS IS LEET ACCEPTED CODE.**********************************************

*/
class Solution {
public:
    string longestWord(vector<string>& v) {
        string s;
        sort(v.begin(),v.end(),[] (const string& a, const string& b){return a.size()<b.size();});
        map<string, int> m;
        for(int i=0;i<v.size();i++)
            m[v[i]]=1;
        map<string, int> ::iterator it;
        int maxm= INT_MIN;
        for(it=m.begin();it!=m.end();it++){
            string t=it->first;
            //cout<<"substring considered is: "<<t.substr(0,t.size()-1)<<endl;
            if(m[t.substr(0,t.size()-1)]>=1 || t.size()==1)
                it->second=t.size();
            else
                it->second=0;
            if(maxm< it->second){
                maxm=it->second;
                s=it->first;
            }
            //cout<<"string considering is: "<<it->first<<" and the val is: "<<it->second<<" maxm val is: "<<maxm<<endl;
        }
        //cout<<"The answer is: "<<s<<endl;
        return s;
    }
};