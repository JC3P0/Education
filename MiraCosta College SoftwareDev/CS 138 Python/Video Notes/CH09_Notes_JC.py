########################################dictionaries
#technically a list is a dictionary that maps the index to the elements, key are the index and values are the elements on the list
# list_names = ['Pipper', 'Oliver', 'Charlie']
# key index 0, maps value 'Pipper'
# key index 1 maps value 'Oliver'
# key index 2 maps value 'Charlie'

# dictionary_list = {'normal':'conforming to a standard; usual, typical, or expected','standard': 'a level of quality or attainment', 'basic': 'forming an essential foundation or starting point'}
# print(dictionary_list)
# print(dictionary_list["normal"])
# print(dictionary_list["Normal"])
#######################################adding new elements and deleting

phone_book = {'Chris': 555-1111, 'Katie':555-2222, 'Joanne':555-3333}
# print(phone_book)
# phone_book['Joe'] = "555-4444"
# print(phone_book)
# del phone_book['Katie']
# print(phone_book)
# # if 'Bruce' in phone_book:
# #     del phone_book['Bruce']
# # else:
# #     print('Bruce is not in the phone book')
# try:
#     del phone_book['Bruce']
# except:
#     print('Bruce is not in the phone book')
#####################################len and mixing data
# print(phone_book)
# print(len(phone_book))
# test_scores = {'Kayla': [88,92,100], 'Luis': [95,74,81], 'Sophie': [72,88,91], 'Ethan':[71,75,78]}
# print(test_scores)
# employee_1 = {'name':"Kevin Smith", 'id':12345,'payrate':25.75}
# print(employee_1)
########################################creating empty dictionaries
# phone_book = {}
# print(phone_book)
# phone_book['Chris'] = "555-1111"
# phone_book['Katie'] = "555-2222"
# phone_book['Joanne'] = "555-3333"
# print(phone_book)

# for key in phone_book:
#     print(key)
# for key in phone_book:
#     print(key,phone_book[key])

###########################################some dictionary methods
# phone_book.clear()
# print(phone_book)
# print(phone_book.get('Katie','Key not found'))
# print(phone_book.get('katie','Key not found'))
# print(phone_book.items())
# for key, value in phone_book.items():
#     print(key, value)
# print(phone_book.keys())
# for key in phone_book.keys():
#     print(key)
# print(phone_book)
# print(phone_book.pop('Katie',"Key not found"))
# print(phone_book)
# print(phone_book.pop('katie',"Key not found"))
# print(phone_book)
# print(phone_book.popitem())
# print(phone_book)
# print(phone_book.values())
# for value in phone_book.values():
#     print(value)

#############################################dictionary comprehension
numbers = [1,2,3,4]
squares = {}
for element in numbers:
    squares[element] = element**2
print(squares)

squares = {element:element**2 for element in numbers}
print(squares)

phone_book_copy  = {k:v for k,v in phone_book.items()} #hard copy
# phone_book_copy = phone_book #soft copy

# print(phone_book)
# phone_book.popitem()
# print(phone_book)
# print(phone_book_copy)

# populations = {'New York': 8839785, 'Los Angeles': 3990456, 'Chicago': 2705994, 'Houston':2325502, 'Pheonix': 1660272, 'Philadelphia':1584138}
# largest = {k:v for k,v in populations.items() if v > 2000000}
# print(populations)
# print(largest)

##################################################Sets
my_set = set(['a', 'b', 'c'])
# print(my_set)
# print(len(my_set))
# my_set = set()
# my_set.add(1)
# my_set.add(2)
# my_set.add(3)
# print(my_set)
# my_set.add(2)
# print(my_set)
# my_set.update([4,5,6])
# print(my_set)

my_set_1 = set([4,5,6])
my_set.update(my_set_1)
print(my_set)
my_set.update('abc')
print(my_set)
my_set.remove('c')
print(my_set)
# my_set.remove('d')
# my_set.discard('d')
# my_set.clear()
# print(my_set)
for element in my_set:
    print(element)
if 1 in my_set:
    print("value not found")
if 99 not in my_set:
    print("value not found")

#####################################union intersection difference of set
# set_1 = set ([1,2,3,4])
# set_2 = set ([1,2,3,4])
# set_3 = set_1.union(set_2)
# set_3 = set_2.union(set_1)
# set_3 = set_1 | set_2
# set_3 = set_1.intersection(set_2)
# set_3 = set_1 & set_2
# set_3 = set_1.difference(set_2)
# print(set_3)
# set_3 = set_2.difference(set_1)
# print(set_3)

# set_2 = set([1,2])
# print(set_2 <= set_1)
# print(set_1 <= set_2)

#####################################set comprehension
set_1 = set ([1,2,3,4,5])
set_2 = {element for element in set_1}
print(set_1)
print(set_2)

set_2 = {element**2 for element in set_1}
print(set_2)
set_3 = {element for element in set_2 if element < 10}
print(set_3)
