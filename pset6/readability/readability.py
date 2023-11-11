from cs50 import get_string
import ctypes
import math

# Get input
n = get_string("Text: ")

# Assume three kinds
letter = 0
word = 1
sentence = 0

# Get the length of string
j = len(n)

# Loop for the above three
for i in range(0, j, 1):
    if n[i].isalpha():
        letter = letter + 1

    if n[i] == ' ':
        word = word + 1

    if n[i] == '.' or n[i] == '?' or n[i] == '!':
        sentence = sentence + 1

# For fomula
L = float(letter * 100 / word)
S = float(sentence * 100 / word)

index = 0

# Formula
index = 0.0588 * L - 0.296 * S - 15.8

grade = int(round(index))

# Printing process
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
