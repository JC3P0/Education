'''
DEVELOPER: Josh Clemens
LAST MODIFIED: June 20, 2022

This program implements the projectile formula to a function.

'''

# from module_file import *

#### CONSTANTS SECTION ####
# Step 1: Defining a constant global variable
global ACCELERATION
ACCELERATION = -9.8
# print(ACCELERATION)

#### FUNCTIONS SECTION ####
# Step 2: Defining a function to find the time of the maximum height
# name the function calc_time_max_height

def calc_time_max_height(velocity):
    time = -velocity / ACCELERATION
    return time
  
# print(calc_max_height(39.2)) #test line


# Step 3: Defining a function to find the height of the maximum height
# name the function calc_max_height

def calc_max_height(velocity, initial_height, time):
    height = (1/2 * ACCELERATION * time ** 2) + (velocity * time) + (initial_height)
    return height


# Step 6: Combining two functions into one and returning two outputs
# name the function find_peak
    
def find_peak(initial_velocity, initial_height):
    max_time = calc_time_max_height(initial_velocity)
    max_height = calc_max_height(initial_velocity, initial_height, max_time)
    return max_time, max_height


#### MAIN PROGRAM ####
# Step 4: Using the calc_time_max_height to find the time of the maximum height
# passed values to a variable. Using the calc_max_height to find the maximum height and
# passed values to a variable.

max_time = calc_time_max_height(39.2)
max_height = calc_max_height(39.2, 3, max_time)
# print(max_time) #testing lines
# print(max_height)


# Step 5: Printing the results using calc_time_max_height and calc_max_height output.
print(f"The maximum time of the ball with velocity 39.2 m/s and initial velocity 3 meters is {max_time:.2f} sec, with maximum height {max_height:.2f} meters using the two functions.")

# Step 7: Using the find_peak to find the maximum height and time
# passed values to two different variables

peak_time, peak_height = find_peak(39.2, 3)
# print(peak_time) #test lines
# print(peak_height)


# Step 8: Printing the results using the find_peak output

print(f"The maximum time of the ball with velocity 39.2 m/s and initial velocity 3 meters is {peak_time:.2f} sec, with maximum height {peak_height:.2f} meters using the two functions.")