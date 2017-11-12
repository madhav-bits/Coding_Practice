/*

//***********************************************539. Minimum Time Difference**************************************************

Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.

Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.

//Time Complexity: O(nlogn).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    int findMinDifference(vector<string>& v) {
        int minm=INT_MAX;
        //sort(v.begin(), v.end());
        vector<int>u(v.size(),0);
        for(int i=0;i<v.size();i++){
            int hours=stoi(v[i].substr(0,2));
            int min=stoi(v[i].substr(3,2));
            u[i]=(60*hours)+min;
        }
        sort(u.begin(),u.end());// Sorting the calculated times.
        for(int i=0;i<u.size();i++){
            int diff=abs(u[(i+1)%u.size()]-u[i]);// First and last indices might make the min diff. so, calc. their diff also.
            int diff2=min(diff, 1440-diff);// Taking into consideration,which of the two is minm.
            minm=min(minm, diff2);// Saving overall minm.
        }
        //cout<<"Min is: "<<minm<<endl;
        return minm;// Returning the minm time diff. value.
        
    }
};