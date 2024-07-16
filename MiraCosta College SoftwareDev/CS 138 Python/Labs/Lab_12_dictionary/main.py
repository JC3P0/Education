'''
DEVELOPER: Josh Clemens
COLLABORATOR(S): name(s) of anyone who helped you
'''
""" This program is to create a stack of flashcards then have the user test themselves.
"""
##### IMPORTS #####

##### CONSTANTS #####

##### FUNCTION DEFINITIONS #####

def build_dict(file_name):
    flashcards = dict()
    try:
        open_file = open(file_name, 'r')
        next_line = open_file.readline()
        while next_line != "":
            next_line = next_line.rstrip("\n")
            # print(next_line)

            question, answer = next_line.split(",")
            # print(question)
            # print(answer)
            # dictionary_name[key] = value
            flashcards[question] = answer
            next_line = open_file.readline()
        # print(flashcards)
    except:
        print("File does not exist")

    return flashcards

def check_dict(key, dictionary):
    if key not in dictionary.keys():
        return "No match found."
    else:
        return dictionary[key]

##### MAIN PROGRAM #####

def main():

    print("Let's review your flashcards!")
    flashcards = build_dict("database.txt")
    while True:
        for question, answer in flashcards.items():
            print(f"Question: {question}")
            input("Press Enter to see the answer.")
            print(f"Answer:{answer}")
    
        redo = input("\nEnd of Deck. Redo all cards?(Y/N): ")
        if redo == "N":
            break
    print("\nQuestion Review time.")
    while True:
        question = input("Enter Question(stop to end): ")
        if question == "stop":
            break
        else:
            print(f"Answer: {check_dict(question, flashcards)}")
    print("End of program.")

if __name__ == "__main__":
    main()