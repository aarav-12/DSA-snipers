class Solution {
public:
    string minWindow(string s, string t) {

        // Agar s ya t empty hai ya s chhota hai t se
        // toh answer possible hi nahi
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // map array to store frequency of characters (ASCII based)
        // map[c] batata hai ki character c kitni baar chahiye
        vector<int> map(128, 0);

        // count = total characters jo abhi bhi match hone baaki hain
        int count = t.length();

        // start = left pointer
        // end = right pointer
        int start = 0, end = 0;

        // minLen = smallest valid window ka size
        // startIndex = us window ka starting index
        int minLen = INT_MAX, startIndex = 0;

        // t ke characters ki frequency map me store karo
        for (char c : t) {
            map[c]++;
        }

        // Sliding window start
        while (end < s.length()) {

            // Right pointer ka character include karo
            // Agar map value > 0 thi, matlab ye character required tha
            if (map[s[end++]]-- > 0) {
                count--;  // ek required character mil gaya
            }

            // Jab saare required characters mil jaate hain
            while (count == 0) {

                // Agar current window chhoti hai, answer update karo
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }

                // Left pointer ka character remove kar rahe hain
                // Agar map value 0 ho jaaye, matlab ek required character chala gaya
                if (map[s[start++]]++ == 0) {
                    count++;  // window invalid ho gayi
                }
            }
        }

        // Agar koi valid window nahi mila toh empty string return
        // warna smallest window return karo
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
