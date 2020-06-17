def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        if len(list2) == 0 or len(list1) == 0:
            return []
        
        checker = {}
        for i in range(len(list2)):
            if not list2[i] in checker.keys():
                checker[list2[i]] = i
        
        if len(checker) == 0:
            return []
        result = []
        
        idx_sums = []
        #min = (float('inf'), float('inf'))
        for i in range(len(list1)):
            if list1[i] in checker.keys():
                idx_sum = i + checker[list1[i]]
                #if float(idx_sum) <= min[1]:
                #min = (i, idx_sum)
                idx_sums.append((i, idx_sum))
        
        min = 11000
        for e in idx_sums:
            if e[1] < min:
                min = e[1]
        
        target = min
        for e in idx_sums:
            if e[1] == min:
                result.append(list1[e[0]])
  
        return result 