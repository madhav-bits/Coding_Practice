/*
*
//******************************************************2353. Design a Food Rating System.******************************************************

https://leetcode.com/problems/design-a-food-rating-system/




*******************************************************************TEST CASES:************************************************************
//These are the examples I had created, tweaked and worked on.


["FoodRatings","highestRated","highestRated","changeRating","highestRated","changeRating","highestRated"]
[[["kimchi","miso","sushi","moussaka","ramen","bulgogi"],["korean","japanese","japanese","greek","japanese","korean"],[9,12,8,15,14,7]],["korean"],["japanese"],["sushi",16],["japanese"],["ramen",16],["japanese"]]



// Time Complexity: O(logm).												// O(logm) for changeRating, Asymptotic O(logm) for highestRated function.
// Space Complexity: O(n*m).												// m-#cuisines, n-avg. #foods per cuisine

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(logm).												// O(logm) for changeRating, Asymptotic O(logm) for highestRated function.
// Space Complexity: O(n*m).												// m-#cuisines, n-avg. #foods per cuisine
// This algorithm is Priority Queue based. We store {food, ratings} pairs in their cuisine corresponding Priority Queues, whenever there is an rating update
// for a food, we update the corresponding food's cuisine related PQ. We make a new entry into PQ with {food, newRating}, which makes this an duplicate entry
// for that food. We handle duplicates by popping all such PQ entries whose rating value doesn't match current latest food rating for that food, food rating
// doesn't match imply that this rating is an old rating, so that ignore it and pop it and return the first entry whose rating matches latest rating of the food.
// We also created various other maps to correlate food with cuisines and ratings.







class FoodRatings {
public:
    struct comp {
        bool operator() (pair<string, int>& lt, pair<string, int>& rt) {
            if(lt.second!=rt.second) return lt.second<rt.second;
            return lt.first>rt.first;
        }    
    };
    
    unordered_map<string, pair<string, int>>foodRatings;
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, comp>>highRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        foodRatings=unordered_map<string, pair<string,int>>();
        for(int i=0;i<foods.size();i++) {
            foodRatings[foods[i]]={cuisines[i], ratings[i]};				// Mapping food with it's cuisine and latest rating.
            highRating[cuisines[i]].push({foods[i], ratings[i]});			// Pushing {food, rating} pair into cuisine related PQ.
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatings[food].second=newRating;									// Updating latest rating for the food.
        highRating[foodRatings[food].first].push({food, newRating});		// Pushing food, latest rating into PQ.
        return ;
    }
    
    string highestRated(string cuisine) {
        while(!highRating[cuisine].empty() && 
              highRating[cuisine].top().second!=foodRatings[highRating[cuisine].top().first].second) {
            // cout<<"popping food: "<<highRating[cuisine].top().first<<" and rating: "<<highRating[cuisine].top().second<<endl;
            highRating[cuisine].pop();										// Popping all old/prev. ratings of the food.
        }
        return highRating[cuisine].top().first;								// Returning highestRated food in the cuisine.
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 
 