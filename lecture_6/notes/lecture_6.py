# Introducing Python + Python Shorts
# PLEASE NOTE: My PRIMARY language is Python. Most notes below are notes on concepts that I want to IMPROVE on.

# Part 1: Printing, Compiling, User Input --> Proficient
# - print("hello," + answer)
# - print("hello,", answer)
# - print(f"hello, {answer}")

# Part 2: Declaring a variable, if-else statements, while loop, for loop --> Proficient
# - counter = 0
# - counter += 1
# - if x > y: return true else: return false
# - if x > y: return true elif: x == y return true else: return false
# - while True: i += 1
# - while i < 10: print("cough")
# - for i in range(3): print("cough")

# Part 3: List variations --> Proficient
# - range (numbers), list(mutable), tuple(immutable), dictionary(hash table), sets(unique values)

# Part 4: blur.py
# import PIL import Image, ImageFilter

# before = Image.open("bridge.bmp")
# after = before.Filter(ImageFilter.BLUR)
# after.save("out.bmp")

# Part 5: dictionary.py
# words = set()

# def check(word):
#     if word.lower() in words:
#         return True
#     else:
#         return False

# def load(dictionary):
#     file = open(dictionary, "r'")
#     for line in file:
#         words.add(line.rstrip("\n")) # --> removes the ending "\n"
#     file.close()
#     return True

# def size():
#     return len(words)

# def unload():
#     return True

# Part 6: Random Python Practice
# string.py
# from cs50 import get_string

# s = get_string("What is your name? \n")
# print(f"Hello, {s}")




# int.py
# from cs50 import get_int

# age = get_int("What is your age? \n")
# print(f"You are at least {age * 365} days old!")




# conditions.py
# from cs50 import get_int

# x = get_int("x: ")
# y = get_int("y: ")
# if x < y:
#     print("True")
# elif x > y:
#     print("False")
# else:
#     print("x and y are equal")





# agree.py
# from cs50 import get_string

# s = get_string("Do you agree?\n")
# if s.lower() in ["y", "yes"]:
#     print("agreed")
# elif s.lower() in ["n", "nope"]:
#     print("not agreed")





# cough.py
# def cough():
#     print("cough")

# for i in range(3):
#     cough()



# Part 7: Main()
# def main():
#     cough(3)

# def cough(n):
#     for i in range(n):
#         print("cough")

# main()



# positive.py
# from cs50 import get_int

# def main():
#     i = get_positive_int()
#     print(i)

# def get_positive_int():
#     while True:
#         n = get_int("Positive integer: ")
#         if n > 0:
#             break
#     return n

# main()




# Part 8: Mario
# for i in range(4):
#     print("?", end="") # --> This is how you override the auto "\n"
# print()

# print("#\n" * 3, end="")

# for i in range(3):
#     for j in range(3):
#         print("#", end="")
#     print()






# Part 9: Lists and Arrays

# scores.py
# scores = [];
# scores.append(72)
# scores.append(33)
# scores.append(22)

# print(f"Average: {sum(scores) / len(scores)}")



# # string2.py
# s = input("Input:")
# # print("Output: ", end="")

# for i in range(len(s)):
#     print(s[i], end="")
# print()




# uppercase2.py
# s = input("Before: ")
# print("After: ", end="")
# print(s.upper())




# argv.py
# from sys import argv

# for i in range(len(argv)):
#     print(argv[i])



# exit.py
# from sys import argv, exit

# if len(argv) != 2:
#     print("Missing command-line argument")
#     exit(1)
# print(f"hello, {argv[1]}")




# names.py
# from sys import exit
# name = ["Gian", "Anjanetter", "Bubbles"]

# if "dadwead" in name:
#     print("Found!")
#     exit(0)
# print("Not Found!")
# exit(1)





# phonebook.py
# from sys import exit

# people = {
#     "Gian": "456-354-5456",
#     "Anj": "484-534-5315",
#     "Bubbles": "435-987-5455"
# }

# if "adw" in people:
#     print(f"Found {people['axsadw']}")
#     exit(0)
# print("Not Found!")
# exit(1)




# compare.py
# s = input("s: ")
# t = input("t: ")

# if s == t:
#     print("same")
# else:
#     print("Different")




# swap.py
# x = 1
# y = 2

# print(f"x is {x}, y is {y}")
# x, y = y, x

# print(f"x is {x}, y is {y}")






# phonebook2.py --> writing a new file --> this appends a name and number into a csv
# import csv

# file = open("phonebook.csv", "a")
# --> with openopen("phonebook.csv", "a") as file

# name = input("Name: ")
# number = input("Number: ")

# writer = csv.writer(file)
# writer.writerow((name, number))

# # file.close()





# Part 10: Regular Expressions
import re
from cs50 import get_string

s = get_string("Do you agree?\n")

if re.search("y(es)?", s, re.IGNORECASE): # --> syntax to search "everything"
    print("agreed")
elif re.search("n(o)?", s, re.IGNORECASE):
    print("not agreed")

