class Solution:
    def findDifferentBinaryString(self, nums: list[str]) -> str:
        return "".join(
            "1" if nums[i][i] == "0" else "0"
            for i in range(len(nums))
        )


if __name__ == "__main__":
    n = int(input("Enter number of binary strings: "))

    nums = []

    print(f"Enter {n} binary strings of length {n}:")

    for _ in range(n):
        binary_string = input().strip()
        nums.append(binary_string)

    solution = Solution()
    result = solution.findDifferentBinaryString(nums)

    print("Unique binary string:", result)