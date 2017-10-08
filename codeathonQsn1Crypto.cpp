#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>


using namespace std;

//This is a qsn from codeathon of acm group, we are supposed to decrypt a message as indicated in the question.A->Z, Z->A ....

int main(){
  cout<<"Hi"<<endl;
  
  //string s2="52";
  //cout<<int(s2[0])<< "string is: "<<s2[0]<<endl;
  string s="Glwzb dv szev urmzoob hmfxp rmgl. FUh, \" : ullgyzoo hgzwrfn 123456789";
  //cout<<int(s[0])<<endl<<endl<<endl;
  //cout<<char(155-s[0])<<endl;
  //cout<<int(10)<<endl;
  for(int i=0;i<s.length();i++){
    if(int(s[i])>=65 && s[i]<=90)
      s[i]=char(155-int(s[i]));
    else if(int(s[i])>=97 && s[i]<=122)
      s[i]=char(219-int(s[i]));
    else if(int(s[i])>=49 && int(s[i])<=52)
      s[i]=char(106-int(s[i]));
    else if(int(s[i])>=53 && int(s[i])<=57)
      s[i]=char(105-int(s[i]));
  }
  cout<<s<<endl<<endl<<endl;
  
  //cout<<s[58]<<endl;
  cout<<"Length of string is: "<<s.length()<<endl;
  return 0;
  
}