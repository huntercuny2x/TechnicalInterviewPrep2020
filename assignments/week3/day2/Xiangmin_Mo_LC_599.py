def findRestaurant(list1, list2):
  res = []
  
  # use a dictionary to store one of the list and its indices
  # use second list to check if it is in the list
  # if it is, add to value
  
  # s : 0 --> 3
  # te : 1
  # bk : 2
  # kfc: 3
  
  restaurant = {}
  curr_total = len(list1) + len(list2)
  
  for i, k in enumerate(list1):
    restaurant[k] = i
    
  for i, k in enumerate(list2):
    if k in restaurant:
      if restaurant[k] + i < curr_total:
        curr_total = restaurant[k] + i
        res = [k]
      elif restaurant[k] + i == curr_total:
        res.append(k)
        
  return res

print(findRestaurant(["Shogun","Tapioca Express","Burger King","KFC"],["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]))