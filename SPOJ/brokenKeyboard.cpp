/*

//***************************************************BROKEN - Broken Keyboard.*******************************************************
https://www.spoj.com/problems/BROKEN/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Sliding Window/ Two Pointers based solution.  Here, we iter. over given array and at any instant we maintain a valid window,
// if in case a window unsatisfies we remove beginning chars so as to make it valid, and at every instant we try to maximize the
// result based on window length.







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
#include<cstdio>



using namespace std;






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int nums;
    string s="";
    cin>>nums;
    while(nums!=0){
        // cout<<"nums; "<<nums<<endl;
        cin.ignore();        
        getline(cin, s);
        // cout<<"string: "<<s<<endl;
        vector<int>occur(256,-1);
        // unordered_map<char,int>occur;
        int index=0;
        int close=0, start=0;
        int dist=0, res=INT_MIN;
        while(index<s.length()){
            char ch=s[index];
            close=index;
            if(occur[ch]!=-1){// occur.count(ch)==1
                occur[ch]=index;
            }else{
                dist++;
                occur[ch]=index;
                if(dist>nums){
                    while(start<close && occur[s[start]]!=start) start++;
                    occur[s[start]]=-1;
                    // occur.erase(s[start]);
                    start++;
                    dist--;
                }
            }
            res=max(res, close-start+1);
            // cout<<"res: "<<res<<" and str: "<<s.substr(start, close-start+1)<<endl;
            index++;
        }
        cout<<res<<endl;
        cin>>nums;
    }

    return 0;
}
