import random

numbers = range(1, 2000000)
sample = random.sample(numbers, 1000000)

for number in sample:
  print(number, end=' ')
print()

