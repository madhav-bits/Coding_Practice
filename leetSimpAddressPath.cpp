/*

//************************************************71. Simplify Path71. Simplify Path***********************************************

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
//***********************************I had thought of these corner cases, but don't know of /. and /.... patterns, I don't know-
//- if such address patterne exists.********************************************************************************************


//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    string simplifyPath(string s) {
        string t,u;
        if(s.length()==0)// If no path is present, returning the null address path("").
            return t;
        vector<string> v;
        for(int i=1;i<s.length();i++){
            if(s.compare(i,1,"/")==0){
                if(u.compare(0,u.length(),"..")==0){
                    if(v.size()>0)
                        v.pop_back();
                }
                else if(u.length()!=0 && u.compare(0,u.length(),".")!=0)// Not pushing the empty braces and /. address paths.
                    v.push_back(u);
                u="";
            }
            else// Augmenting the address value if "/" is not encountered.
                u+=s[i];
        }
        if(u.compare(0,u.length(),"..")==0){// Pop if the last encountered sequence is ".."
            if(v.size()>0)
                v.pop_back();
        }
        else if(u.length()!=0 && u.compare(0,u.length(),".")!=0)// Push if the last encountered sequence is not empty braces-
            v.push_back(u);//- and /. address path.
        
        t="/";// If non empty path is present, base address is: "/".
        if(v.size()==0)
            return t;
        for(int i=0;i<v.size();i++)
            t+=v[i]+"/";// Pushing all the address sequences into the final address variable.
        
        return t.substr(0,t.length()-1);//Avoiding returning the last "/" which comes with the address values.
    }
};