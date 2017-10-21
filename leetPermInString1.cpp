/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
//***************************************************THIS IS LEET ACCEPTED SOLUTION.*****************************************
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m,n;
        queue<char> q;
        if(s1.length()==0 && s2.length()==0)
            return 0;
        if(s1.length()==0)
            return 1;
        
        for(int i=0;i<s1.length();i++){
            if(m.find(s1[i])!=m.end())
                m[s1[i]]+=1;
            else
                m[s1[i]]=1;
        }
        n=m;
        for(int i=0;i<s2.length();i++){
            //n=m;
            int b=0;
            while(n.find(s2[i])!=n.end() && n[s2[i]]>0 && i<s2.length()){
                b=1;
                //cout<<"Character under consideration is: "<<s2[i]<<endl;
                q.push(s2[i]);
                n[s2[i]]--;
                if(n[s2[i]]==0)
                    n.erase(s2[i]);
                i++;
            }
            //cout<<"Break and the size of queue is: "<<q.size()<<endl;
            if(n.empty()==1)
                return 1;
            //cout<<"Break element is: "<<s2[i]<<"index is: "<<i<<endl;
            if(m.find(s2[i])!= m.end() && !q.empty()){
                //cout<<"To be removed element is: "<<q.front()<<endl;
                char d=q.front();
                while(d!=s2[i]){
                    q.pop();
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
        return 0;
    }
};