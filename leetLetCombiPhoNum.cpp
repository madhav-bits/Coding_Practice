/*

//******************************************17. Letter Combinations of a Phone Number.***********************************************
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Time Complexity: 2^n.
Space Complexity: O(n).

//*********************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
class Solution {
public:
    vector<string> printResult(string s, int current, string pres, map<int, string> m, vector<string> v){
        int num=int(s[current])-48;
        for(int i=0;i<m[num].length(); i++){
            if(current==s.length()-1){
                //cout<<"To be pushed elem. is: "<<pres+m[num][i]<< " and pres is: "<<pres<<endl;
                v.push_back(pres+m[num][i]);
            }
            //string pres2; //pres2.push_back(string(pres)+string(m[num][i]));
            string pres2=pres+m[num][i];
            if(current<s.length()-1)
                v=printResult(s, current+1, pres2,m,v);
        }
        return v;
    }
    vector<string> letterCombinations(string s) {
        vector<string> v;
        map<int, string> m;
        m[1]="";m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
        if(s.length()==0|| s.find("1")!=string::npos )
            return v;
        v=printResult(s, 0, "",m,v);
        return v;
    }
};