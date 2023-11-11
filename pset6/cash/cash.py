from cs50 import get_float
import math


# Get float value for n
while True:
    n = get_float("Change owed: ")
    if n > 0:
        break

# Turn into integer
n = int(round(n * 100))

# Assign a variable
coins = 0

# Loops for the coins
while n >= 25:
    n = n - 25
    coins = coins + 1

while n >= 10:
    n = n - 10
    coins = coins + 1

while n >= 5:
    n = n - 5
    coins = coins + 1

while n >= 1:
    n = n - 1
    coins = coins + 1

print(coins)