# Importing get_string from cs50
from cs50 import get_string

# Defining function to calculate total letters in the given text
def letters(text):
    letters = 0
    for char in text:
        if char.isupper() or char.islower():
            letters += 1
    return letters

# Defining function to calculate total words in the given text
def words(text):
    words = 1
    for char in text:
        if char in (" "):
            words += 1
    return words

# Defining function to calculate total sentences in the given text
def sentences(text):
    sentences = 0
    for char in text:
        if char in ('.', '!', '?'):
            sentences += 1
    return sentences

# Defining main function
def main():

    # Getting text from user
    text = get_string("Text: ")

    # Counting total number of Letters, Words and Sentences in the given text by user
    num_letters = letters(text)
    num_words = words(text)
    num_sentences = sentences(text)

    # Calculating the Value of L = Letters per 100 words and S = Sentences per 100 words for the Index Formula
    print(f"No. of Letters: {num_letters}, No. of Words: {num_words}, No. of Sentences: {num_sentences}")
    lettersPerWords = (num_letters / num_words) * 100
    sentencesPerWords = (num_sentences / num_words) * 100

    # Calculating the Index Formula to find out the Grade level
    index = round((0.0588 * lettersPerWords) - (0.296 * sentencesPerWords) - 15.8);

    # If index is less than 1 then the grade is Before Grade 1
    if index < 1:
        print("Before Grade 1")

    # If index is more than 16 then the grade is Grade 16+
    elif index > 16:
        print("Grade 16+")

    # Under normal conditions print the Grade level
    else:
        print(f"Grade {index}")

# Call main function
main()

# check50 cs50/problems/2022/x/sentimental/readability
