# Import the required libraries
import sys
import csv


def main():
    # Ensure the three arguments
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py csv_file dna_file")

    # Create the lists and dictionary
    memory = []
    sequence = []
    sq = {}

    # Open the csv file and read it into memory
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        # Go through each row
        for row in reader:
            # Go through the individual item
            for ind in row:
                if row[ind].isdigit():
                    row[ind] = int(row[ind])
            memory.append(row)

    # Open the DNA file and read it into sequence
    with open(sys.argv[2]) as datafile:
        reading = datafile.read()
        for row in reading:
            sequence.append(row)

    # Check for the dna string
    for person in memory:
        # Check the individual item for each person
        for ind in person:
            # Skip if the item is name
            if ind == "name":
                continue
            else:
                # Update the result by this
                sq[ind] = result(sequence, ind)
        break

    # Go through the csv file
    for profile in memory:
        # Count each match
        match = 0
        # Go through each ind
        for ind in sq:
            # If the STR is equal to the sq
            if sq[ind] == int(profile[ind]):
                match += 1
            # Print out the name if values in key matches
            if match == len(sq):
                print(profile['name'])
                sys.exit(0)
    # If not print no match
    print("No match")
    sys.exit(1)


def result(sequence, dna_str):
    # Read the STR and the longest one
    count = 0
    max_count = 0

    L = len(dna_str)
    # Split the string into the list of char
    dna_char = list(dna_str)

    # For each position in sequence: compute how many times the STR repeat starting at that position
    for i in range(len(sequence)):
        # If position is equal to the string
        if sequence[i: (i + L)] == dna_char:
            count = 0
            while sequence[i: (i + L)] == dna_char:
                count += 1
                i += L
            if count > max_count:
                max_count = count
    return max_count


if __name__ == "__main__":
    main()