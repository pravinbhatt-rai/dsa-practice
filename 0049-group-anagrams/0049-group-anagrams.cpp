class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;

        for(string s:strs){
            int count[26]={0};

          string key=s; 
          sort(key.begin(),key.end()) ;// abs and asb after soring asb become abc
            map[key].push_back(s); // jun key cha teseima s lai pushback garde kina bhane key same huncha

        }

        vector<vector<string>> result;

        for(auto & pair:map){
            result.push_back(pair.second);
        }

        return result;
    }
};