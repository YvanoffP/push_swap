import sys
import random

file = open("gen.log", "w")
result = ""
#Generate 5 random numbers between 10 and 30
randomlist = random.sample(range(-500, 500), 500)
for n in randomlist:
    result = f'{result} {n}'
file.write(result)
file.close()
print(result)
