class Solution {
public:
    int findMin(vector<int>& arr) {

        // start = array ka first index
        // end   = array ka last index
        // ans   = abhi tak ka minimum (initially arr[0])
        int start = 0, end = arr.size() - 1, ans = arr[0];

        // jab tak search space valid hai
        while (start <= end) {

            // mid index nikal rahe hain (overflow safe)
            int mid = start + (end - start) / 2;

            // agar arr[mid] >= arr[0]
            // matlab mid LEFT sorted part mein hai
            // (rotation ke pehle wala bada part)
            if (arr[mid] >= arr[0]) {

                // left part sorted hai, yahan minimum nahi ho sakta
                // isliye right side mein jao
                start = mid + 1;
            }

            // arr[mid] < arr[0]
            // matlab mid RIGHT sorted part mein hai
            // yahin minimum ho sakta hai
            else {

                // possible minimum mil gaya
                ans = arr[mid];

                // aur better (aur left) minimum dhundhne ke liye
                // left side mein jao
                end = mid - 1;
            }
        }

        // final minimum return
        return ans;
    }
};
