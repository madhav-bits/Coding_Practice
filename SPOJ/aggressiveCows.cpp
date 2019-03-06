/*

//**************************************************AGGRCOW - Aggressive cows.******************************************************
https://www.spoj.com/problems/AGGRCOW/




Time Complexity:O(log(maxm dist)*logn).                                                                                                                                                                                             
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(log(maxm dist)*logn).                                                  
// Space Complexity:O(n).                                                   
// This is Binary Search based solution. Here, we find the largest min. possible distance between all cows(Atleast this distance has
// to be b/w all the cows). We do Binary Search, b/w min. possible(0) and max. possible(v.back()-v[0]) dist. b/w two cows. If 
// for mid dist. we can't place all the cows with atleast mid dist b/w them, we can't place them with greater distance either, so
// focus on first half of interval, if mid is successful, we include it in the second half of intervals we are gonna focus on.


// For checking, if it's possible to place cows with minm. of mid dist. we do a binary search we first place first cow at index '0',
// we binary search for index which is atleast mid dist. away from it. If found, we place next cow there are further look for psns
// of later cows. If we are able to place all m cows, then mid dist. is suitable else not suitable distance for placing cows.


// At the end of iter. we get largest possible minimum dist. b/w cows.






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




int binSearch(vector<int>&v, int prev, int dist, int index){                // Binary Searching for index with atleast dist gap from curr. index.
    int low=index, high=v.size()-1;

    while(low<high){
        int mid=(low+high)/2;
        if(v[mid]-prev<dist) low=mid+1;
        else high=mid;
    }
    return low;

}



bool isValid(vector<int>&v, int target, int dist){                          // Checking whether it's possible to place cows with minm. dist of (dist) b/w them.
    int cnt=1, prev=v[0];
    int index=1;
    // cout<<"min dist: "<<dist<<endl;
    while(index<v.size()){
        int j=binSearch(v,prev,dist,index);
        // cout<<"next j: "<<j<<endl;
        if(v[j]-prev<dist) return false;
        if(target-cnt>v.size()-j) return false;
        cnt++;
        if(cnt==target) return true;
        prev=v[j];
        index=j+1;
    }
    return false;
}



int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int tests, stalls, cows;
    cin>>tests;
    for(int a=0;a<tests;a++){
        cin>>stalls>>cows;
        vector<int>v(stalls,0);
        for(int i=0;i<stalls;i++) cin>>v[i];
        sort(v.begin(), v.end());
        if(cows<=1){
            cout<<v.back()<<endl;
            continue;
        }
        int low=0, high=v.back()-v[0];                                      // Smallest, largest allowed minm. dist. b/w cows.
        while(low<high){
            int mid=(low+high)/2+1;
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            if(isValid(v,cows,mid)) low=mid;
            else high=mid-1;
        }    
        cout<<low<<endl;
    }
    

    return 0;
}
