/*
//This solution still required improvement.
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
      float rem=float(numerator)/float(denominator);
      cout<<rem<<endl;
      string s=to_string(rem);
      cout<<"length is: "<<s.length()<<endl;
      //string s=to_string(c);
      cout<<"String is: "<< s<<endl;
      int sizes=s.length();
      cout<<"Size is: "<<sizes<<endl;
      //s.erase(3);
      string t=s;
      sizes=sizes-2;
      cout<<"New sizes is: "<<sizes<<endl;
      int c=1;
      while(1){
        if(s[sizes]==s[sizes-1]){
          sizes=sizes-1;
          c=2;
        }
        else
          break;
      }
      cout<<"after while loop is: "<<sizes<<endl;
      if(int(s[sizes])==48){
        sizes=sizes-1;
        t.erase(sizes+1);  
      }
      else if(c== 2){
        t.erase(sizes);
        cout<<"New t is: "<<t<<endl;
        string x=string("(")+ s[sizes] +")";
        cout<<"x is: "<<x<<endl;
        t.append(x);
      }
      cout<<"FInal sizes is: "<<sizes<<endl;
      //s.erase(sizes+1);
      cout<<"final string is: "<<t<<endl;
      return t;
    }
};