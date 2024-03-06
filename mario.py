# Importing get_int from cs50
from cs50 import get_int

# Asking user for custom height
height = get_int("What height do you want the Pyramind be of? ")

# If height is more than 9 or less than 1, program keeps prompting user for valid input
while (height > 8 or height <1):
    height = get_int("Enter Height again: ")

# Prints out the pyramid of custom height
for x in range(height):
    for y in range(height):
        if y > height - x -2:
            print("#", end = "")
        else:
            print(" ", end = "")
    print("")

# cs50/problems/2022/x/sentimental/mario/less
