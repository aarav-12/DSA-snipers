class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();

        // l = left pointer, r = right pointer
        // maxlen = longest valid window ka size
        int l = 0, r = 0, maxlen = 0;

        // maxf = current window me kisi ek character ki max frequency
        int maxf = 0;

        // count array to store frequency of characters (A to Z)
        vector<int> count(26, 0);

        while (r < n) {

            // 1️⃣ Right pointer ka character window me add karo
            count[s[r] - 'A']++;

            // 2️⃣ Window me jo sabse zyada baar aaya character hai uski frequency update karo
            maxf = max(maxf, count[s[r] - 'A']);

            // 3️⃣ Agar window me k se zyada replacements chahiye
            // (window size - max frequency > k)
            // toh window invalid ho jaati hai
            if ((r - l + 1) - maxf > k) {

                // Left pointer ka character remove karo
                count[s[l] - 'A']--;
                l++;  // window shrink karo
            }

            // 4️⃣ Har step pe maximum valid window ka size update karo
            maxlen = max(maxlen, r - l + 1);

            // Right pointer aage badhao
            r++;
        }

        return maxlen;
    }
};
