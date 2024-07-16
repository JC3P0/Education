

# x = 1
# while x < 11: # x < 11 is condition
#     print(x)
#     x = x + 1

# sales = float(input('Enter the amout of sales: '))
# comm_rate = float(input('Enter the commission rate: '))
# commission = sales * comm_rate
# print('The commission is $', format(commission, ',.2f'), sep='')

# sales = float(input('Enter the amout of sales: '))
# comm_rate = float(input('Enter the commission rate: '))
# commission = sales * comm_rate
# print('The commission is $', format(commission, ',.2f'), sep='')

# sales = float(input('Enter the amout of sales: '))
# comm_rate = float(input('Enter the commission rate: '))
# commission = sales * comm_rate
# print('The commission is $', format(commission, ',.2f'), sep='')

# count = 0
# while count < 4:
#     sales = float(input('Enter the amout of sales: '))
#     comm_rate = float(input('Enter the commission rate: '))
#     commission = sales * comm_rate
#     print('The commission is $', format(commission, ',.2f'), sep='')
#     count = count + 1

# keep_going = 'y'
# while keep_going == 'y':
#     sales = float(input('Enter the amout of sales: '))
#     comm_rate = float(input('Enter the commission rate: '))
#     commission = sales * comm_rate
#     print('The commission is $', format(commission, ',.2f'), sep='')
#     keep_going = input("Do you want to calculate another person? (Enter y for yes) ")

# for element in [1,2,3,4,5,6,7,8,9,10]:
#     print(element)

# for element in range(11):
#     print(element)
#     #first argument represents the first staring value whle the second represents the end and does not include it
# for element in range(1,11):
#     print(element)

# for element in range(2,11,2):
#     print(element)

# for element in range(10, 0, -1):
#     print(element)

# for character in ['a','b','c','d',]:
#     print(character)


# end = int(input("How many times do you want to print Hello World? "))

# for element in range (1, end+1):
#     print(f'{element}. Hello World')

# MAX = 5
# total = 0

# print(f"This program calculates the sum of {MAX} numbers you will enter.")

# for element in range(MAX):
#     number = int(input("Enter a number: "))
#     # total = total + number
#     total += number

# print(total)

# score = int(input("Enter a test score: "))
# while score < 0:
#     print("Error: the score cannot be negative.")
#     score = int(input("Enter a test score: "))


# while True:
#     score = int(input("Enter a test score: "))
#     if score < 0:
#         print("Error: the score cannot be negative.")
#     else:
#         break

# print (score)

# while True:
#     print("Main Menu: First While Loop")
#     print("A")
#     print("B")
#     print("C (Exit)")
#     answer = input("Enter choice: ")
#     if answer == "A":
#         while True:
#             print("\nMenu A: inner while loop")
#             print("a")
#             print("b")
#             print("c (Exit)")
#             choose = input("Enter choice: ")
#             if choose == "c":
#                 break
#             else:
#                 print(f"Your choice if {choice}")
#     elif answer == "B":
#         while True:
#             print("\nMenu B: inner while loop")
#             print("1")
#             print("2")
#             print("3 (Exit)")
#             choose = input("Enter choice: ")
#             if choose == "3":
#                 break
#             else:
#                 print(f"Your choice if {choice}")
#     else:
#         break

# GUI
import tkinter

main_window = tkinter.Tk()
main_window.title("My first GUI")
main_window.geometry("600x400")
# label1 = tkinter.Label(main_window, text = "Hello World")
# label2 = tkinter.Label(main_window, text = "This is my GUI Program")
label1 = tkinter.Label(main_window, text = "Hello World", borderwidth = 4, relief = 'solid')
label2 = tkinter.Label(main_window, text = "This is my GUI Program", borderwidth = 4, relief = 'raised')
label1.pack()
label2.pack()
# label1.pack(side = "left")
# label2.pack(side = "left")


tkinter.mainloop()