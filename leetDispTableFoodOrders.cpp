/*
*
//**************************************1418. Display Table of Food Orders in a Restaurant.**************************************

Given the array orders, which represents the orders that customers have done in a restaurant. More specifically 
orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer 
sit at, and foodItemi is the item customer orders.

Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table 
ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first 
row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not 
part of the table. Additionally, the rows should be sorted in numerically increasing order.

 

Example 1:

Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
Output: [["Table","Beef Burrito","Ceviche","Fried Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]] 
Explanation:
The displaying table looks like:
Table,Beef Burrito,Ceviche,Fried Chicken,Water
3    ,0           ,2      ,1            ,0
5    ,0           ,1      ,0            ,1
10   ,1           ,0      ,0            ,0
For the table 3: David orders "Ceviche" and "Fried Chicken", and Rous orders "Ceviche".
For the table 5: Carla orders "Water" and "Ceviche".
For the table 10: Corina orders "Beef Burrito". 
Example 2:

Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]] 
Explanation: 
For the table 1: Adam and Brianna order "Canadian Waffles".
For the table 12: James, Ratesh and Amadeus order "Fried Chicken".
Example 3:

Input: orders = [["Laura","2","Bean Burrito"],["Jhon","2","Beef Burrito"],["Melissa","2","Soda"]]
Output: [["Table","Bean Burrito","Beef Burrito","Soda"],["2","1","1","1"]]
 

Constraints:

1 <= orders.length <= 5 * 10^4
orders[i].length == 3
1 <= customerNamei.length, foodItemi.length <= 20
customerNamei and foodItemi consist of lowercase and uppercase English letters and the space character.
tableNumberi is a valid integer between 1 and 500.




*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


I used test cases provided with the question.


// Time Complexity: O(n*m).													// n- #tables, m-# uniq. items ordered in restaurent.
// Space Complexity: O(n*m).	

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(n*m).													// n- #tables, m-# uniq. items ordered in restaurent.
// Space Complexity: O(n*m).	
// This algorithm is Sequence of steps to get the result in desired format. Our output has Table nums in the first col, item names in 
// the first row. We iter. over all orders to save all uniq. tables and the uniq. items ordered. We assign row num. to each table
// and col. number to each item, then we iter. over orders once again and track the cnt. of #orders for each item from each table, they
// will be saved in their respective indices which we have decided in earlier steps.









class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<int>tables;
        set<string>items;
        for(int i=0;i<orders.size();i++){									// Storing Uniq. tables and items to assign indices to them.
            int tab=stoi(orders[i][1]);
            tables.insert(tab);
            items.insert(orders[i][2]);
        }
        unordered_map<string,int>tableIndex,itemsIndex;						// Tracks tables, items row and col indices resp.
        vector<vector<string>>res(tables.size()+1,vector<string>(items.size()+1,"0"));// Init. the result array.
        int index=0;
        res[0][0]="Table";
        for(auto it=tables.begin();it!=tables.end();it++){					// Assigning indies to tables.
            tableIndex[to_string(*it)]=index+1;
            // cout<<"table: "<<to_string(*it)<<" and index: "<<tableIndex[to_string(*it)]<<endl;
            res[++index][0]=to_string(*it);									// Storing table num. at start of each row.
        }
        index=0;
        for(auto it=items.begin();it!=items.end();it++){					// Assigning col. num. to each uniq. item.
            itemsIndex[*it]=index+1;
            res[0][++index]=*it;											// Storing item name at the start of each col.
        }
        for(int i=0;i<orders.size();i++){									// Iter. over all orders.
            int row=tableIndex[orders[i][1]];
            int item=itemsIndex[orders[i][2]];
            // cout<<"row: "<<row<<" and col: "<<item<<" and val: "<<res[row][item]<<endl;
            res[row][item]=to_string(stoi(res[row][item])+1);				// Updating the cnt. of items and storing in corresp. indices.
        }
        return res;															// Returning the result 2D-array.
    }
};