#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<cstdio>
#include<algorithm>


using namespace std;


/*
Sorting a map based on values by copying it to a vector and then sorting a vector as needed.
*/
//******************************FIGURE OUT SIGNIFICANCE OF LAMBDA FUNCTION USED IN THE SORTING FUNCTION.************************
int main(){
  map<char, int> m;
  map<char, int>::iterator it;
  m['a']=111111;
  m['d']=222;
  m['g']=22;
  m['z']=2;
  vector<pair<char, int>> v;
  for(it=m.begin();it!=m.end();it++){
    v.push_back(*it);
  }
  
  vector<int> u;
  u.push_back(1344);
  u.push_back(1);
  u.push_back(34);
  u.push_back(22);
  
  sort(v.begin(), v.end(), [=](pair<char, int>&a, pair<char,int> &b){ return a.second<b.second; });// Sorting a vector, whose values-
  //are map's key and values, based on values.
  cout<<v[0].first<<endl;//[=] is part of lambda function, don't know it's actual importance need to figure out.
  sort(u.begin(), u.end(), [=]( int &a, int &b){ return a>b; });// Sorting a vector in descending order.
  cout<<"U vector is: "<<u[0]<<endl;
  return 0;
  
}