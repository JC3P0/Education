

# for character in  "Hello World":
#     print(character)
#     # if character == "o":
#         # print(character)

# print("\n\n")

# for index in range(len("Hello World")):
#     print("Hello World"[index])

# print("\n\n")

# for index in range(11):
#     print("Hello World"[index])


# print("hello" + " " + "world)

# hello = "hello"
# world = "world"

# helo_world = hello + " " + world
# print(hello)

# hello = hello + " " + world
# print(hello)

# pie = "pie"
# apple = ""
# apple += pie # apple = apple + pie

###String are IMMUTABLE ###
#immutable means it cannot change the value

# hello = "hello World"
# "hello World"[0] = "H"

### String Slicing ###
# hello_world = "Hello World"
# # hello = hello_world[0:5]
# # hello = hello_world[:5]
# hello = hello_world[:-6]
# print (hello)

# world = hello_world[6:]
# world = hello_world[6:11]
# world = hello_world[6:len(hello_world)]
# world = hello_world[-5:]

# print(world)

### String Method ###
# helloWorld = "HelloWorld"
# helloWorld = "HELLOWORLD"
# helloWorld = "HelloWorld1234"

# helloWorld = "   Hello World   "
# helloWorld = "   Hello World#*(&#$*9)   "

# verifies if true or False
# print(helloWorld.isalnum())
# print(helloWorld.isalpha())
# print(helloWorld.isdigit())
# print(helloWorld.islower())
# print(helloWorld.isspace())
# print(helloWorld.isupper())

# # return a copy of the string
# print(helloWorld.lower())
# print(helloWorld.lstrip())
# print(helloWorld.lstrip("H"))
# print(helloWorld.lstrip(helloWorld[0]))
# print(helloWorld.rstrip())
# print(helloWorld.rstrip("d"))
# print(helloWorld.rstrip(helloWorld[-1]))
# print(helloWorld.strip())
# print(helloWorld.strip("H"))
# print(helloWorld.strip(helloWorld[0]))
# print(helloWorld.upper())

#Search methods, returns a substring copy
# print(helloWorld.startswith("Hello"))
# print(helloWorld.endswith("World"))
# print(helloWorld.find("Hello"))
# print(helloWorld.find("lo"))
# print(helloWorld.replace("Hello", "Hi"))
# print(helloWorld.replace("l", "L", 2))
# print(helloWorld.replace(helloWorld[0], helloWorld[0].lower(), 1))
# print(helloWorld*6)

### split operator ###
# helloWorld = "Hello from the other side"
helloWorld = "Hello from the other side. It has been a pleasure to meet you. Is there anything i can do for you?"
# helloWorldlist = helloWorld.split()
helloWorldlist = helloWorld.split(".")
print(helloWorld)
print(helloWorldlist)

for word in helloWorldlist:
    print(word)

helloWorldfixed = ".".join(helloWorldlist)
print(helloWorldfixed)