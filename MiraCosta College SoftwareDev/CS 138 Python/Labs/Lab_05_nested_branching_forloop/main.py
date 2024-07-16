'''
DEVELOPER: Josh Clemens
'''
""" This program presents user with a menu of services and allows them to select one for additional information.
"""

##### CONSTANTS #####
# Do not change these! They are needed to produce the exact output expected.
LANGUAGE_LAB = "\nDid you know that MiraCosta has a Language Lab where you could schedule a one-on-one language coaching appointments through Zoom? \n\nCheck out their page: https://www.miracosta.edu/academics/degree-and-certificate-programs/languages-communication-and-humanities/international-languages/language-resource-center.html "
MLC="\nMLC is a great resource if you have questions regarding math topics! You can drop in for an appointment or schedule one at your convenience. \nMore information about the center is found here: https://www.miracosta.edu/student-services/math-learning-center/index.html"
STEM="\nIf you have questions concerning courses in Biology, Biotechnology, Chemistry, Computer Science, Physics, Astronomy, Oceanography, Earth Science, Geology, Horticulture, and Physical Science, don't be shy and go to:\nhttps://www.miracosta.edu/student-services/stem/index.html "
FOOD_PANTRY="\nExperiencing food insecurity? No problem, Food Pantry at MiraCosta College has your back! Food Pantry provides food assistance and referrals to students experiencing hunger\nhttps://www.miracosta.edu/student-services/care/food-pantry.html "
HEALTH_SERVICES="\nWe have amazing Student Health Services that are now open on campus! They offer a variety of health support for MiraCosta students including telehealth and teletherapy appointments. You can make an appointment here \nhttps://www.miracosta.edu/student-services/health-services/index.html"
MENTAL_HEALTH_SERVICES="\nFeeling anxious and/or stressed? MiraCosta Health Services offer Mental Health counseling. Free and confidential telehealth Counseling and Mental Health Services are available via Zoom or Phone to currently enrolled student. Simply follow the link \nhttps://www.miracosta.edu/student-services/health-services/counseling-and-mental-health-services.html"
  
# FUNCTIONS#

def main_menu():
    print("\n1. Academic Support\n2. Campus Services\n3. Exit\n")

def academic_menu():
    print("\na)Language lab\nb)Math Learning Center\nc)STEM Learning Center\n")

def campus_menu():
    print("\na)Food Pantry\nb)Health Services \nc)Mental Health Services\n")


##### MAIN PROGRAM #####

def main():
    print("\n***Welcome to MiraCosta College Student Resources*** \n")
    print("As you may already know we offer many services for our students.")
    print("Please choose one of the following options:")


# Display suboptions of the Academic Support choice:


# Display suboptions of the Campus Services choice:


main()

while True:
    main_menu()
    choose = input("Enter your choice from the above options : ")
    if choose == "1":
        while True:
            academic_menu()
            choose = input("Choose from the options above : ")
            if choose == "a":
                print(LANGUAGE_LAB)
                break
            elif choose == "b":
                print(MLC)
                break
            elif choose == "c":
                print(STEM)
                break

        input("\nPress enter to return to main menu.")
    elif choose == "2":
        while True:
            campus_menu()
            choose = input("Choose from the options above : ")
            if choose == "a":
                print(FOOD_PANTRY)
                break
            elif choose == "b":
                print(HEALTH_SERVICES)
                break
            elif choose == "c":
                print(MENTAL_HEALTH_SERVICES)
                break

        input("\nPress enter to return to main menu.")
    else:
        break

print("\nHappy studying, bye!!!")