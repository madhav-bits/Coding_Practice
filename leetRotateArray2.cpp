#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

/*
Rotate a given array. Rotates the part which we want to shift right, rotates the part which we want to shifted left, 
rotates the entire array, which results in the desired array state.

*/


vector<int> rotate(vector<int> v, int begin, int end){
  int temp;
  while(begin<end){
    temp=v[begin];
    v[begin]=v[end];
    v[end]=temp;
    begin++;
    end--;
  }
  return v;
}

vector<int> rotateArray(vector<int> v, int target){
  v=rotate(v,0, target-1);// Rotates the part which we want to shift to right.
  v=rotate(v, target, v.size()-1);// Rotates the part which won't be shifted to left.
  v=rotate(v,0, v.size()-1);// Rotates the entire array.
  return v;
}


int main(){
    cout<<"Hi"<<endl;
    int arr[]={1,4,7,9,11,14,17,21};// These are stock values for a certain days.
    vector<int> v;
    int target=3;
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++)
      v.push_back(arr[i]);
    v=rotateArray(v,target);
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<endl;
    return 0;
}