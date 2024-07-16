'''
DEVELOPER: Josh Clemens
'''
""" This program reads grades from a file, calculates averages, then creates a bar graph.
"""
##### IMPORTS #####

import matplotlib.pyplot as plt

##### CONSTANT VARIABLES #####

##### FUNCTION DEFINITIONS #####

def get_list():
    list = []
    # file_name = "grades.txt"
    while True:
        file_name = "grades.txt"
        # print(file_name)
        try:
            open_file = open(file_name, 'r')
            next_line = open_file.readline()
            next_line = open_file.readline()
            while next_line != "":
                # print(next_line)
                grade_list = next_line.split()
                # print(grade_list)
                student, final_grade = create_student(grade_list)
                list.append((student, final_grade))
                next_line = open_file.readline()
                # list = open_file.read().splitlines()
            break
        except:
            print("File does not exist")
            break

    open_file.close()
    print(list)
    return list

def average(list):
    temp = [int(element) for element in list]
    average = sum(temp) / len(temp)
    return average

def create_student(grades):
    student = ""
    final_grade = 0
    min_grade = min(grades[1:-1])
    # print(min_grade)
    final_exam = grades[-1]
    # print(final_exam)
    if min_grade < final_exam:
        grades.remove(min_grade)
        # print(grades)
        grades.append(final_exam)
        # print(grades)
    # print(grades[1:])

    final_grade = average(grades[1:])
    # print(grades[0])
    student = grades[0]

    return student, final_grade

def plotting_graph(list_tuples): #tuple is (x,y) or (x,y,z)
    x_coords = []
    y_coords = []
    [('Thorny', 85.0), ('Mac', 91.75), ('Farva', 76.75), ('Steve', 74.75), ('Ursula', 74.25), ('Foster', 96.75)]
    for index in range(len(list_tuples)):
        x_coords.append(list_tuples[index][0])
        y_coords.append(list_tuples[index][1])
    print(x_coords)
    print(y_coords)
    plt.plot(x_coords, y_coords, marker = "o")
    plt.title("Student Grades")
    plt.xlabel("Students")
    plt.ylabel("Grades")
    plt.grid(True)
    plt.show()

##### MAIN PROGRAM #####

def main():

    list = get_list()
    plotting_graph(list)

    # get_list()
    # grades = get_list()
    # print(grades)
    # temp = create_student(get_list())
    # print(temp)
    # plotting_graph(temp)

if __name__ == "__main__":
    main()