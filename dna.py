import csv
from sys import argv, exit


def main():

    # If more or less than 3 command-lines are used, Display error with error 1
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.text")
        exit(1)

    # Open and read data.csv file into dataCSV and append line by line into dnaList
    dnaList = []
    with open(argv[1], "r") as dnaData:
        dataCsv = csv.reader(dnaData)
        for line in dataCsv:
            dnaList.append(line)

    # Read DNA sequence file into dna
    with open(argv[2], "r") as dnaSequence:
        dna = dnaSequence.read()


    # Store all STR sequences into STRs list and loop over STRs to find the longest count by using longest_match and passing the dna which is sample to check with the STR known sequences and then appending the longest count of every STR in sequence inside longest_STR list
    longest_STR = []
    STRs = dnaList[0][1:]
    for STR in STRs:
        longest_count = longest_match(dna, STR)
        longest_STR.append(str(longest_count))

    # Declare match_found as false and check in dnaList chipping from second column to the end, if the longest_STR count matches with any sequences, print Row with the name stored at first most column at index 0 and set match_found to True and break the loop
    match_found = False
    for row in dnaList[1:]:
        if longest_STR == row[1:]:
            print(row[0])
            match_found = True
            break

    # If match_found is still equal to False, that means that the loop ran successfully without finding any match and henceforth no match found shall be the output
    if match_found == False:
        print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
