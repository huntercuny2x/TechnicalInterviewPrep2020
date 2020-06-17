class Solution:
    # more optimal solution
    def searchMatrix2(self, matrix, target):
	if not matrix:
            return False

        i, j = 0, len(matrix[0]) - 1

        while i < len(matrix) and j >= 0:
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] < target:
                i += 1
            else:
                j -= 1

        return False

    # my original solution using binary search
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
