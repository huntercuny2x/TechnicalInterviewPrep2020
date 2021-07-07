class Solution:
    def findRestaurant(self, list1, list2):
        from collections import defaultdict

        andy = {}
        for i in range(len(list1)):
            andy[list1[i]] = i

        min_sum = float('inf')
        rst_d = defaultdict(list)
        min_rst = None

        for i,rst in enumerate(list2):
            if rst in andy:
                rst_d[i+andy[rst]].append(rst)
                if i + andy[rst] < min_sum:
                    min_sum = i + andy[rst]
                    min_rst = rst

        return rst_d[min_sum]
