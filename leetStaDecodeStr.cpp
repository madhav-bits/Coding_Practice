/*

//********************************************************394. Decode String.****************************************************

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

//These are the test cases I had created and worked on in addition.
//"2[abc]gh3z[cd2[uio]]ef2[]tk"
//"2[abc]gh3z[cd2[uio4[z]]]ef2[]tk"

//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
   
class Solution {
public:
    string decodeString(string s) {
        string t,z;
        stack<string> u;
        stack<int> num;								// Stores the integer, number of times we need to repeat a substring.
        int num1=0, num2;
        for(int i=0;i<s.length();i++){
            //cout<<"Inside for with index i: "<<i<<endl;
            if(isdigit(s[i])){						//Calculating the number of times to repeat a substring.
                //cout<<"inside isdigit for index: "<<i<<" num1 is: "<<num1<<endl;
                num2=stoi(s.substr(i,1));
                num1=num1*10+num2;
                //cout<<"num1 after the index is: "<<num1<<endl;
            }
            else if(s.compare(i,1,"[")==0){			// Substring begins.
                //cout<<"num1 is inside [ is: "<<num1<<endl;
                if(z.length()>0 && num.size()==0)	//If there is no bracket which substring "z" can relate, direct push to result.
                    t+=z;
                num.push(num1);									
                u.push("");				
                num1=0;								//Making the no. of repeat to zero.
            }
            else if(s.compare(i,1,"]")==0){
                //cout<<"top of stack is: "<<u.top()<<" and num is: "<<num.top()<<endl;
                string y="";
                for(int i=0;i<num.top();i++)
                    y+=u.top();
                num.pop();
                if(u.size()>1){						//If this substr. is part of another bracket, then adding this to outer bracket.
                    u.pop();
                    string d="";
                    d=u.top();
                    d+=y;
                    u.pop();
                    u.push(d);
                }
                else{								//If this substr. is not part of another bracket, then direct push to final result.
                    t+=y;
                    u.pop();						//Removing this substring from the substr related stack.
                    //cout<<"t by index: "<<i<<" is: "<<t<<endl;
                }
                z="";
            }
            else{									// Piling up the substr contents to their related substring bracket.
                if(u.size()!=0){
                    z=u.top();
                    z+=s[i];
                    u.pop();
                    u.push(z);
                }
                else								// If a related substr bracket doesn't exist, just store the char's which we will push-
                    z+=s[i];						// - into final result using the conditon in Line-51.
            }
        }
        t+=z;
        return t;									//Giving the fianl result.
    }
};