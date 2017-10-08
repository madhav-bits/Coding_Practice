#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share
 of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock 
 before you buy again).

 **The solution is nothing but summation of all the hike in prices b/w consecutive days when iterated through the array.
 ** Leetcode accepted Solution.
*/

int maxProfit(vector<int> v){
  int profit=0;
  for(int i=1;i<v.size();i++){
    if(v[i]>v[i-1])
      profit+=v[i]-v[i-1];// This calculates the difference b/w consecutive values in case of a hike.
  }
  return profit;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1, 7, 2, 3, 6, 7, 6, 7};// These are stock values for a certain days.
    vector<int> v;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    int profit=maxProfit(v);
    cout<<"Max Profit attainable is: "<<profit<<endl;
    return 0;
}