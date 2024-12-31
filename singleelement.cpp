class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        int st = 0, end = n - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Ensure mid is pointing to the first element of a pair
            if (mid % 2 == 1) mid--;

            // If mid and mid+1 form a valid pair, the unique element is on the right
            if (A[mid] == A[mid + 1]) {
                st = mid + 2;
            } else {
                // Otherwise, the unique element is on the left (or is mid itself)
                end = mid;
            }
        }

        // st == end will point to the unique element
        return A[st];
    }
};
