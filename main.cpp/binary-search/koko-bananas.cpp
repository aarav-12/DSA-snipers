class Solution {
public:
    bool canEat(vector<int>& piles, int k, int h) {
        long long hours = 0;

        // Har pile ke liye check karo
        for (int bananas : piles) {
            // is pile ko khane ke liye kitne hours lagenge
            // ceil(bananas / k) ka kaam
            hours += (bananas + k - 1) / k;
        }

        // agar total hours h ke andar aa gaye
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;                       // minimum speed possible
        int high = *max_element(piles.begin(), piles.end()); // max pile size
        int ans = high;                    // worst case answer

        while (low <= high) {
            int mid = low + (high - low) / 2; // current speed try kar rahe hain

            if (canEat(piles, mid, h)) {
                // agar is speed pe kaam ho gaya
                ans = mid;          // potential answer
                high = mid - 1;     // aur slow try karo
            } else {
                // agar kaam nahi hua (too slow)
                low = mid + 1;      // speed badhao
            }
        }

        return ans;
    }
};
