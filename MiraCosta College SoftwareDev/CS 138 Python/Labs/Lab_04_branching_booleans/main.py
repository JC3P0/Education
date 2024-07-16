'''
DEVELOPER: Josh Clemens
LAST MODIFIED: June 20, 2022
'''
""" This program can be used to determine final course grade or to find the expected number of assignments for a given week of the semester.
"""
import math # for .floor() to pass tests
# num_weeks_completed = 4
num_weeks_completed = 13
# num_weeks_completed = 8
# num_weeks_completed = 3

##### FUNCTION DEFINITIONS #####
 
def determine_grade(uds, labs, eps):
    if uds >= 4 and labs >= 14 and eps >= 45:
        # print('A')
        return('A')
    elif uds >= 3 and labs >= 12 and eps >= 40:
        # print('B')
        return('B')
    elif uds >= 2 and labs >= 10 and eps >= 35:
        # print('C')
        return('C')
    elif uds >= 1 and labs >= 8 and eps >= 30:
        # print('D')
        return('D')
    elif uds >= 0 and labs >= 0 and eps >= 0:
        # print('F')
        return('F')
    elif uds < 0 or labs < 0 or eps < 0:
        return("error")
    else:
        # print("error")
        return("error")

def progress_check_a(num_weeks_completed):
    # 5,9,13,17
    # num_lab = (14 / 16) * num_weeks
    # num_EP = (45 / 16) * num_weeks
    num_lab = (num_weeks_completed / 16) * 14
    num_EP = (num_weeks_completed / 16) * 45
    if num_weeks_completed < 5:
        num_UD = 0
    elif num_weeks_completed >= 5 and num_weeks_completed <= 8:
        num_UD = 1
    elif num_weeks_completed >= 9 and num_weeks_completed <= 12:
        num_UD = 2
    elif num_weeks_completed >= 13 and num_weeks_completed <= 16:
        num_UD = 3
    elif num_weeks_completed >= 17:
        num_UD = 4
    else:
        # print("error")
        return("error")
        
    return math.floor(num_UD), math.floor(num_lab), math.floor(num_EP)

  
##### MAIN PROGRAM #####

# print(determine_grade(4, 14, 45)) #test line
# print(determine_grade(4, -14, 45)) #test line
# print(determine_grade(0, 15, 48)) #test line
# print(determine_grade(4, 13, 48)) #test line
# print(determine_grade(-1, 15, 48)) #test line


num_UD, num_lab, num_EP = progress_check_a(num_weeks_completed)
print(f"To be on track for an A, after completing {num_weeks_completed} weeks of the semester you should have {num_UD} unit deliverables completed, {num_lab} labs completed, and earned {num_EP} engagement points.")