class Solution:
    def singleNumber(self, nums):
        result = 0

        for num in nums:
            result ^= num

        return result


# Main function for VS Code testing
if __name__ == "__main__":

    nums = [4, 1, 2, 1, 2]

    solution = Solution()

    answer = solution.singleNumber(nums)

    print(answer)