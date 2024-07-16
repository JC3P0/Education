

# name = input("What is your name? ") # return function input
# number = int("3") # int is a return function

# name = print("What is yout name? ") # void function

# print(number + 5) # void function

###### Creating Functions ######

def this_is_my_first_fucntion(): #defining a void function
    print("\tI am inside my function") #block of code inside function
    print(("\tSecond line indside function"))

def multiplication_integers(x, y): #return function
    multiplication = x*y
    return multiplication # use the return keyword to return a value

def last_first_middle(last, first, middle): #void function
    print(f'My last name is {last}, middle name is {middle}, and first name is {first}.')

def last_first_middle_with_return(last, first, middle): #return function
    return f"My last name is {last}, middle name is {middle}, and first name is {first} as a return value."

global my_name
PI_NUMBER = 3.14
def multiplication_integers_mult_return(x, y): #return function
    num = x*y
    return num, x,y

def main():
    # this_is_my_first_fucntion() # to execute the function you need to call it
    # this_is_my_first_fucntion()
    # this_is_my_first_fucntion()
    # this_is_my_first_fucntion()
    # this_is_my_first_fucntion()
    # this_is_my_first_fucntion()
    # print(return_value)
    # print("I am outside the block of my first function")

    # return_value = multiplication_integers(3, 4)
    # print(return_value)

# last_first_middle("Clemens", "Josh", "Cole")
# last_first_middle(middle="cole", last = "Clemens", first = "Josh")
# last_first_middle("Clemens", middle="Cole", first="Josh")
# my_sibling_name = last_first_middle_with_return("Clemens", "Josh", "Cole")
# print(my_sibling_name)
# print(last_first_middle_with_return("Clemens", "Josh", "Cole"))

# my_name = "Josh"
# print(my_name)
# print(PI_NUMBER)

####### import #######
# import random
#fron tkinter import *

# num = random.randint(1,100)
# print(num)

# multiplication_integers_mult_return(3,4)
prod, first_value, second_value = multiplication_integers_mult_return(3,4)

print(prod,first_value,second_value)

main_window = tkinter.Tk()
main_window.title("My first GUI")
main_window.geometry("600x400")
top_frame = tkinter.Frame(main_window)
bottom_frame = tkinter.Frame(main_window)
label1 = tkinter.Label(top_frame, text="Top1")
label2 = tkinter.Label(top_frame, text="Top2")
label3 = tkinter.Label(top_frame, text="Top3")

label4 = tkinter.Label(bottom_frame, text="Bottom1")
label5 = tkinter.Label(bottom_frame, text="Bottom2")
label6 = tkinter.Label(bottom_frame, text="Bottom3")


label1.pack()
label2.pack()
label3.pack()

label4.pack(side='left')
label5.pack(side='left')
label6.pack(side='left')




main()