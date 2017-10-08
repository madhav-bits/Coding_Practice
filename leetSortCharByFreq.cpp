#include<cstdlib>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

********************************************THIS IS LEET ACCEPTED CODE.********************************************
*/



string frequency( string s){
  map<char, int> m;
  vector< pair<char, int> > v;
  map<char, int>::iterator it;
  for(int i=0;i<s.length();i++){
    if(m.find(s[i])!=m.end())
      m[s[i]]+=1;
    else
      m[s[i]]=1;
  }
  
  for(it=m.begin();it!=m.end();it++){
    v.push_back(*it);
  }
  sort(v.begin(), v.end(), [=] (pair<char, int> &a, pair<char,int> &b){return a.second>b.second;});
  //cout<<"First element is: "<< v[0].first<<endl;
  string t;
  for(int i=0;i<v.size();i++){
    int count=m[v[i].first];
    while(count>0){
      cout<<"strings are: "<<v[i].first<<endl;// This line(print) is increasing the run time, so deleted it while executing in the leet-
      t+=(v[i].first);// to meet the time limitations.
      count--;
    }
  }
  cout<<"T is: "<<t<<endl;
  return t;
}

int main(){
  string s,t;
  s="tree";
  t=frequency(s);
  cout<<"The final output based on frequency is: "<<t<<endl;
}