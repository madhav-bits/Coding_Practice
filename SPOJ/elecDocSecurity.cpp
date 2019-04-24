/*

//**********************************************EDS - Electronic Document Security.**************************************************
https://www.spoj.com/problems/EDS/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(1).                                                   
// This is String manipulation based solution. Here, to keep track of permissions, we use a boolean array of size 26. Since, the 
// entities are Block Letters, we use a array of size 26. As a whole, we use a 2D array of (26X26).







#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>
#include<stack>
#include<string>
#include<cmath>




using namespace std;




void addPermissions(vector<vector<bool>>&v, string &emp, char sign, string &perm){
    // unordered_map<char,int>m;
    // m['a']=0; m['d']=1; m['e']=2; m['r']=3;

    // cout<<"emp: "<<emp<<" sign: "<<sign<<" and perm: "<<perm<<endl;
    for(int i=0;i<emp.length();i++){
        int index=(emp[i]-'A');
        if(sign=='=') v[index]=vector<bool>(26,false);
        for(int j=0;j<perm.length();j++){
            char ch=perm[j];
            if(sign=='+' || sign=='='){
                // cout<<"setting "
                v[index][ch-'a']=true;
            }else if(sign=='-'){
                v[index][ch-'a']=false;
            }
        }
    }
}








string printPerms(vector<vector<bool>>&v){
    // unordered_map<int,char>m;
    // m[0]='a'; m[1]='d'; m[2]='e'; m[3]='r';
    string res="";
    string emp="", prev="", curr="";
    // for(int i=0;i<26;i++){
    //     for(int j=0;j<26;j++)
    //         cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }

    for(int i=0;i<26;i++){
        curr="";
        bool valid=false;
        for(int j=0;j<26;j++){
            if(v[i][j]==true){
                curr+=(j+'a');
                valid=true;    
            } 
        }
        if(valid==false) continue;
        // cout<<"prev: "<<prev<<" and curr: "<<curr<<endl;
        if(prev!="" && prev!=curr){
            res+=emp;
            res+=prev;
            emp="";
        }
        emp+=(i+'A');
        prev=curr;
    }
    res+=emp;
    res+=prev;
    return res;
}






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    string s="";
    vector<vector<bool>>v(26,vector<bool>(26,false));
    int a=1;
    char sign='.';
    cin>>s;
    while(s!="#"){
        v=vector<vector<bool>>(26,vector<bool>(26,false));
        string emp="", perm="";
        int index=0;
        while(index<s.length()){
            emp="";
            while(index<s.length() && s[index]>='A' && s[index]<='Z'){
                emp+=s[index];
                index++;    
            } 
            sign=s[index];    
            perm="";
            index++;
            while(index<s.length() && s[index]!=','){
                perm+=s[index];
                index++;
            }
            addPermissions(v,emp, sign, perm);
            index++;
        }
        string res=printPerms(v);
        cout<<a<<":"<<res<<endl;
        cin>>s;
        a++;
    }

    return 0;
}
