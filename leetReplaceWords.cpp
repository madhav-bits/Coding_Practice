/*

//****************************************************648. Replace Words***********************************************

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's 
call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence 
with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000


//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    string replaceWords(vector<string>& v, string s) {
        unordered_map<string,int> m;
        for(int i=0;i<v.size();i++)
            m[v[i]]=1;
        
        string t="";// The final result string.
        for(int i=0;i<s.length();i++){
            if(s.compare(i,1," ")!=0){
                int a=0;
                string u="";// Intitializing the temp string to "".
                while(s.compare(i,1," ")!=0 && i<s.length()){
                    u+=s[i];
                    if(a==0 && m.find(u)!=m.end()){// a=1 says that, there is a subarray of this string in the map.
                        t+=u;
                        a=1;
                    }
                    i++;
                }
                if(a==0)// If no subarray exists in map, then the whole string is passed to new string.
                    t+=u;
                i--;// In the last iteration, the curr. elem goes to " ", so reverting back to str elem., such that else condi.
            }// passes the " " into the new string.
            
            else// If a white space is encountered directly pushed to output string.
                t+=s[i];
        }
        //cout<<"the result is: "<<t<<endl;
        return t;
    }
};