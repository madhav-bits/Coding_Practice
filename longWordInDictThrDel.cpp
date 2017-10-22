/*
524. Longest Word in Dictionary through Deleting

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by 
deleting some characters of the given string. If there are more than one possible results, return the longest 
word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.

//*********************************************************THIS IS LEET ACCEPTED CODE.***********************************************

*/
class Solution {
public:
    int lexSmall(int index, int a, vector<string> v){
      int i=0, j=0; int variable;
      while(i<v[index].length() && j<v[a].length()){
        //cout<<"Elements under consid are: "<<s[i]<< "and "<<t[j]<<endl;
        if(v[index][i]!= v[a][j])
          break;
        i++; j++;
      }
      //cout<<"i is: "<<v[index][i]<<endl;
      //cout<<"j is: "<<v[a][j]<<endl;
      if(v[index][i]<v[a][j])
        return variable=index;
      else
        return variable =a;
    }
    
    string findLongestWord(string s, vector<string>& v) {
        string t;
        if(s.length()==0 && v.size()==0)
            return t;
        if(v.size()==0)
            return t;
        int i,j; int arr[v.size()]={0}; int minm=INT_MAX; int index;
        for(int k=0;k<v.size();k++){
            //cout<<"Insdie while with elem. under consideration is: "<<v[k]<< " index is: "<<k<<endl;
            i=0; j=0;
            if(s.length()<v[k].length())
                arr[k]=INT_MAX;
            
            else{
                while(i<s.length()){
                    
                    if(s[i]==v[k][j])
                        j++;
                    if(j==v[k].length()){
                        arr[k]=s.length()-v[k].size();
                        break;
                    }
                    i++;
                }
                if(j!=v[k].length())
                    arr[k]=INT_MAX;
            }   
        }
        for(int a=0;a<v.size();a++){
            //cout<<"array value at index: "<<a<<" is: "<<arr[a]<<endl;
            if(arr[a]==minm && arr[a]!= INT_MAX)
                index=lexSmall(index,a,v);
            else if(arr[a]<minm){
                index=a;
                minm=arr[a];
            }
        }
        if(minm==INT_MAX)
            return t;
        //cout<<"The dict element with long equi. is: "<<v[index]<<endl;
        return v[index];
    }
};