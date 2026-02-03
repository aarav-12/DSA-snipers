class TimeMap {
public:
    // Har key ke liye hum (timestamp, value) ki list store kar rahe hain
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        // constructor, kuch special kaam nahi
    }

    // SET operation
    void set(string key, string value, int timestamp) {
        // kyunki timestamps hamesha increasing order mein aate hain,
        // hum simply last mein push kar sakte hain
        mp[key].push_back({timestamp, value});
    }

    // GET operation
    string get(string key, int timestamp) {
        // agar key exist hi nahi karti
        if (mp.find(key) == mp.end()) {
            return "";
        }

        // key ke saare (time, value) pairs nikaal lo
        vector<pair<int, string>>& arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;
        string answer = "";

        // binary search shuru
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // agar mid ka timestamp <= given timestamp
            if (arr[mid].first <= timestamp) {
                // ye ek valid answer ho sakta hai
                answer = arr[mid].second;

                // aur better (bada timestamp) dhundhne ke liye right side jao
                left = mid + 1;
            } 
            else {
                // mid ka timestamp zyada hai, left side jao
                right = mid - 1;
            }
        }

        // jo last valid value mili, wahi answer hai
        return answer;
    }
};
