class Solution
{
public:
    int findKth(const vector<int> &A, int a_start,
                const vector<int> &B, int b_start,
                int k)
    {
        if (a_start >= (int)A.size())
            return B[b_start + k - 1];
        if (b_start >= (int)B.size())
            return A[a_start + k - 1];
        if (k == 1)
            return min(A[a_start], B[b_start]);

        int A_key = (a_start + k / 2 - 1 < (int)A.size())
                        ? A[a_start + k / 2 - 1]
                        : INT_MAX;
        int B_key = (b_start + k / 2 - 1 < (int)B.size())
                        ? B[b_start + k / 2 - 1]
                        : INT_MAX;

        if (A_key < B_key)
        {
            return findKth(A, a_start + k / 2, B, b_start, k - k / 2);
        }
        else
        {
            return findKth(A, a_start, B, b_start + k / 2, k - k / 2);
        }
    }

    double findMedianSortedArrays(vector<int> &nums1,
                                  vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int total = n + m;
        if (total % 2 == 1)
        {
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        }
        else
        {
            double a = findKth(nums1, 0, nums2, 0, total / 2);
            double b = findKth(nums1, 0, nums2, 0, total / 2 + 1);
            return (a + b) / 2.0;
        }
    }
};
