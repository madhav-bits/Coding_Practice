/*
*
//******************************************************************Pretty Json.***********************************************************

https://www.interviewbit.com/problems/pretty-json/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.



["foo", {"bar":["baz",null,1.0,2]}]





// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS IB ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS IB ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is iteration based. Here, we iterate through the string, at crucial junctures like ',', '{','}','[',']', we take some indent
// related decisions and form the string and push them into final result accordingly.









void getSpace(int count, string&temp){
    int x=0;
    while(x<count){
        temp+="\t";
        x++;
    }
    return ;
}
vector<string> Solution::prettyJSON(string s) {
    vector<string>res;
    int count=0;
    string temp="";
    int i=0;
    while(i<s.length()){
        int x=0;
        if(s[i]==',' || s[i]=='[' || s[i]==']' || s[i]=='{' || s[i]=='}'){
            if(s[i]==',') temp+=s[i];
            
            if((s[i]==']' || s[i]=='}') && (i+1<s.length() && s[i+1]==',')){
                if(temp.length()>count) res.push_back(temp);
                temp="";
                count--;
                getSpace(count, temp);
                temp+=s[i];    
            } 
            
            if(s[i]=='[' || s[i]=='{'){
                if(temp.length()>count) res.push_back(temp);
                temp="";
                getSpace(count, temp);
                temp+=s[i];
                if(temp.length()>count) res.push_back(temp);
                temp="";
                count++;
                getSpace(count, temp);
            }
            if(s[i]==','){
                if(temp.length()>0) res.push_back(temp);
                temp="";
                getSpace(count, temp);
            }
            if((s[i]==']' || s[i]=='}')&& (i+1>=s.length() || (i+1<s.length() && s[i+1]!=','))){
                if(temp.length()>count) res.push_back(temp);
                temp="";
                count--;
                getSpace(count, temp);
                temp+=s[i];
                if(temp.length()>count) res.push_back(temp);
                temp="";
                getSpace(count, temp);
                
            }
        }
        else{
            temp+=s[i];
        }
        i++;
    }
    
    return res;
}
