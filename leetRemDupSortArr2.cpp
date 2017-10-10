/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 It doesn't matter what you leave beyond the new length.
 //********************************************THIS IS LEET ACCEPTED CODE.***********************************************
*/


class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        map<int, int> m;
        for(int i=0;i<v.size();i++){
            cout<<"entry index is: "<<i<<endl;
            if(m.find(v[i])!=m.end()){
                if(m[v[i]]==2){// Makes sure that Two duplicates remain in the vector.
                    v.erase(v.begin()+i, v.begin()+i+1);// Removes element at index "i" in the vector.
                    cout<<"Removed index is: "<<i<<endl;
                    i--;
                }
                else
                    m[v[i]]++;
            }
            else
                m[v[i]]=1;
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        
        cout<<v.size()<<endl;
        return v.size();
    }
};