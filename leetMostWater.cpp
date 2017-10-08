#include<cstdlib>
#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical 
lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with 
x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

** Leet Accepted Solution.
*/


int maxVolume(vector<int> v){
  int a=0; int b=v.size()-1;
  int max=0;
  while(a<b){
    int c= v[a]<v[b]?v[a]:v[b];
    if(c* (b-a)> max)
      max=c* (b-a);
    if(v[a]>v[b])
      b--;
    else
      a++;
  }
  return max;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1, 7, 2, 3, 6, 17, 8, 9};// These are stock values for a certain days.
    vector<int> v;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    int volume=maxVolume(v);
    cout<<"Max Volume is: "<<volume<<endl;
    return 0;
}