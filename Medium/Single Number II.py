class Solution:
    def singleNumber(self, nums):

        ones = 0
        twos = 0

        for num in nums:

            ones = (ones ^ num) & ~twos

            twos = (twos ^ num) & ~ones

        return ones



if __name__ == "__main__":

    nums = [2, 2, 3, 2]

    sol = Solution()

    print(sol.singleNumber(nums))