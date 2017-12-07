#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;

// This gives the character which had occured more than once in a string and its first occurence is 
// -first of the all the chars that had occured more than once.
//****************************************THIS QUESTION IS ASKED IN A CODING ROUND FOR A COMPANY.****************************************** 

int main(){
  string s="abcbcddefggfe";
  cout<<"string length is: "<<s.length()<<endl;
  map<char,int> m;
  for(int i=0;i<s.length();i++)//Counts the occurence of the chars.
    m[s[i]]+=1;
  int j=0;
  while(j<s.length()){
    if(m[s[j]]>=2){// When the first char. which occured >=1 found returns it to output.
      cout<<"Match found  and the char is: "<<s[j]<<endl;
      break;
    }
    j++;
  }
  
  return 0;
}