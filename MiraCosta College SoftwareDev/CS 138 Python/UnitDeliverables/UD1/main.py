'''
DEVELOPER: Josh Clemens
LAST MODIFIED: June 26, 2022
'''
"""
This program uses data from https://www.sleepdr.com/the-sleep-blog/new-guidelines-how-much-sleep-do-you-need/ for recommended sleep times for an adult ages 26 - 64. User enters their last week's sleep schedule and the program calculates and prints total hours slept, average hours of sleep, nights of recomended sleep, not recomended sleep and may be recomended sleep.
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

def get_total(N1, N2, N3, N4, N5, N6, N7):
    sum = N1 + N2 + N3 + N4 + N5 + N6 + N7
    return sum

def get_average(total):
    average = total / NIGHTS_OF_WEEK
    return average
    
def process_sleep(N):
    rec_sleep = 0
    may_sleep = 0
    not_sleep = 0
    if N >=7 and N <=9:
        rec_sleep += 1

    elif N >=10 and N <=10:
        may_sleep += 1

    elif N >=6 and N <=6:
        may_sleep += 1
    else:
        not_sleep += 1

    return rec_sleep, may_sleep, not_sleep
    
##########################################
# MAIN PROGRAM:
##########################################

#intro
print("Welcome to the weekly sleep check program!\n\nThis program will process nights of sleep for adults ages 26-64.\nRecommended hours of sleep for adults ages 26-64 are between \n7 and 9 hours.\n6 and 10 hours of sleep may be an appropriate amount of sleep and \nanything else is not recommended.\n")

#declare and initialize variables to add and store the total values as user inputs nights of sleep
recommended_sleep = 0
may_appropriate_sleep = 0
not_recommended = 0

#night 1 
#variable initialzed by users input and used for process_sleep function
N1 = float(input("Enter the hours slept on night 1: "))

#temp variables used to add to total variables as function re-sets variables used to 0 each time its called
rec, may, not_rec = process_sleep(N1)

#adds temp variable to the variables that will store the total of each night of sleep
recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 2
N2 = float(input("Enter the hours slept on night 2: "))

rec, may, not_rec = process_sleep(N2)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 3
N3 = float(input("Enter the hours slept on night 3: "))

rec, may, not_rec = process_sleep(N3)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 4
N4 = float(input("Enter the hours slept on night 4: "))

rec, may, not_rec = process_sleep(N4)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 5
N5 = float(input("Enter the hours slept on night 5: "))

rec, may, not_rec = process_sleep(N5)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 6
N6 = float(input("Enter the hours slept on night 6: "))

rec, may, not_rec = process_sleep(N6)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#night 7
N7 = float(input("Enter the hours slept on night 7: "))

rec, may, not_rec = process_sleep(N7)

recommended_sleep += rec
may_appropriate_sleep += may
not_recommended += not_rec

#testing lines
# print(int(recommended_sleep))
# print(int(may_appropriate_sleep))
# print(int(not_recommended))

#variable to store total from get_total function
total = (get_total(N1, N2, N3, N4, N5, N6, N7))

#variable to store average from get_average function
average = (get_average(total))
# print(f"{average:.2f}")

#output

print(f"\nYou slept a total of {total:.2f} hours, for an average of {average:.2f} hours." )

print(f"\nYou had {recommended_sleep:.0f} days of recommended sleep, {may_appropriate_sleep:.0f} days of may be appropriate\nsleep, and {not_recommended:.0f} days of not recommended sleep.")