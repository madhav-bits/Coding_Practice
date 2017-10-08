#include<cstdlib>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<cstring>
#include<deque>

using namespace std;

/*
Longest Substring without repetition.
This code makes use of two datatypes- double ended queues and hash maps. 
** This is Leetcode accepted code.
*/


int maxVolume(string s){
  //cout<<"Size of vector is: "<<v[0]<<endl;
  unordered_map<char, int> m;
  deque<int> dq;
  
  int max=0; int count=0;
  for(int i=0;i<s.size();i++){
    if(m.find(s[i])== m.end()){
      m[s[i]]=i;
      dq.push_back(s[i]);
      count=dq.size();
      cout<<"THe count is: "<<count<<"element is:"<<s[i]<<endl;
      if(count>max)
        max=count;
    }
    else{
      deque<int> :: iterator it;
      it=dq.begin();
      while(*it!=s[i]){
        cout<<"Removing element is: "<<char(dq.front())<<endl;
        dq.pop_front();
        m.erase(*it);
        it++;
      }
      dq.pop_front();
      //m.erase(dq.front());
      dq.push_back(s[i]);
      if(count>max)
        max=count;
      count=dq.size();
      cout<<"count is: "<<count<<"repeat element is: "<<s[i]<<endl;
      m[s[i]]=1;//As part of values store the index of the value and try.
    }
  }
  return max;
}


int main(){
    cout<<"Hi"<<endl;
    char arr[]={"tmmzuxt"};// These are stock values for a certain days.
    string s="abcabcbb";
    cout<<"Size of arrayyyy is: "<<s.size()<<endl;
    vector<char> v;
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Size of array is: "<<size<<endl;
    for(int i=0;i<size-1;i++)
      v.push_back(arr[i]);
    int volume=maxVolume(s);
    cout<<"Max length non repititive substring is: "<<volume<<endl;
    return 0;
}