/*

//*****************************************************JNEXT - Just Next !!!.*********************************************************
https://www.spoj.com/problems/JNEXT/




Time Complexity:O(n).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n).                                                  
// Space Complexity:O(n).                                                   
// This is Stack based solution. Here, we are getting next greatest number, so we iter. past all sorted numbers(Dec. order) from the 
// end, then change the first unsorted num, we have to swap this closest number greater than it from the list of sorted numbers that
// we accumulated till this number.







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

    int tests;
    cin>>tests;
    int nums;
    for(int a=0;a<tests;a++){
        cin>>nums;
        vector<int>v(nums);
        for(int i=0;i<nums;i++) cin>>v[i];
        stack<int>st;
        int index=v.size()-2;
        st.push(v.back());
        while(index>=0 && v[index]>=v[index+1]){                            // Storing all numbers from the end, which are sorted.
            st.push(v[index]);
            index--;
        }
        if(index<0){
            cout<<-1<<endl;
            continue;
        }
        // cout<<"index: "<<index<<endl;
        int j=v.size()-1;
        while(j>index && !st.empty()){                                      // Changing num. from Dec. order to Inc. Order.                   
            v[j]=st.top();
            st.pop();
            j--;
        }
        int k=index;
        while(k<v.size() && v[k]<=v[index]) k++;                            // Iter. to index, which is closely greater than curr. num.      
        swap(v[index], v[k]);
        for(auto num:v) cout<<num;
        cout<<endl;

    }

    return 0;
}
