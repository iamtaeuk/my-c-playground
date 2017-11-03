# Python 3.7

"""
i: 1 len: 1
i: 2 len: 2
i: 3 len: 2
i: 4 len: 3
i: 5 len: 3
i: 6 len: 3
i: 7 len: 2
i: 8 len: 2
i: 9 len: 1
"""

def numbers_to_fingers(n):
    ways = []
    i = n
    if n > 5:
        i -= abs(5 - n)
    for i in range(i, -1, -1):
        if n - i > i:
            break
        ways.append((i, n - i))
    return ways

for i in range(1,10):
    print(numbers_to_fingers(i))