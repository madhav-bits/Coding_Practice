
/*
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is.
 Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in
 both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows").
 Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows.
 In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

*******************************THIS IS LEET ACCEPTED CODE.**************************************
*/

class Solution {
public:
    string getHint(string s, string t) {
      int bull=0; int cows=0;
      map<int, int> m,n;
      //cout<<"Length is: "<<s.length()<<endl;
      for(int i=0;i<s.length();i++){
        if(s[i]==t[i]){
          bull++;
            //cout<<"s element is: "<<s[i]<<" and t is: "<<t[i]<<endl;
        }
        else{
            if(m.find(s[i])!=m.end())
                m[s[i]]+=1;
            else
                m[s[i]]=1;
            if(n.find(t[i])!=n.end())
                n[t[i]]+=1;
            else
                n[t[i]]=1;
        }
      }
      //cout<<"checking: "<<m[50]<<endl;
      map<int, int>::iterator it, it1;
      for(it=m.begin();it!=m.end();it++){
          int temp=it->second;
          //cout<<"in consideration is: "<<it->first<<"value is: "<<it->first<<endl;
          while(temp>0){
            it1=n.find(it->first);
            if(it1!=n.end()){
                if(it1->second>0){
                    //cout<<"first map element is: "<<it->first<<" m count is: "<<m[it->first]<<" n count is: "<<n[it->first]<<endl;
                    cows++;
                    n[it->first]--;
                    m[it->first]--;
                }
            }
            temp--;
          }
      }
      string finals;
      finals=to_string(bull)+"A"+to_string(cows)+"B";
      //cout<<"Final string is: "<<finals<<endl;
      return finals;
    }
};