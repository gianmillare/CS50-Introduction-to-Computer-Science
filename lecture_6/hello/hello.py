def main():
    name = ask_name()
    greet_user(name)

def ask_name():
    name = input("What is your name?\n")
    return name

def greet_user(name):
    print(f"hello, {name}")

main()