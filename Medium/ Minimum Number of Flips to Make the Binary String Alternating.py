class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)

        # Duplicate the string to represent every possible rotation
        doubled = s + s

        # Number of mismatches with:
        # pattern1 = "010101..."
        # pattern2 = "101010..."
        mismatch1 = 0
        mismatch2 = 0
        answer = n

        left = 0

        for right in range(2 * n):
            expected1 = "0" if right % 2 == 0 else "1"
            expected2 = "1" if right % 2 == 0 else "0"

            if doubled[right] != expected1:
                mismatch1 += 1

            if doubled[right] != expected2:
                mismatch2 += 1

            # Keep the sliding window size at most n
            if right - left + 1 > n:
                left_expected1 = "0" if left % 2 == 0 else "1"
                left_expected2 = "1" if left % 2 == 0 else "0"

                if doubled[left] != left_expected1:
                    mismatch1 -= 1

                if doubled[left] != left_expected2:
                    mismatch2 -= 1

                left += 1

            # Every window of size n represents one rotation
            if right - left + 1 == n:
                answer = min(answer, mismatch1, mismatch2)

        return answer


# -----------------------
# Driver Code for VS Code
# -----------------------
if __name__ == "__main__":
    binary_string = input("Enter a binary string: ").strip()

    solution = Solution()
    result = solution.minFlips(binary_string)

    print("Minimum number of flips:", result)