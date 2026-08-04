from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [0] * (n + 1)

        # Build the DP table from the end
        for i in range(n - 1, -1, -1):
            best = float('-inf')
            total = 0

            # Try taking 1, 2, or 3 stones
            for j in range(3):
                if i + j < n:
                    total += stoneValue[i + j]
                    best = max(best, total - dp[i + j + 1])

            dp[i] = best

        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"


# ----------------------
# Driver Code (VS Code)
# ----------------------
if __name__ == "__main__":
    arr = list(map(int, input("Enter stone values separated by spaces: ").split()))

    sol = Solution()
    result = sol.stoneGameIII(arr)

    print("Winner:", result)