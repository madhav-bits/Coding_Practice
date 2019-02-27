/*

//**************************************************YODANESS - Yodaness Level.******************************************************
https://www.spoj.com/problems/YODANESS/




Time Complexity:O(nlogn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(nlogn).                                                  
// Space Complexity:O(n).                                                   
// This is Merge Sort/Inverse Count based solution. Here, while performing merge sort, we add those numbers, which are smaller but 
// to right of numbers, which can be observed in the merging process. We get their countby (j-mid-1) at every step. At the end of 
// process, we have the array sorted, with inverse count as the result.




// Further reading is needed in this domain of Inverse Count.
// https://www.geeksforgeeks.org/count-inversions-in-an-array-set-2-using-self-balancing-bst/
// https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/











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




void sortArray(vector<int>&v, int low, int high, int &res){// MergeSort Function.
    if(low>=high) return ;
    // if(low==high) return ;
    int mid=(low+high)/2;
    sortArray(v,low, mid, res);
    sortArray(v, mid+1, high, res);
    vector<int>temp(high-low+1);



    //******************************************Merging Process.************************************************
    int i=low, j=mid+1, k=0;
    while(i<=mid && j<=high){
        if(v[i]<v[j]){
            res+=j-(mid+1);
            temp[k]=v[i];
            i++;
        }else{
            temp[k]=v[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        res+=high-mid;
        temp[k++]=v[i++];
    }
    while(j<=high){
        temp[k++]=v[j++];
    }
    for(int i=low;i<=high;i++){
        v[i]=temp[i-low];
    }
    return ;

}





int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests;
    cin>>tests;

    for(int a=0;a<tests;a++){
        int number;
        cin>>number;
        vector<string>u(number);
        // vector<string>v(number);
        unordered_map<string,int>m,n;
        for(int i=0;i<number;i++) cin>>u[i];
        string s="";
        for(int j=0;j<number;j++){
            cin>>s;
            n[s]=j;
        }
        vector<int>v(number);
        for(int i=0;i<number;i++){
            // cout<<n[u[i]]<<" ";
            v[i]=n[u[i]];
        }
        // cout<<endl;
        int res=0;
        sortArray(v,0,number-1, res);
        // for(auto num:v) cout<<num<<" ";
        // cout<<endl;
        cout<<res<<endl;

    }

    return 0;
}