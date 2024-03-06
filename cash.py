# Import get_float from cs50
from cs50 import get_float

# Define function for taking total cents from user
def get_cents():

    # Initialize dollars and calculate it in cents
    dollars = 0
    dollars = get_float("How many Dollars do you own: ")

    # Get the user to cooperate
    while dollars < 0:
        dollars = get_float("Invalid Value, Enter again: ")
    cents = round(dollars * 100)
    return cents

# Define function to calculate quarters
def get_quarters(cents):
    quarters = 0
    quarters = cents // 25
    return quarters

# Define function to calculate dimes
def get_dimes(cents):
    dimes = 0
    dimes = cents // 10
    return dimes

# Define function to calculate nickels
def get_nickels(cents):
    nickels = 0
    nickels = cents // 5
    return nickels

# Define function to calculate pennies
def get_pennies(cents):
    pennies = 0
    pennies = cents
    return pennies

# Define what main function will do
def main():

    # Store cents, quarters, dimes, nickels and pennies to the respective variables
    cents = get_cents()

    # Calculate the total quarters in given cents and subtract that value and update cents with new value
    quarters = get_quarters(cents)
    cents = cents - quarters * 25

    # Calculate the total dimes in remaining cents and subtract that value and update cents with remaining cents
    dimes = get_dimes(cents)
    cents = cents - dimes * 10

    # Calculate the total nickels in remaining cents and subtract that value and update cents with remaining cents
    nickels = get_nickels(cents)
    cents = cents - nickels * 5

    # Calculate the total pennies in remaining cents and subtract that value and update cents with remaining cents
    pennies = get_pennies(cents)
    cents = cents - pennies * 1

    # Add the total quarters, dimes, nickels and pennies to calculate the minimum coins to return the customer
    coins = quarters + dimes + nickels + pennies

    print(f"You owe {coins} coins")

# Call main function
main()


# check50 cs50/problems/2022/x/sentimental/cash
