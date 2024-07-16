'''
DEVELOPER: Josh Clemens
'''
""" This program can be used to encrypt or decrypt text using a shift cipher.
"""

##### FUNCTION DEFINITIONS #####

#gets and return users choice from encrypt or decrypt
def menu_option():
    answer = False
    while answer is False:
        choice = input("Chose from encrypt or decrypt: ")
        if choice == "encrypt" or choice == "decrypt":
            answer = True
 
    return choice

#verifies there is a file to read from
def in_file():
    answer = False
    while answer is False:
        inFile = input("Enter the name of Text file: ")
        inFile = inFile + ".txt"
        try:
            open_file = open(inFile, 'r')
            open_file.close()
            answer = True
        except:
            print("File does not exist")

    return inFile

#defines the outFile name and append or overwrite choice
def out_file():
    answer = False
    while answer is False:
        outFile = input("Enter the name of the Text file to write to: ")
        outFile = outFile + ".txt"
        choice = input("Enter append or overwrite: ")
        if choice == "append" or choice == "overwrite":
            answer = True

    return choice, outFile

    # return outFile

#encrypts a file per "key" shifts
def encrypt(data_encrypt, key):
    new_string = ""
    for character in data_encrypt:
        number = ord(character)
        number = number + key
        new_character = chr(number)
        new_string = new_string + new_character
    
    return new_string
    
#decrypts a file per "key" shifts
def decrypt(data_decrypt, key):
    new_string = ""
    for character in data_decrypt:
        number = ord(character)
        number = number - key
        new_character = chr(number)
        new_string = new_string + new_character
    
    return new_string
            
##### MAIN PROGRAM #####

def main():
    #store menu_option for if elif statement
    menu_choice = menu_option()
    #store file_name for opening file in if elis statements
    file_name = in_file()
    #store out_choice and outFile for append, overwrite value and file name to be written to
    out_choice, outFile = out_file()
    #user enters number of key shifts
    key = int(input("""Enter how many "key" shifts: """))

    #users choice from encrypt or decrypt
    if menu_choice == "encrypt":
        #read and store the file to inFile
        open_file = open(file_name, 'r')
        inFile = open_file.read()
        #store encrypt_file after passing through function
        encrypt_file = encrypt(inFile, key)
        #writes encrypted message to outFile
        open_file = open(outFile, 'w')
        open_file.write(encrypt_file)
        open_file.close()

    elif menu_choice == "decrypt":
        #read and store the file to inFile
        open_file = open(file_name, 'r')
        inFile = open_file.read()
        #store decrypt_file after passing through function
        decrypt_file = decrypt(inFile, key)
        #writes decrypt message to outFile
        open_file = open(outFile, 'w')
        open_file.write(decrypt_file)
        open_file.close()

if __name__ == "__main__":
    main()