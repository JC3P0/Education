import os

def check_dict(key,dict):
  if key not in dict.keys():
    return "No match found."
  else:
    return dict[key]
  
def build_dict(filename):
  flashcards = dict()

  with open(filename, "r") as fileIn:
    for line in fileIn.readlines():
      line = line.replace("\n", "")
      question, answer = line.split(",")
      question = question
      answer =  answer
      # print(question, " ->", answer)
      flashcards[question] = answer
  return flashcards

def count():
  file1 = open('count.txt', 'r')
  count = file1.read()
  # print(count)  
  file1.close()
  return count

def flip(boolean_variable):
  file1 = open('count.txt', 'w')
  file1.write(boolean_variable)
  file1.close

def add_word(word, definition):
  file1 = open("database.txt", 'a')
  new_word = "\n"+word + "," + definition
  file1.write(new_word)
  file1.close()