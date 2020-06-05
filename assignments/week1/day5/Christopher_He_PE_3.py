num = 600851475143

def solution(num):
    for i in range(2, num // 2):
        if num % i == 0:
            return solution(num // i) + solution(i)

    return [num]

print(max(solution(num)))
