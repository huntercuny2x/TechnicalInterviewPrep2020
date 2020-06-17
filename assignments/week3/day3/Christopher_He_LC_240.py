class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False

        r = len(matrix)
        c = len(matrix[0])

        def binsearch(arr, lo, hi, target):
            if lo >= hi:
                return hi

            mid = (lo + hi) // 2
            if arr[mid] == target:
                return mid
            elif target < arr[mid]:
                return binsearch(arr, lo, mid, target)

            return binsearch(arr, mid+1, hi, target)

        x = binsearch(matrix[0], 0, c, target)

        for i in range(r):
            if matrix[i] and matrix[i][0] > target:
                break
            y = binsearch(matrix[i], 0, x, target)
            if not y < c:
                continue
            if matrix[i][y] == target:
                return True

        return False
