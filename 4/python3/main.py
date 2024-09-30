#!/usr/bin/env python3

class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        # Emptiness check
        if not nums1 and not nums2:
            return 0

        # If each list only has one element, return the average
        if len(nums1) == 1 and len(nums2) == 1:
            return (nums1[0] + nums2[0]) / 2.0

        combined_size = len(nums1) + len(nums2)
        median_index = combined_size // 2

        # We use a list to simulate the array from the C++ version
        combined_nums = [0] * (median_index + 1)

        nums1_tail, nums2_tail = 0, 0

        # Fill the combined array up to the median index
        for i in range(median_index + 1):
            if nums1_tail >= len(nums1):
                combined_nums[i] = nums2[nums2_tail]
                nums2_tail += 1
            elif nums2_tail >= len(nums2):
                combined_nums[i] = nums1[nums1_tail]
                nums1_tail += 1
            elif nums1[nums1_tail] > nums2[nums2_tail]:
                combined_nums[i] = nums2[nums2_tail]
                nums2_tail += 1
            else:
                combined_nums[i] = nums1[nums1_tail]
                nums1_tail += 1

        # If the combined size is even, average the last two elements
        if combined_size % 2 == 0:
            return (combined_nums[median_index] + combined_nums[median_index - 1]) / 2.0
        else:
            return combined_nums[median_index]
