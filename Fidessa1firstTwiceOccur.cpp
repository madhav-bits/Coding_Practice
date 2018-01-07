#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;

// This gives the character which had occured more than once in a string and its first occurence is 
// -first of the all the chars that had occured more than once.
//***************************************************FIDESSA TECHNICLA RECRUITING EXAMINATION.****************************************
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



//******************************************THIS IS THE CODE I HAD SUBMITTED IN THE TECHNICAL ROUND EXAMINATION.******************************
//In the  question he hadn't asked about Fail cases. So, I haven't written regarding it.

#include<cstdlib>
#include<vector>
#include<string>
#include<map>
#include<iostream>

using namespace std;


/*
 * Complete the function below.
 */
string findFirstRepeatingChar(string s) {
    int len=s.length();
    map<char, int> m,n;
    for(int i=0;i<len;i++){
        m[s[i]]+=1;
        if(n[s[i]]==0 && m[s[i]]==1)
            n[s[i]]=i ;
    }
    //for(const auto& num:m)
    //    cout<<"Elem are: "<<num.first<< " second: "<<num.second<<endl;
    //for(const auto& num:n)
    //    cout<<"Second Elem are: "<<num.first<< " second: "<<num.second<<endl;
    
    
    map<char,int> ::iterator it, it1; 
    it1=n.begin();
    int minm=INT_MAX;
    for(it=m.begin();it!=m.end();it++, it1++){
        if(it->second>=2)
            minm=min(it1->second, minm);
    }
    //cout<<"minm index is: "<<s[minm]<<endl;
    string t=s.substr(minm,1);
    return t;
}



//As the Tech. round doesn't ask about Fail cases,  I had worked on Fail caess, the below code is modified code containing the fail cases.


#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<climits>



using namespace std;


string findFirstRepeatingChar(string s) {
    int len=s.length(), index=INT_MAX;
    map<char, int> m,n;
    for(int i=0;i<len;i++){
        m[s[i]]+=1;
        if(n[s[i]]==0 && m[s[i]]==1)
            n[s[i]]=i ;
        if(m[s[i]]>=2)								//This finds the least index of elem. repeating twice or more.
            index=min(index, n[s[i]]);				//This part greatly reduces the time complexity, but not Asymptotically.
    }
    //for(const auto& num:m)
    //    cout<<"Elem are: "<<num.first<< " second: "<<num.second<<endl;
    //for(const auto& num:n)
    //    cout<<"Second Elem are: "<<num.first<< " second: "<<num.second<<endl;
    string u;
    if(index==INT_MAX){								//When no elem. repea. twice or more.
      cout<<"Not Exist."<<endl;
      //return u;
    }
    else{
    u=s.substr(index,1);
    cout<<"The answer is: "<<u<<endl;
    }
	
	
    map<char,int> ::iterator it, it1; 
    it1=n.begin();
    int minm=INT_MAX;
    for(it=m.begin();it!=m.end();it++, it1++){
        if(it->second>=2)
            minm=min(it1->second, minm);
    }
    //cout<<"minm index is: "<<s[minm]<<endl;
    string t;
    if(minm==INT_MAX){								//When no elem. repea. twice or more.
      cout<<"Not Exist."<<endl;
      return t;
    }
    t=s.substr(minm,1);
    return t;
}


int main(){
	string s="ABCDabcdbca";
	string t=findFirstRepeatingChar(s);
	cout<<"The result is: "<<t<<endl;
	return 0;
}




