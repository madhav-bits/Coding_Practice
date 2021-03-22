/*
*
//************************************************1801. Number of Orders in the Backlog.***********************************************

https://leetcode.com/problems/number-of-orders-in-the-backlog/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had worked on.


[[10,5,0],[15,2,1],[25,1,1],[30,4,0]]
[[7,1000000000,1],[15,3,0],[5,999999995,0],[5,1,1]]




// Time Complexity: O(nlogn).  
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).
// Space Complexity: O(n).	
// This algorithm is Priority Queue based. As we are sell orders at max prices, we store buy orders in Max PQ. As we are buying things at min prices, we
// buy them from Min PQ sell orders, we get it by pushing neg. sell values into Max PQ. In this way we match buy and sell orders with their optimal 
// mathing opposite orders. The left out orders are popped form both PQs and added and returned. 











class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        int mod=1000000007;
        priority_queue<vector<int>>sell, buy;
        for(int i=0;i<orders.size();i++){
            if(orders[i][2]==1){											// Sell orders, matching with max valued buy orders.
                while(orders[i][1]!=0 && !buy.empty() && buy.top()[0]>=orders[i][0]){
                    int minOrders=min(orders[i][1], buy.top()[1]);
                    vector<int>temp=buy.top();buy.pop();
                    // cout<<"buy quantity: "<<temp[1]<<endl;
                    temp[1]-=minOrders;
                    orders[i][1]-=minOrders;
                    if(temp[1]>0) buy.push(temp);							// If the buy orders are still present, push back into PQ.
                }
                if(orders[i][1]>0) sell.push({-orders[i][0], orders[i][1]});// Pushing neg. sell values to get min sell values on top of PQ.
            }else{// Buy Orders.price, quantity, type						// Buy orders, matching with min valued sell orders.
                while(orders[i][1]!=0 && !sell.empty() && abs(sell.top()[0])<=orders[i][0]){
                    int minOrders=min(orders[i][1], sell.top()[1]);
                    vector<int>temp=sell.top();sell.pop();
                    // cout<<"sell quantity: "<<temp[1]<<endl;
                    temp[1]-=minOrders;
                    orders[i][1]-=minOrders;
                    if(temp[1]>0) sell.push(temp);							// If sell orders are still left, push back into PQ.
                }
                if(orders[i][1]>0) buy.push({orders[i][0], orders[i][1]});	// Pushing buy values to get max buy values on top of PQ.
            }
        }
        long long int res=0;
        while(!buy.empty()){
            res=(res+buy.top()[1])%mod;										// Adding left out buy orders.
            // cout<<"buy price: "<<buy.top()[0]<<" and quan: "<<buy.top()[1]<<endl;
            buy.pop();
        }
        while(!sell.empty()){
            res=(res+sell.top()[1])%mod;
            // cout<<"sell price: "<<sell.top()[0]<<" and quan: "<<sell.top()[1]<<endl;
            sell.pop();
        }
        return res;															// Returning total of left out orders.
    }
};


