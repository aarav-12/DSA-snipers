class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size(); 
        // matrix me total kitni rows hain, wo nikaal rahe hain

        int cols = matrix[0].size(); 
        // pehli row se columns ki count nikaal li (matrix empty nahi maana)

        int candidateRow = -1; 
        // ye wo row hogi jisme target ho sakta hai
        // -1 se initialize kiya taaki pata chale agar abhi koi row decide nahi hui

        // Step 1: rows ko scan kar rahe hain
        for (int i = 0; i < rows; i++) {

            // agar current row ka first element target se bada ho gaya
            if (matrix[i][0] > target) {

                // to target sirf previous row me hi ho sakta hai
                candidateRow = i - 1;

                // row mil gayi, aage check karne ki zarurat nahi
                break;
            }
        }

        // agar loop ke baad bhi candidateRow -1 hai
        // matlab target last row me ho sakta hai
        if (candidateRow == -1) {
            candidateRow = rows - 1;
        }

        // safety check: agar candidateRow invalid ho
        if (candidateRow < 0) return false;

        // Step 2: selected row ke andar binary search laga rahe hain
        int low = 0, high = cols - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2; 
            // mid index nikaal rahe hain (overflow safe)

            if (matrix[candidateRow][mid] == target) {
                // agar target mil gaya
                return true;
            }
            else if (matrix[candidateRow][mid] < target) {
                // agar mid element chhota hai target se
                // to right side me search karo
                low = mid + 1;
            }
            else {
                // agar mid element bada hai target se
                // to left side me search karo
                high = mid - 1;
            }
        }

        // agar binary search me bhi target nahi mila
        return false;
    }
};
