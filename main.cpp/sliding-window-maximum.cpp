class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        // ans me har window ka maximum store karenge
        vector<int> ans;

        // deque me hum INDEX store karenge (values nahi)
        // deque hamesha DECREASING order me rahega (front = max)
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // 1️⃣ Jo index window ke bahar chala gaya hai use hata do
            // current window: [i - k + 1 , i]
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // 2️⃣ Deque ka order maintain karo
            // Agar current element bada hai,
            // toh peeche ke saare chhote elements useless ho jaate hain
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // 3️⃣ Current index deque me add karo
            dq.push_back(i);

            // 4️⃣ Jab window size k ho jaye,
            // deque ka front hi maximum hota hai
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};
