/*

//******************************************************242. Valid Anagram.***************************************************
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?



Time Complexity: O(nlogn).
Space Complexity: O(1).
//***********************************************THIS IS LEET ACCEPTED CODE.************************************************
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t)// If the two strings are already sorted and equal, then directly returning true.
            return true;
        else{
            sort(s.begin(), s.end());// Sorting two strings.
            sort(t.begin(), t.end());
            if(s==t)// If two string are equal after they are sorted then they are anagrams, so, TRUE is returned.
                return true;
        }
        return false;// If not equal even after sorting, then they are not anagrams. So, FALSE is returned.
    }
};