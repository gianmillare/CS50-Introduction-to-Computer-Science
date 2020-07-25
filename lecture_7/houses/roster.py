import cs50
from sys import argv, exit

def main():
    # Ensure that the number of command-line arguments == 2
    if len(argv) != 2:
        print("Error in Usage ==> filename.py 'house' ")
        exit(1)

    # store the database into a variable db
    db = cs50.SQL("sqlite:///students.db")
    # store the house in question into a variable --> not "house" to avoid confusion
    stdin_house = argv[1]

    # store the SQL output into a variable
    stdout_students = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", stdin_house)

    # loop through the output to print out the students and birth year
    for student in stdout_students:
        # store the name and birth year into variables
        first_name = student["first"]
        middle_name = student["middle"]
        last_name = student["last"]
        birth = student["birth"]
        # if middle name exists, print accordingly. Else, exclude "None"
        if middle_name:
            print(f"{first_name} {middle_name} {last_name}, born {birth}")
        else:
            print(f"{first_name} {last_name}, born {birth}")

if __name__ == "__main__":
    main()