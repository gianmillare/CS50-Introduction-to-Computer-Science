import cs50
import csv
from sys import argv, exit

def main():
    # Check that the right amount of command line arguments are passed in
    if len(argv) != 2:
        print("Error in Usage ==> filename.py filename.csv")
        exit(1)

    # Start the database using students.db
    db = cs50.SQL("sqlite:///students.db")

    # Read the csv into memory
    with open(argv[1], "r") as csv_file:
        reader = csv.DictReader(csv_file)

        # store each variable from the csv file into a variable
        for row in reader:
            # split the name into first, middle (if any), and last --> returns a list
            name = split_name(row["name"])
            house = row["house"]
            birth = row["birth"]
            # store the variables above into the students.db
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                        name[0], name[1], name[2], house, birth)

# function to split the name into a list with length = 3
def split_name(name):
    # split name into list with length = 3
    name_list = name.split(' ')
    # if full name has three names, return. Else, store the middle name with value None
    if len(name_list) == 3:
        return name_list
    elif len(name_list) == 2:
        return [ name_list[0], None, name_list[1] ]


if __name__ == "__main__":
    main()