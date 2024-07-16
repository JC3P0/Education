'''
DEVELOPER: Josh Clemens
'''
""" This program is to create lottery cards. The user can select their own numbers or have the numbers randomly selected for them.
"""
##### IMPORTS #####

import random #creates random numbers for lottery_list

##### FUNCTION DEFINITIONS #####

def generate():
    #create array object to be returned at end of function
    lottery_list = []
    #generates first 5 random numbers
    for count in range(5):
        #.append adds to the array list
        lottery_list.append(random.randrange(1, 49))

    #generates random number for mega number
    for count in range(1):
        #.append adds to the array list
        lottery_list.append(random.randrange(1, 19))

    # print(lottery_list) #test line
    #return the random generated lottery_list
    return lottery_list

def create():
    #create array object to be returned at end of function
    lottery_list = []
    #gets first 5 lotto numbers from user
    for count in range(5):
        item = int(input("Enter your lottery number between 1 and 49: "))
        #while loop to validate 1-49 numbers and numbers cannot repeat
        while item < 1 or item > 49 or item in lottery_list:
            print("Invalid entry. Number must be between 1 and 49. Numbers cannot be repeated.")
            item = int(input("Enter your lottery number between 1 and 49: "))

        #.append adds to the array list with user input "item"
        lottery_list.append(item)

    #gets mega number from user
    for count in range(1):
        item = int(input("Enter your mega number between 1 and 19: "))
        #while loop to validate 1-19 input
        while item < 1 or item > 19:
            print("Invalid entry. Number must be between 1 and 19.")
            item = int(input("Enter your mega number between 1 and 19: "))
        # print(item) #test line
        #.append adds to the array list with user input "item"
        lottery_list.append(item)

    # print(lottery_list) #test line
    return lottery_list

##### MAIN PROGRAM #####

def main():

    #intro
    print("Welcome to Python Lotto!")
    print("You have the option to choose your own lottery numbers or have them randomly selected for you.")
    answer = False
    #while condition for valid menu option
    while answer is False:
        choice = input("Please enter C for custom or R for random: ")

        if choice == "R":
            #create object with generate funtion
            lottery_list = generate()
            # print(lottery_list) #test line
            #display results with ":02d" ex:(04)
            print(f"Your lottery ticket is: {lottery_list[0]:02d} {lottery_list[1]:02d} {lottery_list[2]:02d} {lottery_list[3]:02d} {lottery_list[4]:02d} (mega {lottery_list[5]:02d}).")
            answer = True #while condition for valid menu option

        elif choice == "C":
            #create object with create funtion
            lottery_list = create()
            #display results with ":02d" ex:(04)
            print(f"Your lottery ticket is: {lottery_list[0]:02d} {lottery_list[1]:02d} {lottery_list[2]:02d} {lottery_list[3]:02d} {lottery_list[4]:02d} (mega {lottery_list[5]:02d}).")
            answer = True #while condition for valid menu option
        else:
            print("Invalid, try again!") #while condition for valid menu option (anything other than 'C' or 'R' is Invalid)

    # print("Thank you for using the program!") # testing out of while loop

if __name__ == "__main__":
    main()