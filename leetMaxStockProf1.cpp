#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

int maxProfit(vector<int> v){
  int profit;
  int diff[v.size()]={0};// Initializing another array which contains diff b/w stock values.
  for(int i=1;i<v.size();i++)// So, it can be solved using Max Sum Subarray problem technique.
    diff[i]=v[i]-v[i-1];
  //cout<<diff[2]<<endl;// Checking whether initialized properly or not.
  int max=0;int max_so_far=0;
  for(int j=0;j<v.size();j++){
    if(diff[j]>=diff[j]+max_so_far)
      max_so_far=diff[j];
    else
      max_so_far+=diff[j];
    if(max_so_far>max)
      max=max_so_far;
      
  }
  return max;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={7, 1, 5, 3, 6, 4};// These are stock values for a certain days.
    vector<int> v;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    int profit=maxProfit(v);
    cout<<"Max Profit attainable is: "<<profit<<endl;
    return 0;
}