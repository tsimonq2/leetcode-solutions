#!/usr/bin/env python3

class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        # Truncate according to the expected elements
        nums1[:] = nums1[:m]
        nums2[:] = nums2[:n]

        # Emptiness checks
        if ((len(nums1) == 0 and len(nums2) == 0) or (m == 0 and n == 0)):
            nums1[:] = []
            return
        elif (m == 0 and n > 0):
            nums1[:] = nums2
            return
        elif (n == 0 and m > 0):
            return

        # Merge the two vectors into one
        n1_index = 0
        n2_index = 0
        combined_nums = list()
        while n1_index < m or n2_index < n:
            if n1_index >= m:
                combined_nums.append(nums2[n2_index])
                n2_index += 1
            elif n2_index >= n:
                combined_nums.append(nums1[n1_index])
                n1_index += 1
            elif nums1[n1_index] <= nums2[n2_index]:
                combined_nums.append(nums1[n1_index])
                n1_index += 1
            else:
                combined_nums.append(nums2[n2_index])
                n2_index += 1

        nums1[:] = combined_nums


# Test case 1
nums1 = [1, 2, 3, 0, 0, 0]
m = 3
nums2 = [2, 5, 6]
n = 3
Solution().merge(nums1, m, nums2, n)
print(nums1)  # Expected Output: [1, 2, 2, 3, 5, 6]

# Test case 2
nums1 = [1]
m = 1
nums2 = []
n = 0
Solution().merge(nums1, m, nums2, n)
print(nums1)  # Expected Output: [1]

# Test case 3
nums1 = [0]
m = 0
nums2 = [1]
n = 1
Solution().merge(nums1, m, nums2, n)
print(nums1)  # Expected Output: [1]

