
# squence ex: list [1,2,3,4,5,6] is defined by[]
# ex: tuple (1,2,3) is defined ()
##################creating a list
# even_numbers = [2,4,6,8,10]
# print(even_numbers)

# names = ["Molly", "Steven", "Will", "Alicia", "Adriana"]
# print(names)

# info = ["Alicia", 27, 1550.87]
# print(info)

# list() #this list function that turns data into a list
# print(list("Hello World"))

###################### Repetition and Iterating

# print(even_numbers*3)
# print(even_numbers)

# for element in even_numbers:
#     print(element)

#using index to access the elements on the list
# [2,4,6,8,10] contains five elemtns
# 0 1 2 3 4 indices
# -5-4-3-2-1 indices
# print(even_numbers[3])
# print(even_numbers[-1])
# # print(even_numbers[7])
# print(len(even_numbers))
# print(even_numbers[len(even_numbers)-1])

################len function and index error
# iterating using list
# for element in even_numbers:
#     print(element)

# iterating using an index
# for index in range (len(even_numbers)):
#     print(even_numbers[index])

# for index in range (len(even_numbers)+3):
#     try:
#         print(even_numbers[index])
#     except IndexError:
#         print("Out of range")

##########################lists are mutable
# even_numbers[0] = 1
# even_numbers[1] = 3
# even_numbers[2] = 5
# even_numbers[3] = 7
# even_numbers[4] = 9
# print(even_numbers)
# # "HelloWorld"[0] = "h" # s string is immuatble, can't be changed
# var_1 = "HelloWorld".replace("H", "h")
# print(var_1)

############################Slicing
# print(even_numbers[2:4]) # slicing [start:end] not including the end
# print(even_numbers[:4]) #starts at 0
# print(even_numbers[2:]) #ends at len(even_numbers)
# print(even_numbers[2:-1])

############################finding items in a list
# to determine if an elemtn is in the list we use keyword "in"
# print(6 in even_numbers)
# print(3 in even_numbers)
# print(6 not in even_numbers)

###########################list methods and building functions
even_numbers = [2,4,6,8,10]
# names = ["Molly", "Steven", "Will", "Alicia", "Adriana"]
# method depends on the object
# ex: strings, list
# function does not, all you need is the correct arguments

# even_numbers is a list object
# methods for the class object list:
# insert(), sort(), remove(), reverse(), amend()
# object_name.method_name()
# even_numbers.insert(1,3)
# print(even_numbers)
# unsorted_list = [6, 3, 5, 9, 1]
# unsorted_list.sort()
# print(unsorted_list)
# names.remove("Molly")
# print(names)
# even_numbers.append(12)
# print(even_numbers)
# del even_numbers[2]
# print(even_numbers)
# print(max(even_numbers))
# print(min(even_numbers))
############################coping list
# list1 = [2,4,6,8,10]
# list2 = list1 # soft copy

# list1[1] = 3
# print(list1)
# print(list2)

# list1_hard_copy = [2,4,6,8,10]
# list2_hard_copy = []

# 1 way to hard copy of list
# for element in list1_hard_copy:
#     list2_hard_copy.append(element)

# print(list1_hard_copy)
# list1_hard_copy[1] = 3
# print(list1_hard_copy)
# print(list2_hard_copy)


# 2 way to hard copy
# list2_hard_copy = [] + list1_hard_copy
# print(list1_hard_copy)
# list1_hard_copy[1] = 3
# print(list1_hard_copy)
# print(list2_hard_copy)

# 3 way to hard copy
# list2_hard_copy = [item for item in list1_hard_copy]
# print(list1_hard_copy)
# list1_hard_copy[1] = 3
# print(list1_hard_copy)
# print(list2_hard_copy)

########################### writing on a list
# open_file = open("NewList.txt", 'w')
# names = ["Molly", "Steven", "Will", "Alicia", "Adriana"]
# # open_file.writelines(names)
# for element in names:
#     open_file.writelines(element + "\n")

# open_file.close()

############################ list comprehensions

# list2 = [item for item in even_numbers]
# print(list2)

# list2 = [item**2 for item in even_numbers]
# print(list2)

# list1 = [1,12,2,20,3,15,4]
# list2 = []
# for element in list1:
#     if element < 10:
#         list2.append(element)
# print(list2)

# list2 = [item for item in list1 is item < 10]
# print(list2)

###########################2 demensional list

# couples = [["Jenny", "John"], ["Rebecca", "Eddie"], ["Jon", "Matt"]]
# print(couples)

################################ tuples

# exam_scores = (65,70,80,100,85)
# print(len(exam_scores))
# print(min(exam_scores))
# print(max(exam_scores))
# print(80 in exam_scores)
# print(exam_scores)
# print(list(exam_scores))
# print(tuple(list(exam_scores)))

###############################matplotlib
import matplotlib.pyplot as plt

# x_coords = [0,1,2,3,4]
# y_coords = [0,3,1,5,2]

# plt.plot(x_coords, y_coords, marker = "o")
# plt.title("Sales by Year")
# plt.xlabel('Year')
# plt.ylabel('Sales')
# plt.xticks([0,1,2,3,4], ['2016', '2017', '2018', '2019', '2020'])
# plt.yticks([0,1,2,3,4,5], ['$0m', '$1m', '$2m', '$3m', '$4m', '$5m'])
# plt.grid(True)
# # plt.xlim(xmin=1, xmax = 100)
# # plt.ylim(ymin=10, ymax = 50)

# plt.show()

# left_edges = [0,10,20,30,40]
# heights = [100,200,300,400,500]
# plt.bar(left_edges, heights)
# plt.show()

# left_edges = [0,10,20,30,40]
# heights = [100,200,300,400,500]
# bar_width = 5
# plt.bar(left_edges, heights, bar_width, color =('r', 'g', 'b', 'w', 'k'))
# plt.show()

values = [20,60,80,40]

plt.pie(values)
plt.show()