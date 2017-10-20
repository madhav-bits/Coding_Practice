/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of 
which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
//***************************************************THIS IS LEET ACCEPTED SOLUTION.*********************************************
//*************************************************THIS SOLUTION MODEL IS CALLED MOVING WINDOW MODEL.****************************

*/
class Solution {
public:
    
    int minSubArrayLen(int sum, vector<int>& v) {
        if(v.size()==0)
            return 0;
        if(v[0]==sum)
            return 1;
        queue<int> q; int count=0; int minm=INT_MAX;
        for(int i=0;i<v.size();i++){
            do{
                //cout<<"To be pushed element is: "<<v[i]<<endl;
                q.push(v[i]);
                count+=v[i];
                i++;
            }while(count<sum && i<v.size());
            i--;
            while(count>=sum && q.size()!=0){
                int length=q.size();
                //cout<<"count is: "<<count<<" length is: "<<length<<endl;
                minm=min(length, minm);
                if(minm==1)
                    return 1;
                int temp=q.front();
                //cout<<"To be deleted element is: "<<temp<<endl;
                count=count-temp;
                //cout<<"New count is: "<<count<<endl;
                q.pop();
            }
            
        }
        cout<<"Min value is: "<<minm<<endl;
        if(minm==INT_MAX)
            return 0;
        return minm;
    }
};