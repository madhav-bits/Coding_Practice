/*

//********************************************************************PPATH - Prime Path.***************************************************************
https://www.spoj.com/problems/PPATH/




Time Complexity:O(n).                                                       
Space Complexity:O(n).

*/


//*****************************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                    
// Space Complexity:O(n).
// This is Breadth First Search based. Here, we start with given string, at each step, we modify the given number by 1 step and also check whether
// the modified num. is prime or not? If its prime and unviisted till now, we push into queue, we do this until we have strings to check or find the
// target number. If target found, return the steps till then, which would be min. steps to reach target num or if the queue goes empty, we return -1, 
// which leads to returning "Impossible".










#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
#include<climits>



using namespace std;



void fillSieve(vector<bool>&v){
    for(int i=2;i*i<=9999;i++){
        if(v[i]==false) continue;
        for(int j=i*i;j<=9999;j+=i) v[j]=false;
    }   
}




int getMoves(int start, int target,vector<bool>&prime){
    if(start==target) return 0;
    unordered_set<string>s;
    queue<int>q;
    q.push(start);
    s.insert(to_string(start));
    int moves=0;
    // string tar=to_string(target);
    while(!q.empty()){
        moves++;
        int len=q.size();
        for(int i=0;i<len;i++){
            int curr=q.front();
            // cout<<"Curr. num: "<<curr<<endl;
            q.pop();
            string str=to_string(curr);
            for(int i=0;i<4;i++){
                    string temp=str;
                for(int k=48;k<=57;k++){
                    if(i==0 && k==48) continue;
                    temp[i]=k;
                    int val=stoi(temp);
                    if(s.count(temp)==0 && prime[val]){
                        // cout<<"fol. num: "<<temp<<endl;
                        if(val==target) return moves;
                        q.push(val);
                        s.insert(temp);
                    }
                }
            }
        }
    }
    return -1;
}




int main() {
    // your code goes here
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");
    int tests;
    vector<bool>prime(10000,true);
    prime[2]=true;
    fillSieve(prime);
    cin>>tests;
    for(int i=0;i<tests;i++){
        int start, target;
        cin>>start>>target;
        int res=getMoves(start,target,prime);
        if(res==-1) cout<<"Impossible"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}