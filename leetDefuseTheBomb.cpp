/*
*
//********************************************************1652. Defuse the Bomb.********************************************************

https://leetcode.com/problems/defuse-the-bomb/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


[5,7,1,4]
3
[1,2,3,4]
0
[2,4,9,3]
-2
[3,5,2,5,3,6,24,65,64]
6




// Time Complexity: O(n).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, we iter. based on the k value. We take new array and update it during iter.








class Solution {
public:
    vector<int> decrypt(vector<int>& v, int k) {
        vector<int>res(v.size(),0);
        if(k==0) return res;
        if(k<0){
            k*=-1;
            int total=0;
            for(int i=0;i<k;i++) total+=v[i];
            for(int dx=0;dx<v.size();dx++){
                // cout<<"i: "<<(k+dx)%v.size()<<" and val: "<<total<<endl;
                // cout<<"sub: "<<v[(dx+v.size())%v.size()]<<" and add: "<<temp<<endl;
                res[(k+dx)%v.size()]=total;
                total-=v[dx];
                total+=v[(k+dx)%v.size()];
            }
        }else{
            int total=0;
            for(int i=v.size()-1;i>=v.size()-k;i--)
                total+=v[i];
            for(int dx=1;dx<=v.size();dx++){
                int temp=v[(v.size()-k-dx+v.size())%v.size()];
                // cout<<"i: "<<(v.size()-k-dx+v.size())%v.size()<<" and total: "<<total<<endl;
                res[(v.size()-k-dx+v.size())%v.size()]=total;
                total-=v[v.size()-dx];
                total+=temp;
            }
        }
        return res;
    }
};






//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(n).	
// This algorithm is Sliding Window based. Here, we update the new array based on drn.




class Solution {
public:
    vector<int> decrypt(vector<int>& v, int k) {
        vector<int>res(v.size(),0);
        if(k==0) return res;
        int drn=k;
        if(drn>0) reverse(v.begin(), v.end());								// Reversing the drn to match k<0 situation.
        else k*=-1;
        int total=0;
        for(int i=0;i<k;i++) total+=v[i];
        for(int dx=0;dx<v.size();dx++){
            // cout<<"i: "<<(k+dx)%v.size()<<" and val: "<<total<<endl;
            // cout<<"sub: "<<v[(dx+v.size())%v.size()]<<" and add: "<<temp<<endl;
            res[(k+dx)%v.size()]=total;										// Updating new array with subarr. sum.
            total-=v[dx];													// Remove last index. from window.
            total+=v[(k+dx)%v.size()];										// Add curr. index to window.
        }
        if(drn>0) reverse(res.begin(), res.end());							// Reversing the result as given array is reversed.
        return res;															// Return the window sum array.
    }
};
