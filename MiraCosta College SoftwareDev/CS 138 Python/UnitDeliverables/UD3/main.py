'''
DEVELOPER: Josh Clemens
LAST MODIFIED: July 30, 2022
'''

"""
This program adds from unit 2 project. Now the program reads the recomended sleep durations per age group from file sleep_data. The program reads all the sleep_data into a list then gets users age category and returns only the line needed to process_sleep. Uses a "list" to store sleep_data from file as the "key" function in "dictionary" was not needed for this program.

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

def get_list():
    list = []
    while True:
        file_name = "sleep_data.txt"
        # print(file_name)
        try:
            open_file = open(file_name, 'r')
            next_line = open_file.readline()
            while next_line != "":
                # print(next_line)
                data_list = next_line.split()
                # print(data_list)
                list.append(data_list)
                next_line = open_file.readline()
            break
        except:
            print("File does not exist")
            break

    open_file.close()
    selected_list = age_selection(list)
    # print(list)
    # print(data_list)
    return selected_list

def age_selection(list):

    # display age categories
    print("\nChose from one of the age categories: \n1) 0-3 Months \n2) 4-11 Months \n3) 1-2 Years \n4) 3-5 Years \n5) 6-13 Years \n6) 14-17 Years \n7) 18-25 Years \n8) 26-64 Years \n9) 65+ Years")
    #gets age input from user
    age = int(input("Enter an age category: "))
    #use age - 1 to return the line in array per age entered
    selected_list = list[age-1]
    return selected_list

# calculates and returns average
def get_average(total):
    average = total / NIGHTS_OF_WEEK
    return average

def process_sleep(sleep):
    # declare and initialze variables for calculating
    rec_sleep = 0
    may_sleep = 0
    not_sleep = 0
    night = 0
    total = 0

    # loop through each night of week getting user's input each loop
    for night in range(NIGHTS_OF_WEEK):
        night = float(input("Enter Night " + str(night + 1) + ": "))
        total += night # calculate total each loop
        if night >= float(sleep[0]) and night <= float(sleep[1]):
            rec_sleep += 1
        elif night >= float(sleep[2]) and night <= float(sleep[3]):
            may_sleep += 1
        elif night >= float(sleep[4]) and night <= float(sleep[5]):
            may_sleep += 1
        else:
            not_sleep += 1
    # print(f"{rec_sleep}  {may_sleep}  {not_sleep} {total}") # testing line
    return rec_sleep, may_sleep, not_sleep, total

##########################################
# MAIN PROGRAM:
##########################################

def main():

    #intro
    print("Welcome to the sleep recommendation program!")

    menu = True # condition to continue while loop

    while menu is True:

        name = input("\nEnter name: ") # to show string manipulation

        #get the line of data needed from sleep_data.txt per age group from user input
        sleep_data = get_list()
        #declare and initialize variables to store sleep input from function
        recommended_sleep, may_appropriate_sleep, not_recommended, total = process_sleep(sleep_data)

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

if __name__ == "__main__":
    main()