class Solution {
public:
    bool isAnagram(string s, string t) {
        //diff lenght - not an anagram
        if(s.length() != t.length())
            return false;
        
        /*
        *   if character was used in string s, increment its count in map
        *   if it was used in string t, decrement its count
        *   if string are anagrams every character count should be == 0
        */
        unordered_map<char, int> chars_used;        
        for(int i=0; i<s.size(); ++i)
        {
            ++chars_used[s[i]];
            --chars_used[t[i]];
        }
        
        for (auto& it: chars_used) {
           if(it.second != 0)
               return false;
        }
        
        return true;
    }
};