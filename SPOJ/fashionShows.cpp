/*

//****************************************************FASHION - Fashion Shows.*******************************************************
https://www.spoj.com/problems/FASHION/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Greedy based solution. Here, so as to get maximum sum of hotness pairs, we pair the maxm. valued men with women, whose 
// multiplying will lead to best contribution each of the two numbers could give to the final count. So, we sort the two arrays,
// multiply the numbers in them from largest to smallest values and add to final count.







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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    
    int tests;
    cin>>tests;
    int len, res=0;

    for(int a=0;a<tests;a++){
        cin>>len;
        vector<int>u(len), v(len);
        for(int i=0;i<len;i++) cin>>u[i];
        for(int i=0;i<len;i++) cin>>v[i];
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        res=0;
        for(int i=len-1;i>=0;i--) res+=u[i]*v[i];
        cout<<res<<endl;

    }
    return 0;
}