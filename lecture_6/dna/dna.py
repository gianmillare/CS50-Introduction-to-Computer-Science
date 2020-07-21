import csv
from sys import argv, exit

def max_count_of_substring(s, sub): # count the max number of times a substring is repeated
    # create an array equal to the length of the sequence, values starting at 0
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1): # start from the end where length of substring is inclusive
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    # return the max of ans
    return max(ans)

def print_match(people_data, result):
    for i in people_data:
        person = i[0]
        values = []
        for value in i[1:]:
            values.append(int(value))

        if values == result:
            print(person)
            return
    print("No match")


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # read the database into memory
    csv_path = argv[1]
    with open(csv_path) as csv_file:
        reader = csv.reader(csv_file)

        # save the rows of the reader into a variable, drop the first row
        people_data = []
        for i in reader:
            people_data.append(i)
        header = people_data.pop(0)[1:]

        # read the sequences into memory
        with open(argv[2]) as txt_file:
            s = txt_file.read()

            # initialize max_count_of_substring using s and sequences stored in header, store the answers into an array
            result = [];
            for sequence in header:
                result.append(max_count_of_substring(s, sequence))

            print_match(people_data, result)

if __name__ == "__main__":
    main()