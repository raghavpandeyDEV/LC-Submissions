class TimeMap {
public:
    unordered_map<string , vector<pair<string,int>>>mpp; // {foo -> [{bar,1}, {bar2, 2}] } 
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!mpp.count(key))
            return "";

        auto &v = mpp[key];

        int left = 0;
        int right = v.size() - 1;
        string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].second <= timestamp) {
                ans = v[mid].first;
                left = mid + 1;       // try to find a later timestamp
            }
            else {
                right = mid - 1;
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