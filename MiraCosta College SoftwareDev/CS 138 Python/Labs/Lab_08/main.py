'''
DEVELOPER: Josh Clemens
'''
""" This program presents user with a menu of services and allows them to select one for additional information.
"""
##### FUNCTION DEFINITIONS #####

def get_login_name(first, last, year):
    # gets the first 3 in each input
    first_name = first[0:3]
    last_name = last[0:3]
    year_born = year[0:3]
    # combines the first 3 of each input into a login_name
    login_name = first_name + last_name + year_born
    # print(login_name) # testing line
    return login_name

def valid_password():

    # initialize values to false to verify
    size = False
    digit = False
    character = False
    capital_letter = False

    # display requirements
    print("Make sure your password is at least 8 characters long, at least one digit, at least one character (@,#,$), and at least one capital.")
    # while loop to validate size, digit, character, capital_letter
    while size is False or digit is False or character is False or capital_letter is False:

        # re initialize values to false for each loop so previous entries do not stay True when they might not be on future entries
        size = False
        digit = False
        character = False
        capital_letter = False
        
        password = input("Enter a password: ") # get users input
        
        #first checks length of password, if not at least 8 characters long it will send strait to else statement before validating the other requitements
        if len(password) >= 8:
            size = True
            # print("size = True") # testing line
            # for loop to check each character in password
            for item in password:
                # checks for an uppercase 
                if (item.isupper()):
                    capital_letter = True
                    # print("capital_letter = True") # testing line
                # checks for a digit
                elif (item.isdigit()):
                    digit = True
                    # print("digit = True") # testing line
                # checks for @, #, $
                elif (item == '@' or item == '#' or item == '$'):
                    character = True
                    # print("character = True") # testing line
            # displays error message only if conditions are not met
            if size is False or digit is False or character is False or capital_letter is False:
                print("Make sure your password is at least 8 characters long, at least one digit, at least one character, and at least one capital.")
        # displays error message if length of password is not met     
        else:
            print("Make sure your password is at least 8 characters long, at least one digit, at least one character, and at least one capital.")
    return password
    

##### MAIN PROGRAM #####

# get users info
first = input("Enter your first name: ")
last = input("Enter your last name: ")
year = input("Enter your year born: ")

# display login name with function
print("Your system login name is: " + get_login_name(first, last, year))

# use function to get users password and verify
valid_password()