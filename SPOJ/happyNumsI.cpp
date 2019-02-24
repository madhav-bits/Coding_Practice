/*

//****************************************************HPYNOS - Happy Numbers I.*******************************************************
https://www.spoj.com/problems/FCTRL/




Time Complexity:O(logn).                                                                                                                                                                                             
Space Complexity:O(logn).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(logn).                                                 // Not exactly, as in every step, the sum of squares reduces the given num.                                        
// Space Complexity:O(logn).                                                   
// This is Map based solution. Here, we calculate the square of the digits, and push them into set, to check if the same square sum 
// is encountered once again. If we encounter, same sum once again, then we can't reach 1.If we reach 1, we return #steps till then.






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

    
    
    long long int num;
    cin>>num;
    // cout<<"The num: "<<num<<endl;
    unordered_set<int>st;
    st.insert(num);
    long long int count=0;
    while(num!=1){
        long long int temp=num, fol=0;
        while(temp>0){
            fol+=(temp%10)*(temp%10);
            temp/=10;
        }
        // cout<<"fol: "<<fol<<endl;
        if(st.count(fol)==1) break;
        st.insert(fol);
        count++;
        num=fol;
    }
    if(num==1) cout<<count<<endl;
    else cout<<-1<<endl;

    return 0;
}