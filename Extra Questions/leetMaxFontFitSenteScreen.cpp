/*
*
//*******************************************1618. Maximum Font to Fit a Sentence in a Screen.*******************************************

https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/



*******************************************************************TEST CASES:************************************************************
//These are the examples I had tweaked and worked on.


"helloworld"
80
20
[6,8,10,12,14,16,18,24,36]
"leetcode"
1000
50
[1,2,4]
"easyquestion"
100
100
[10,15,20,25]




// Time Complexity: O(nlgon).												// fonts size array length.  
// Space Complexity: O(1).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/

//************************************************************Solution 1:************************************************************
//*****************************************************THIS IS LEET ACCEPTED CODE.***********************************************
// Time Complexity: O(nlogn).												// fonts size array length.
// Space Complexity: O(1).	
// This algorithm is Binary Search based. As, sizes and heights of characters are increasing monotonously, we can use Binary Search.
// We do Bin. Search over font array, whenever the mid font has both height and width under screen measurements then we will search in
// [mid, high], else we will look in [low, mid-1]. As we are not using [mid+1, high],we have to change the mid calc. formula: 
// mid=(low+high+1)/2.








/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:
    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int low=0, high=fonts.size()-1;
        vector<int>occur(26,0);
        for(auto ch:text)													// Tracking #occur. of each char in text.
            occur[ch-'a']++;
        while(low<high){
            // cout<<"low: "<<low<<" and high: "<<high<<endl;
            int mid=(low+high+1)/2;
            long long int totalWidth=0, totalHeight=fontInfo.getHeight(fonts[mid]);// Getting totalHeight for the curr. font size.
			if(totalHeight>h){
                high=mid-1;
                continue;
            }
            for(int i=0;i<26;i++)											// Getting width based on #occur. of each char in text.
                totalWidth+=occur[i]*fontInfo.getWidth(fonts[mid],i+'a');
            // cout<<"mid: "<<mid<<" and totalWidth: "<<totalWidth<<" and totalheight: "<<totalHeight<<endl;
            if(totalWidth<=w && totalHeight<=h) low=mid;
            else high=mid-1;
            
        }
		// Checking whether low index satisfies the given condition of fitting the screen dimensions.
        long long int totalWidth=0, totalHeight=fontInfo.getHeight(fonts[low]);
        for(int i=0;i<26;i++)
                totalWidth+=occur[i]*fontInfo.getWidth(fonts[low],i+'a');
        return (totalHeight<=h && totalWidth<=w)?fonts[low]:-1;
    }
};
