/*

You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into
 several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can 
 make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]

//*********************************THIS IS NOT AN ACCEPTED SOLUTION. STILL NEED TO IMPROVE IT.****************************
*/



class Solution {
public:
    bool isPossible(vector<int>& v) {
          map<int, int> m,n;
          int prev=-1; int count=0;
          for(int i=0;i<v.size();i++){
            if(v[i]>prev){
              count++;
              prev=v[i];
            }
            else{
              if(m.find(v[i])!=m.end())
                m[v[i]]+=1;
              else
                m[v[i]]+=1;
            }

            if(count==3){
              count=0;
              n[prev]=1;
              prev=-1;
            }
          }
          map<int, int>::iterator it, it1;
          it1=n.begin();
          while(1){
            count=0;
            prev -1;
            for(it=m.begin();it!=m.end();it++){
              if(count==0 && it1->first< it->first){
                it->second--;
                n.erase(it->first); 
                n[it->first]=1;
              }
              else{
                if(it->first > prev){
                  count++;
                  prev= it->first;
                }
                if(count==0){
                  count=0;
                  n[prev]=1;
                  prev=-1;
                }
              }
            }
            if(prev!= -1)
              return false;
          }
          return true;
    }
};