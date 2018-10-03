/*
*
//******************************************************Lexicographically Largest Substring.***********************************************


Given a string, return the lexicographically largest substring of it.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



"abcddedea"


"abcdedcdea"


"dcba"

"abcd"

"aecb"



// Time Complexity: O(n^2).  
// Space Complexity: O(n).

//********************************************************THIS IS WORKING CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*********************************************************THIS IS WORKING CODE.***************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is iteration based. We maintain largest substring encountered till now, compare it with substring starting at various starting 
// indices. The comparision takes O(n)/linear time at every index. So, it's O(n^2) complexity.








#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>



using namespace std;




string findSubstr(string s){
 // string res="";
  int index=-1;																// We track the largest substr with it's start index.
  for(int i=0;i<s.length();i++){
    if(index==-1){
      index=i;
    } 
    else if(s[i]>s[index]){													// IF largest char encountered, update larget substr's start index.
      index=i;  
    } 
    else if(s[i]==s[index]){												// Comparing curr. largest substr with substr starting at index-"i".
      int st=i;																// If first chars match.
      int k=i, j=index;
      while(k<s.length() && s[j]==s[k]){
        j++;k++;
      }  
      if(k==s.length()) return s.substr(j);									// If end is reached, return curr. largest substr.
      else if(s[k]>s[j]){													// If curr. substr is larger, update the start of largest substr.
        index=st;
      }

    }
  }
  //cout<<"index: "<<index<<endl;
  return s.substr(index);													// Return the largest substr.
}  
  

int main() {

 string s="abcdedcdea";


string res= findSubstr(s);
cout<<"res: "<<res<<endl;

return 0;
}











//************************************************************Solution 2:************************************************************
//*********************************************************THIS IS WORKING CODE.***************************************************
// Time Complexity: O(n^2).
// Space Complexity: O(n).	
// This algorithm is iteration based. We maintain largest substring encountered till now, compare it with substring starting at various starting 
// indices. The comparision takes O(n)/linear time at every index. So, it's O(n^2) complexity.
// This is Simpler execution with Syntactic Sugar.









#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>



using namespace std;




string findSubstr(string s){
 
	 string res="";
	 for(int i=0;i<s.length();i++){
		 res=max(res, s.substr(i));											// Comparing largest substr with Substring starting at index "i".
	 }
	 return res;
}  
  

int main() {

 string s="abcdedcdea";


string res= findSubstr(s);
cout<<"res: "<<res<<endl;

return 0;
}