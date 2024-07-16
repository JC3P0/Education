'''
DEVELOPER: Josh Clemens
LAST MODIFIED: July 10, 2022
'''
"""
This program adds two features from Unit 1 project; a while loop menu option and age categories to calculate sleep.

This program uses data from https://www.sleepdr.com/the-sleep-blog/new-guidelines-how-much-sleep-do-you-need/ for recommended sleep times. User enters their age category and their last week's sleep schedule and the program calculates and prints total hours slept, average hours of sleep, nights of recomended sleep, not recomended sleep and may be recomended sleep.
"""

global NIGHTS_OF_WEEK
NIGHTS_OF_WEEK = 7

##########################################
# IMPORTS:
#   <list modules needed for program and their purpose>
##########################################
#none needed

##########################################
# FUNCTIONS:
##########################################

def age_selection():

    # display age categories
    print("\nChose from one of the age categories: \n1) 0-3 Months \n2) 4-11 Months \n3) 1-2 Years \n4) 3-5 Years \n5) 6-13 Years \n6) 14-17 Years \n7) 18-25 Years \n8) 26-64 Years \n9) 65+ Years")
    # gets age input from user
    age = int(input("Enter an age category: "))

    return age

# calculates and returns average
def get_average(total):
    average = total / NIGHTS_OF_WEEK
    return average
    
def process_sleep(age):
    # declare and initialze variables for calculating
    rec_sleep = 0
    may_sleep = 0
    not_sleep = 0
    night = 0
    total = 0
    
    if age == 1:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=14 and night <=17:
                rec_sleep += 1
            elif night >=18 and night <=19:
                may_sleep += 1
            elif night >=11 and night <=13:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 2:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=12 and night <=15:
                rec_sleep += 1
            elif night >=16 and night <=18:
                may_sleep += 1
            elif night >=10 and night <=11:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 3:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=11 and night <=14:
                rec_sleep += 1
            elif night >=15 and night <=16:
                may_sleep += 1
            elif night >=9 and night <=10:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 4:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=10 and night <=13:
                rec_sleep += 1
            elif night == 14:
                may_sleep += 1
            elif night >=8 and night <=9:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 5:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=9 and night <=11:
                rec_sleep += 1
            elif night == 12:
                may_sleep += 1
            elif night >=7 and night <=8:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 6:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=8 and night <=10:
                rec_sleep += 1
            elif night == 11:
                may_sleep += 1
            elif night == 7:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 7:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=7 and night <=9:
                rec_sleep += 1
            elif night >=10 and night <=11:
                may_sleep += 1
            elif night == 6:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 8:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=7 and night <=9:
                rec_sleep += 1
            elif night == 10:
                may_sleep += 1
            elif night == 6:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

    if age == 9:
        # name.upper() to show string manipulation
        print(f"\n{name.upper()}'s week of sleep. Zzz")
        # loop through each night of week getting user's input each loop
        for night in range(NIGHTS_OF_WEEK):
            night = float(input("Enter Night " + str(night + 1) + ": "))
            total += night # calculate total each loop
            if night >=7 and night <=8:
                rec_sleep += 1
            elif night == 9:
                may_sleep += 1
            elif night >=5 and night <=6:
                may_sleep += 1
            else:
                not_sleep += 1
        # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
        return rec_sleep, may_sleep, not_sleep, total

##########################################
# MAIN PROGRAM:
##########################################

#intro
print("Welcome to the sleep recommendation program!")

menu = True # condition to continue while loop

while menu is True:

    name = input("\nEnter name: ") # to show string manipulation

    # gets users age input and creates age to use in process_sleep function
    age = age_selection()
    #declare and initialize variables to store sleep input from function
    recommended_sleep, may_appropriate_sleep, not_recommended, total = process_sleep(age)

    #testing lines
    # print(int(recommended_sleep))
    # print(int(may_appropriate_sleep))
    # print(int(not_recommended))
    # print(int(total))
    
    #variable to store average from get_average function
    average = (get_average(total))
    # print(f"Average = {average:.2f}")
    
    #output
    
    # name.upper() to show string manipulation
    print(f"\n{name.upper()} slept a total of {total:.2f} hours, for an average of {average:.2f} hours per night." )
    
    # name.upper() to show string manipulation
    print(f"\n{name.upper()} had {recommended_sleep:.0f} nights of recommended sleep, {may_appropriate_sleep:.0f} nights of may be appropriate\nsleep, and {not_recommended:.0f} nights of not recommended sleep.")

    # condition to continue or exit while loop
    menu = input("\nWould you like to enter another week of sleep? Y to continue: ")
    if menu == 'y' or menu == 'Y':
        menu = True
    else:
        menu = False

print("Thank you for using the the sleep recommendation program!")