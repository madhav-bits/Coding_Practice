/*
*
//****************************************************738. Monotone Increasing Digits.*********************************************

Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.

(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)

Example 1:
Input: N = 10
Output: 9
Example 2:
Input: N = 1234
Output: 1234
Example 3:
Input: N = 332
Output: 299
Note: N is an integer in the range [0, 10^9].


//These are the examples I had tweaked and worked on.
233332, 3356 10.


// Time Complexity: O(n).
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).
//The algorithm is to find the first occurence where an digit is less than prev. digit. Then replacing all digits following that by "9"
// and then dec. the preceding digit by "1". If the pre. digit is equal ot it's preceding digit, then dec the prev. digit by "1" as long as
// values are equal leaving the last equal digit.
// We are replacing by "9"  as we need largest lesser valued int. satisfying the condition.


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
      int a=0;
      string s=to_string(n);
      int len=s.length();
      if(len==1)
        return n;
      //cout<<"stirng is: "<<s<<endl;
      for(a=0;a<len-1;a++){
        if(s[a]>s[a+1])								//"a+1" digit is voilating the desired property.
        break;
      }
      if(a==len-1)
        return n;
      else{
        //cout<<" a is: "<<a<<endl;
        for(int i=a+1;i<len;i++)					//Starting the first violation replacing all following digits by "9".
        s.replace(i,1,"9");
          if(a>=0){
              while(a-1>=0 && s[a-1]==s[a]){		// Dec. all prev. digits equal to "a" indexed digit except the last one/(Start of string).
                s.replace(a,1,"9");
                a--;
              }
                s.replace(a,1,to_string(s[a]-1-48));// Dec. the "a" index by "1" after the above while loop if while loop satisfied.
            }										// Dec. the non-equal value or equal value if while is satisfied.
          
      }
        
      return stoi(s);
    }
};