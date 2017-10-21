/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

//****************************************THIS IS LEET ACCEPTED SOLUTION.*******************************************************
*/
class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        map<char, int> m,n;
        queue<char> q;
        vector<int> v;
        if(s1.length()==0 && s2.length()==0){
            v.push_back(0);
            return v;
        }
        if(s1.length()==0){
            for(int i=0;i<=s2.length();i++)
                v.push_back(i);
            return v;
        }
        
        for(int i=0;i<s1.length();i++){
            if(m.find(s1[i])!=m.end())
                m[s1[i]]+=1;
            else
                m[s1[i]]=1;
        }
        n=m; int begin;
        for(int i=0;i<s2.length();i++){
            //n=m;
            int b=0; 
            while(n.find(s2[i])!=n.end() && n[s2[i]]>0 && i<s2.length()){
                b=1;
                if(q.empty())
                    begin =i;
                //cout<<"Character under consideration is: "<<s2[i]<<endl;
                q.push(s2[i]);
                n[s2[i]]--;
                if(n[s2[i]]==0)
                    n.erase(s2[i]);
                i++;
            }
            //cout<<"Break and the size of queue is: "<<q.size()<<endl;
            if(n.empty()==1)
                v.push_back(begin);
            //cout<<"Break element is: "<<s2[i]<<"index is: "<<i<<endl;
            if(m.find(s2[i])!= m.end() && !q.empty()){
                //cout<<"To be removed element is: "<<q.front()<<endl;
                char d=q.front();
                while(d!=s2[i]){
                    q.pop(); begin++;
                    if(n.find(d)!=n.end())
                        n[d]+=1;
                    else
                        n[d]=1;
                    //cout<<"new value of char: "<<d<<" in n is: "<< n[d]<<endl;
                    d=q.front();
                }
                
                if(n.find(q.front())!=n.end())
                    n[q.front()]+=1;
                else
                    n[q.front()]=1;//q.push(s2[i]);
                q.pop();
                begin++;
            }
            else{
                n=m;
                q={};
            }
            if(b==1){
                i--;
                //cout<<"decreased i to "<<i<<endl;
            }
        }
        return v;
    }
};