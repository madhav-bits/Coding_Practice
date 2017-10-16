/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, 
then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
Can you solve it in O(n) time with only O(k) extra space?

//***********************************************************THIS IS LEET ACCEPTED CODE.*************************************************

*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& v, int k) {
        int count=0; int size=v.size();
        map<string, int>m; map<int, vector<string>, greater<int>> n; map<string,int> ::iterator it1;
        map<int, vector<string>> ::iterator it2;
        for(int i=0;i<size;i++){
            if(m.find(v[i])!= m.end())
                m[v[i]]++;
            else
                m[v[i]]=1;
        }
        
        vector<string> u;
        for(it1=m.begin();it1!=m.end();it1++){
            n[it1->second].push_back(it1->first);
            //cout<<"1 Key is: "<<it1->first<<"  Value is: "<<it1->second<<endl;
        }
        //for(it2=n.begin();it2!=n.end();it2++)
        //    cout<<"2 Key is: "<<it2->first<<"  Value is: "<<it2->second[0]<<endl;
        it2=n.begin();
        for(int i=1;i<=k;i){
            for(int j=0;j<it2->second.size() && i<=k;j++){
                u.push_back(it2->second[j]);
                i++;
            }
            it2++;
        }
        return u;
    }
};