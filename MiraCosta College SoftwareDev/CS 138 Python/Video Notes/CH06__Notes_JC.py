
### Reding from file ###
# file_object = open(file_name, mode) 'r' read, 'w' write, 'a' append

# open_file = open("HelloWorld.txt", 'r')

# one way
# print(open_file.read())

# open_file = open("HelloWorld.txt", 'r')
# print(open_file.read())

# second way
# for line in open_file:
#     print(line)

# third way

# print(open.file.readline().rstrip())
# print(open.file.readline().rstrip())
# print(open.file.readline().rstrip())
# line = open_file.readline()
# line = open_file.readline().rstrip()
# while line:
#     print(line)
#     line = open_file.readline().rstrip()
    
# open_file.close

## reading from Strings ##
# open_file = open ("NumbersList.txt", 'r')
# for line in open_file:
#     # line = "1"
#     # int(line) "1" - > 1
#     print(int(line) + 3)
### writing to a file (Overrides everything) ###
# open_file = open("NewFile.txt", 'w')
# open_file.write("We are creating a new file.")
# open_file.close()

# open_file = open("HelloWorld(Copy)", 'w')
# open_file.write("I like to play video games")
# open_file.close()

### writing to a file of numbers ###
# open_file = open("NumbersEditing.txt", 'w')
# for index in range(1,11):

#     open_file.write(index)
#     # open_file.write(str(index) + '\n')
# open_file.close()

###append to a file###
# open_file = open("HelloWorld.txt", 'a+')
# open_file.write("\nI like to play video games")
# open_file.close()

###Try exception###
# print(x)
# x = 2
# try:
#     print(x)
# except:
#     print("An exception occured")

# x = 2
# try:
#     print(x/0)
# except NameError:
#     print("var x is not defined")
# except ZeroDivisionError:
#     print("Divisioin by zero")
# print("Hello")
# x = 2
# try:
#     print(x)
# except:
#     print("Something went wrong")
# finally:
#     print("The 'Try except' is finished")

# x = 2
# try:
#     print(x)
# except:
#     print("Somthing went wrong")
# print("The 'Try except' is finished")

# f = open("Thanos.txt")

# try:
#     f = open("NewFile.txt", 'a')
#     # f.write("Lorum Ipsum")
#     try:
#         f.write("Lorum Ipsum")
#     except:
#         print("Soomthing went wrong when writing to file")
#     finally:
#         f.close()
# except:
    print("Soomthing went wrong wheil opening the file")

# x = -1
# if x < 0:
#     raise Exception("Sorry, no numbers below zero.")

# x = "Hello"
# if not type(x) is int:
#     raise TypeError("Only integers allowed")

### encryption and decryption ###
# my goal is encrypt a data encrypt (String) using a key (integer)

# def encrypt(data_encrypt, key):
#     new_string = ""
#     for character in data_encrypt:
#         number = ord(character)
#         number = number + key
#         new_character = chr(number)
#         new_string = new_string + new_character
#     print(new_string)



# def main():
#     encrypt("FGHIJ", 10)

# if __name__ == '__main__':
#     main()
