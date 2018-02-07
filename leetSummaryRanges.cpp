/*
*
//**************************************************************228. Summary Ranges.******************************************************

Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


//These are the examples I had created, tweaked and worked on.
[2,3,46,8,12,14,16,17,18,20,22]
[]
[1,2,3,4,5]




// Time Complexity: O(n).
// Space Complexity: O(1).			

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This iterates through the array, sees for sequence of digits, if length of seq.>1 then form one type of range summary, if length is 1, then form
// other type of range summary and push into final result vector.


class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        vector<string> u;
        if(v.size()==0)
            return u;
        int length=0, start, value;										
        for(int i=0;i<v.size();i++){
            if(length==0){														//Initializing the seq. of integers.
                //cout<<" Inside zero length function."<<endl;
                start=v[i];
                value=v[i];
                length++;
            }
            else if(v[i]==value+1){												//Extending the seq. of integers.
                //cout<<" Inside inc. length function."<<endl;
                length++;
                value=v[i];
            }
            else{
                //cout<<" Inside else function."<<endl;
                if(length>1){													//If seq. is ended and length>1, then form a range summary.
                    string s=to_string(start)+"->"+to_string(v[i-1]);
                    u.push_back(s);
                }
                else															//If seq. is ended and length=1, then form a range summary.
                    u.push_back(to_string(start));
                i--;
                length=0;
            }
            //cout<<"Index i: "<<i<<" start: "<<start<<" and value: "<<v[i]<<" length: "<<length<<endl;
        }
        
        if(length>1){                                           				//For the last seq. of integers.
            string s=to_string(start)+"->"+to_string(v[v.size()-1]);			// If the length>1.
            u.push_back(s);
        }
        else																	// If the length=1.
            u.push_back(to_string(start));
        
        return u;
        
    }
};



//************************************************************Solution 2:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n).
// Space Complexity: O(1).			
// This algorithm is same as the above one, but improves the time complexity linearly not asymptotical level improvement.




class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        vector<string> u;
        if(v.size()==0)
            return u;
        int length=1, start=v[0], value=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]==value+1){
                //cout<<" Inside inc. length function."<<endl;
                length++;
                value=v[i];
            }
            else{
                //cout<<" Inside else function."<<endl;
                if(length>1){
                    string s=to_string(start)+"->"+to_string(v[i-1]);
                    u.push_back(s);
                }
                else
                    u.push_back(to_string(start));
                //i--;
                length=1;
                start=v[i];
                value=v[i];
            }
            //cout<<"Index i: "<<i<<" start: "<<start<<" and value: "<<v[i]<<" length: "<<length<<endl;
        }
        
        if(length>1){                                           //For the last seq. of integers.
            string s=to_string(start)+"->"+to_string(v[v.size()-1]);
            u.push_back(s);
        }
        else
            u.push_back(to_string(start));
        
        return u;
        
    }
};