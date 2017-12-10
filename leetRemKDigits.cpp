/*

//********************************************************402. Remove K Digits.**************************************************

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.



//Time Complexity: O(n).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
// The main essence is to remove those integers which are bigger than it's following integers, until the req. no. of deletions are done.
// If there are no num. bigger than its follo. elements/ If after implement. the above logic for the entire string& req. del aren't reached.
// then the delte elem. from the end, as the resulting string will be having non decreasing int., so greater valued int(i.e., from the end.)-
//- needs to be delted, resulting in the final result.
   
class Solution {
public:
    string removeKdigits(string s, int k) {
        int len=s.length(), count=0;
        stack<int> u;
        string t;
        for(int i=0;i<s.length();i++){
            int temp=stoi(s.substr(i,1));
            while(u.size()>0 && u.top()>temp && count<k){//If an elem. is greater than it's follow. elem., delete it.
                t.erase(t.length()-1,1);
                u.pop();
                count++;
            }
            u.push(temp);
            t+=s[i];
            //cout<<"reslut string is by index i: "<<i<<" is: "<<t<<" stack's top is: "<<u.top()<<endl;
        }
        while(t.length()>0 && count<k){					// If still deltions are allowed, then delete from the end.
            t.erase(t.length()-1,1);
            count++;
        }
        int i=0;
        while( i<t.length() && t.compare(i,1,"0")==0)	// Delting the leading zeroes.
            t.erase(i,1);
        if(t.length()==0)								// IF the resulting string is ""(NULL). Then return "0", as per the question.
            t+="0";
        //cout<<"Result is: "<<t<<endl;
        return t;
    }
};