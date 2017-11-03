/*

713. Subarray Product Less Than K

Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

//**************************************************THIS IS LEET ACCEPTED CODE.****************************************************
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int num) {
        if(num==0)
            return 0;
        int count=0, begin=0, product=1, end=0;
        for(int i=0;i<v.size();i++){
            product*=v[i];
            if(product<num){
                end=i;
                count+=(end-begin+1);
            }
            else{
                while(product>=num && begin<=i){
                    product=product/v[begin];
                    begin++;
                    //cout<<"inside else new product is: "<<product<<"index is: "<<i<<endl;
                }
                if(product<num){
                    end=i;
                    count+=(end-begin+1);
                }
                //cout<<"Count after while is: "<<count<<endl;
            }
            //cout<<"The final count after both conditions is: "<<count<<"product is: "<<product<<"and the index is: "<<i<<endl;
        }
        //cout<<"The final count is: "<<count<<endl;
        return count;
    }
};