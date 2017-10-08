
/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*****************************************THIS IS LEET ACCEPTED CODE.*******************************************
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& u, int k) {
        map<int, int> m,n;
        map<int,int>::iterator it;
        vector<pair<int, int>> v;
        vector<int> w;
        for(int i=0;i<u.size();i++){
            if(m.find(u[i])!=m.end())
              m[u[i]]+=1;
            else
              m[u[i]]=1; 
          }
        for(it=m.begin();it!=m.end();it++){
            v.push_back(*it);
        }
        sort(v.begin(),v.end(),[=](pair<int, int> &a, pair<int, int> &b){return a.second>b.second;});
        int count =k;
        int j=0;
        while(k>0){
            w.push_back(v[j].first);
            cout<<"Pushed in element is: "<<v[j].first<<endl;
            j++;
            k--;
        }
        return w;
    }
};