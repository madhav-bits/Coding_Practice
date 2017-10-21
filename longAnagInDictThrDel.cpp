/*
Given a string and a string dictionary, find the longest string or its anagram in the dictionary that can be formed by 
deleting some characters of the given string. If there are more than one possible results, return the 
longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& v) {
        map<char, int> m,n;
        string s2,s3,t; int count;
        if(s.length()==0 && v.size()==0)
            return t;
        if(v.size()==0)
            return t;
        int arr[v.size()]={0}; int minm=INT_MAX; int index;
        for(int i=0;i<v.size();i++){
            s2=s;s3=v[i]; 
            m.clear();count=s3.length();
            for(int j=0;j<s3.length();j++){
                if(m.find(s3[j])!=m.end())
                    m[s3[j]]+=1;
                else
                    m[s3[j]]=1;
            }
            
            map<char,int>::iterator it1;
            //for(it1=m.begin();it1!=m.end();it1++)
              //  cout<<"Before Scanning key is: "<<it1->first<<" and value is: "<<it1->second<<endl;
            for(int j=0;j<s2.length();j++){
                //cout<<" To be scanned elem. is: "<<s2[j]<<endl;
                if(m.find(s2[j])!=m.end() && m[s2[j]]>0){
                    m[s2[j]]-=1; count--;
                    //cout<<"To be deleted is: "<<s2[j]<< " new count in map for del. elem is: "<<m[s2[j]]<<endl;
                    s2.erase(s2.begin()+j, s2.begin()+j+1); j--;
                    if(m[s2[j]]==0)
                        m.erase(s2[j]);
                }
            }
            //for(it1=m.begin();it1!=m.end();it1++)
                //cout<<"After scanning key is: "<<it1->first<<" and value is: "<<it1->second<<endl;
            //cout<<"After scanning string is: "<<s2<<" count is:"<<count<<endl;
            if(count==0)
                arr[i]=s2.length();
            else
                arr[i]=INT_MAX;
        }
        
        for(int i=0;i<v.size();i++){
            //cout<<"The array length is: "<<arr[i]<<endl;
            if(arr[i]<minm){
                minm=arr[i];
                index=i;
            }
        }
        //cout<<"The min length is: "<<v[index]<<endl;
        if(minm==INT_MAX)
            return t;
        return v[index];
    }
};