/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

//***********************************************THIS IS LEET ACCEPTED CODE.********************************************
*/
class Solution {
public:
    int maxSubArray(vector<int>& v) {
      int i, j,max, MAX_so_far;
    i=0;j=0;max=v[0];MAX_so_far=v[0];
    cout<<"In the beginning is: "<<max<<endl;
    for(int k=1;k<v.size();k++){
        if(max<=0){
            if(v[k]>max){
                cout<<"max beginning is: "<<max<<endl;
                i=k;// This marks the beginning of the new subarray under consideration.
                j=k;
                max=v[k];
                if(max>MAX_so_far)
                    MAX_so_far=max;
                cout<<"max so farrr is: "<<MAX_so_far<<" and max is: "<<max<<endl;
            }
        }
        /*
        else if(v[k]>max+v[k]){// Thought that this would be useful, but in the end turned out not usefut at all. :(
            i=k;
            j=k;
            max=v[k];
            MAX_so_far=max;
            cout<<"Currnet element is: "<<v[k]<<" Newwwwwwwwwwwwww max is: "<<max<< " j is: "<<i<<endl;
        }
        */
        else if((max+v[k])>0){
            max+=v[k];
            if(MAX_so_far<max){
                cout<<"max so far is: "<<MAX_so_far<<" and max is: "<<max<<endl;
                j=k;// Adds this index also into the sub array.
                MAX_so_far=max;
            }
            //cout<<"Currnet element is: "<<v[k]<<" max is: "<<max<<" J is: "<<j<<endl;
        }
        else{
            max=-2;
        }
    }
    return MAX_so_far;// Here max value is returned.  
    }
};