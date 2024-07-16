'''
DEVELOPER: Josh Clemens
COLLABORATOR(S): Lab 07 demo video
'''
""" This program demonstrates the use of String methods to process a paragraph.
"""

##### CONSTANTS #####
# Do not change this! It is needed to produce the exact output expected.
DOROTHY_HISTORY = " dorothy Vaughan, née Dorothy Johnson, an American mathematician and computer programmer who made important contributions to the early years of the United States space program and who was the first African American manager at the National Advisory Committee for Aeronautics (NACA), which later became part of the National Aeronautics and Space Administration (NASA). in 1917 Johnson’s family moved from Missouri to West Virginia. she later earned a degree in mathematics (1929) from Wilberforce University near Xenia, Ohio. she worked as a math teacher in Virginia and married Howard Vaughan. in December 1943 she started working for NACA’s West Area Computing unit, a group of African American female mathematicians who where considered “human computers,” performing complex computations and analyzing data for aerospace engineers. the West Computers, as the women where known, provided data that where later essential to the success of the early United States space program. at the time, NACA was segregated, and black employees where forced to use separate bathrooms and dining facilities. despite these conditions, Vaughan was promoted to lead the West Computers in 1949. she became NACA’s first black supervisor and one of its few female supervisors."

##### FUNCTION DEFINITIONS #####

def capitalizing_paragraph(paragraph):

    # replaces "where" with "were" in the paragraph
    replace_paragraph = paragraph.replace("where", "were")
    # print(replace_paragraph) # testing line

    # splits the replace_paragraph from . to . (each sentence)
    paragraph_list = replace_paragraph.split(".")
    # print(paragraph_list) # testing line

    # array created to hold elements in for loop
    final_list = []

    # for loop to go through each element in 
    for element in paragraph_list[:-1]:
        
        # removes the leading white space in each element
        new_element = element.lstrip()    
        # print("/") # testing line to show split elements
        # print(new_element) # testing line
        
        # checks the first letter of each split element (sentence) then replaces the same character with .upper to capitalize the first word of each sentence. the "1" in the .replace(element[0], element[0].upper(), "1") tells it how many time to capitalize that same character when it shows up again in a sentence. if set to 8 and the first character was 'd' it would capitalize the next 8 'd' to 'D' in the sentence
        upper_element = new_element.replace(new_element[0], new_element[0].upper(), 1)
        final_list.append(upper_element)

    # joins the split elements back together, completing each sentence with a . and a space ". "
    paragraph_fixed = ". ".join(final_list) + ". "
 
    # print(paragraph_fixed) # testing line
    return(paragraph_fixed)
    
##### MAIN PROGRAM #####
def main():
  # capitalizing_paragraph(DOROTHY_HISTORY)
    print(f"Corrected paragraph. {capitalizing_paragraph(DOROTHY_HISTORY)} ")

main()