class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // Stack jo un days ke index store karega
        // jinka answer abhi tak nahi mila (warmer day nahi aaya)
        stack<int> st;

        // Result array, default sab 0
        // Agar kisi day ko future me warmer day nahi mila
        // to answer 0 hi rahega
        vector<int> res(temperatures.size(), 0);

        // Har day ko left se right process kar rahe hain
        for (int i = 0; i < temperatures.size(); i++) {

            // Jab tak:
            // 1) stack empty nahi hai
            // 2) aaj ka temperature, stack ke top day se zyada hai
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {

                // Stack ke top pe jo day tha
                // uska answer ab mil gaya
                int idx = st.top();
                st.pop();  // us day ko stack se hata do

                // Kitne din wait kiya = aaj ka day - purana day
                res[idx] = i - idx;
            }

            // Aaj ke day ka answer abhi nahi pata
            // isliye aaj ka index stack me daal do
            st.push(i);
        }

        // Jo days stack me bach gaye
        // unka koi warmer future nahi tha
        // unka answer already 0 hai
        return res;
    }
};
