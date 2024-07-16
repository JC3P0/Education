# this is the character for commenting code '#' the program does not execute the line, used to add discription to the code
# f(x) = print("Hello World")
# f is print
# x is "Hello World"
# Hello World is a string. a string is made up of individual characters
# every string is enclosed with "",'',"""""", crtl + /
print("Hello World") #print is built-in function
print('Hello World')
print("""Hello World""")
print('''Hello World''')
print("""My list of groceries
      1. Apples
      2. Oranges
      3. Bananas
      """)
# does not work with single or double quotation, must be 3 like above
# print('My list of groceries
#       1. Apples
#       2. Oranges
#       3. Bananas
#       ')
print("Josh Clemens")
print("Welcome to CS 138")

print("I'm the kinf of the world")
print('The book "Hamlet" is my favorite')

print("""I'm excited to read "Hamlet" in my English Class""")
print('''I'm excited to read "Hamlet" in my English Class''')
"""comment multiple
lines in code. using
# only allows line by line commenting but ussing
double/single quotations solves the problem"""

age = 31
print(31)
print(age)

name = "Josh"
print(name)

hello_world = "Hello World."
welcome = "Welcome to CS 138."
variable_3 = "3rd Variable."
print(hello_world, welcome, variable_3)

variable_1 = 99
print(variable_1)
variable_1 = "I am the king of the world!"
print(variable_1)

# input function
number_siblings = input("How many siblings fo you have?")
print(number_siblings)
value = 5 + 3
print(value)
# int() turns arguments to integers
print(int(number_siblings)+ 3)

message = hello_world + welcome + variable_3
message = hello_world + welcome + variable_3
print(message)

print("I like apples" " and oranges for breakfast.")
name = input("Please type your name: ")
print("Welcome " + name + " to CS 138, python")
course = 138
# print("Welcome " + name + " to CS " + course + " , python")
# f-string format
print(f'Welcome {name} to CS {course}, python')

print("\tHello World. \nWelcome to CS 138. \n\t\t3rd Variable.")

num = 123456.789
pi = 3.14569
fibo = 11235813
print(f'{num:<20.2f}')
print(f'{num:>20.2f}')
print(f'{num:^20.2f}')
print(f'{"num" :^12} | {"pi":^12} | {"fibo":^12}')
print(f'-----------------------------------------')
print(f'{num:^12.2f} | {pi:^12f} | {fibo:^12.0f}')

import tkinter
# creates the main window widget
main_window = tkinter.Tk()

# Enter the tkinter main loop
tkinter.mainloop()
