class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()){// key agar exis nei garna bhane
        return "";}

        vector<pair<int,string>> &vel=mp[key];// key lai vector banako value , matlab tyo ey koh element lai auta vector banako

        int low=0;
        int high=vel.size()-1;
        string ans="";

        while(low<=high){
            int mid=low+(high-low)/2;
           
            if(vel[mid].first<=timestamp){
                ans=vel[mid].second;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */