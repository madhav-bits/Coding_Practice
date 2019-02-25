/*

//**********************************************MATRIOSH - Generalized Matrioshkas.**************************************************
https://www.spoj.com/problems/MATRIOSH/




Time Complexity:O(n).
Space Complexity:O(n).

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).
// Space Complexity:O(n).
// This is Stack based solution. Here, since we need to take care of sum of volumes at various levels, we take two stacks, one to
// keep track of unmatched opening, other to keep track of sum of volumes of siblings. On entering inside a doll, we push an empty
// sum of siblings count of 0 into stack. On reaching end of curr. doll, we check if sum of siblings is less than doll volume, if
// not we return false, if true we remove sibling total volume from stack and add curr. vol to it's sibling's total volume. Thus, at
// end of iteration, we need to have all dolls openings matched to closings.







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
#include <sstream>



using namespace std;



bool checkMatr2(vector<int>&v){
  stack<int>st, sum;
  sum.push(0);
  for(int i=0;i<v.size();i++){
    if(v[i]<0){
      st.push(v[i]);
      sum.push(0);
    }else{
      // cout<<"sum: "<<sum.top()<<" for v[i]: "<<v[i]<<endl;
      if(st.empty() || st.top()!=-1*v[i] || sum.top()>=v[i]) return false;
      sum.pop();
      st.pop();
      sum.top()=sum.top()+v[i];
    }
  }
  // cout<<"adfa"<<endl;
  if(!st.empty()) return false;
  return true;
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");


    string s;
    while(getline(cin, s)){
        // cout<<" str: "<<s<<endl;
        stringstream ss(s);
        vector<int>v;
        int val;
        while(ss>>val) v.push_back(val);
        bool res=checkMatr2(v);
        if(res) cout<<":-) Matrioshka!"<<endl;
        else cout<<":-( Try again."<<endl;
    }

    return 0;
}
