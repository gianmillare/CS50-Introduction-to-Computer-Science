def main():
    # Get a sentence (string) from the user
    s = input("Text: ")

    number_of_letters = count_letters(s)
    number_of_words = count_words(s)
    number_of_sentences = count_sentences(s)

    grade(number_of_letters, number_of_words, number_of_sentences)

def count_letters(s):
    letters = 0

    for i in range(len(s)):
        if(s[i].isalpha()):
            letters += 1

    return letters

def count_words(s):
    words = 0

    for i in range(len(s)):
        if (i == 0 and s[i] != " ") or (i != len(s) - 1 and s[i] == " " and s[i + 1] != " "):
            words += 1

    return words


def count_sentences(s):
    sentences = 0

    for i in range(len(s)):
        if s[i] == "." or s[i] == "!" or s[i] == "?":
            sentences += 1

    return sentences

def grade(x, y, z):
    L = (x / y) * 100
    S = (z / y) * 100

    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()