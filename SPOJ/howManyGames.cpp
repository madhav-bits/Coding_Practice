/*

//*********************************************************GAMES - HOW MANY GAMES.********************************************************
https://www.spoj.com/problems/GAMES/




Time Complexity:O(logn).                                                                                                                                                                                             
Space Complexity:O(1).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                  
// Space Complexity:O(1).                                                   
// This is Math based solution. Here, for every input we check for '.' to know whether given num is integer or not , it it's integer
// return 1. else we find the #decimal/fraction places and multiply so as to make number an integer. We form denom with pow(10,#frac)
// The essence is to get fraction into a/b form, after that we calc. the gcd of numer, denom. We divide denom by gcd so as to get
// #days(That's when denom. can be cancelled out).







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



int gcd(int numer,int denom){
    // cout<<"num: "<<numer<<" and denom: "<<denom<<endl;
    if(denom==0) return numer;
    return gcd(denom,numer%denom);
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    cin>>tests;
    // cout<<tests<<endl;
    for(int a=0;a<tests;a++){
        string s;
        cin>>s;
        int index=0;
        while(index<s.length() && s[index]!='.') index++;
        if(s.length()==index) cout<<1<<endl;
        else{
            int num=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='.') continue;
                num=num*10+(s[i]-'0');
            }
            int denom=0;
            denom=pow(10,s.length()-index-1);
            // cout<<num<<" "<<denom<<endl;
            int gcdDiv=gcd(num,denom);
            // cout<<"gcd: "<<gcdDiv<<endl;
            cout<<denom/gcdDiv<<endl;
        }
    }
    return 0;
}