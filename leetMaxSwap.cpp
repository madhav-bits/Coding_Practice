/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
1. The given number is in the range [0, 108]

//************************************************* THIS IS LEET ACCEPTED CODE.************************************************
*/
class Solution {
public:
    int maximumSwap(int num) {
        int result=0; int temp=num; int num2=0;
        if(num==0)
            return 0;
        vector<int> v;
        int div=1;int rem=1;
        string s=to_string(temp);
        cout<<"String length is: "<<s.length()<<endl;
        cout<<"xx: "<<int(s[1])-48<<endl;
        int maxm=INT_MIN; int index;
        int temp3=0; 
        for(int i=0;i<s.length();i++)
            v.push_back(int(s[i])-48);
        
        for(int j=0;j<s.length();j++){// Only single swap is allowed, utilize it to maximize the value.
            cout<<"inside for with j: "<<j<<endl;
            index=0;temp3=j;maxm=INT_MIN;
            for(int i=j;i<s.length();i++){
                if(maxm<= v[i]){
                    index=i;
                    maxm=v[i];
                }
            }
            if(v[index]!= v[j])// This makes sure that to be swapped max elem. and the initial elem. are diff.
                break;
        }
        
        cout<<"temp3 val is: "<<temp3<<"index is: "<<index<<endl;
        swap(v[temp3], v[index]);
        cout<<"After swap: "<<v[0]<<endl;
        for(int i=0;i<v.size();i++){
            result+=v[i]*pow(10,v.size()-1-i);
        }
        
        return result;
    }
};