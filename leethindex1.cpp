/*

//*********************************************************274. H-Index.*************************************************
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 
citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations
 each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

*******************************************************THIS IS LEET ACCEPTED CODE.**************************************
*/

class Solution {
public:
    int hIndex(vector<int>& v) {
          sort(v.begin(), v.end());
          if(v.size()==0)
            return 0;
          int hindex=0;
          //cout<<v[0]<<endl;
          map<int, int> m;
          for(int i=0;i<v.size();i++){
            if(m.find(v[i])!=m.end())
              m[v[i]]+=1;
            else
              m[v[i]]=1;
          }
        cout<<"xxxxxx: "<<m[1]<<endl;
          int temp=0;
          map<int, int>::reverse_iterator it1;
          for( it1=m.rbegin();it1!=m.rend();it1++){
            cout<<"key is: "<<it1->first<<endl;
            if(it1!=m.rbegin()){
                cout<<"key scanning is: "<<it1->first<<endl;
              if(it1->first>=it1->second && it1->second>hindex)
                hindex=it1->second;  
              it1->second+=temp;
              cout<<"new it second is: "<<it1->second<<"new hindex is: "<<hindex<<endl;
              if(it1->first>=it1->second && it1->second>hindex)
                hindex=it1->second;
              else if(it1->first>hindex) 
                  hindex=it1->first;
            }
            else{
                //temp=it1->second;
              if(it1->first>=it1->second)
                hindex=it1->second;
              else if( it1->first ==1 && it1->second >=1)
                  hindex=1;
              else if(it1->second>= it1->first )
                  hindex=it1->first;
            }
              temp=it1->second;
          }
          cout<<it1->first<<endl;
        return hindex;
    }
};

//******************************************** Solution 2. THIS IS A LINEAR TIME SOLUTION.**********************************
//********************************************FOR BINARY SEARCH SOLUTION REFER TO 275. H-INDEX II PROBLEM.******************

class Solution {
public:
    int hIndex(vector<int>& v) {
		sort(v.begin(), v.end());
        int hIndex=0, j=1;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]>=j)// We are actually findng the left most index which satisfies this condition which is the true-
                hIndex=j;//- h-index, i.e., "other N − h papers have no more than h citations each."
            j++;
        }
        
        return hIndex;
    }
};