/*

//*******************************************************NPC2014F - Field.***********************************************************
https://www.spoj.com/problems/NPC2014F/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Sliding Window based solution. Here, since we are allowed to have extra chars in the window, we take in chars and dec. 
// the rem(how many more chars are needed to satisfy minm. cdn) only if we access chars which are needed, not when we are accpeting
// chars. After adding every char, we can try to remove chars from beginning which are in excess to minm. requirement. If we get rem==0, 
// we try to update the minm. window length. After the iter. we print the minm. window length satisfying given cdns. If we haven't 
// found any such window, we print "Andy Ropopo".







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






int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int len;
    cin>>len;
    string s="";
    cin>>s;
    vector<int>tar(26,INT_MIN);
    int k, num, res=INT_MAX, rem=0;
    char ch;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>num>>ch;
        // cout<<"num: "<<num<<" and ch: "<<ch<<endl;
        tar[ch-'a']=num;
        rem+=num;
    }
    int start=0, close=0;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        close=i;
        if(tar[c-'a']==INT_MIN) continue;
        tar[c-'a']--;
        if(tar[c-'a']>=0) rem--;
        while(start<close && tar[s[start]-'a']<0){                          // Removing excess chars from the beginning.
            tar[s[start]-'a']++;
            start++;
        }

        if(rem==0 && close-start+1<res){
            res=close-start+1;
            // cout<<"start: "<<start<<" and close: "<<close<<endl;    
        }
    }
    if(res==INT_MAX) cout<<"Andy rapopo"<<endl;
    else cout<<res<<endl;

    return 0;
}
