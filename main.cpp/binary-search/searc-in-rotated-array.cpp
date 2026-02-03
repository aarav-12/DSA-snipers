class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, mid;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (arr[mid] == target) return mid;

            // Left half sorted
            if (arr[mid] >= arr[start]) {
                if (arr[start] <= target && target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
            // Right half sorted
            else {
                if (arr[mid] < target && target <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
