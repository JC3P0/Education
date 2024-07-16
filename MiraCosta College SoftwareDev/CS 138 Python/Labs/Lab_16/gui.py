####################### do not touch down here #########################

from dictionary import build_dict
import random
import tkinter
import tkinter.messagebox
import dictionary
pages = {}

LARGE_FONT = ("Verdana", 14)
MED_FONT = ("Verdana", 10)
# call the build_dict using database.txt file and save it to the variable flashcards
flashcards = build_dict("database.txt")


class MyGUI:
  def __init__(self):
    
    self.main_window = tkinter.Tk()
    self.main_window.title("FlashCards")
    self.main_window.geometry("800x500")
    

    self.page_frame = tkinter.Frame(self.main_window, background = "white")
    self.page_frame.pack(side = "top", fill = "both", expand = True)
    self.page_frame.grid_rowconfigure(0,weight=1)
    self.page_frame.grid_columnconfigure(0,weight=1)


    for F in (StartPage, SecondPage, ThirdPage, FourthPage):
      self.page = F(self.page_frame,self.main_window).get_page()
      pages[F] = self.page
      self.page.grid(row = 0, column = 0, sticky = "nsew")

    show_page(StartPage)

    tkinter.mainloop()

    
def show_page(cont):
  page = pages[cont]
  page.tkraise()


####################### do not touch down here #########################
class StartPage():
  ################# Creating init method ###################
  # create a method init with arguments self, parent, root
  def __init__(self, parent, root):

    ######################### Creating Frame #########################
    # create an attribute page_frame Frame at parent and background  white
    self.page_frame = tkinter.Frame(parent, background = 'white')

    ########################## Creating Label #########################
    # create an attribute label Label at the attribute page_frame, text WELCOME TO FLASHCARDS, font  LARGE_FONT, background white
    self.label = tkinter.Label(self.page_frame, text = "WELCOME TO FLASHCARDS", font = LARGE_FONT, background = "white")
    
    ######################## Creating Buttons #########################
    # create an attribute button_next Button at attribute page_frame, text Exit, width 10, command root.destroy 
    self.button_next = tkinter.Button(self.page_frame, text = "Exit", width = 10, command = root.destroy)
    # create an attribute button_edit Button at attribute page_frame, text Edit, width 10, command self.edit
    self.button_edit = tkinter.Button(self.page_frame, text = "Edit", width = 10, command = self.edit)
    # create an attribute button_study Button at attribute page_frame, text Study, width 10, command self.study
    self.button_study = tkinter.Button(self.page_frame, text = "Study", width = 10, command = self.study)

    ####################### Adding to the pack #########################
    # add the attribute label to the pack, side top, pady (150,20)
    self.label.pack(side = "top", pady = (150, 20))
    # add button_edit attribute to the pack
    self.button_edit.pack()
    # add button_study attribute to the pack
    self.button_study.pack()
    # add button_next attribute to the pack
    self.button_next.pack()
    
  ###################### Creating methods ########################
  # create method edit
  # call the method show_page with argument SecondPage
  def edit(self):
      show_page(SecondPage)

  # create method study
  # call the method show_page with argument ThirdPage
  def study(self):
      show_page(ThirdPage)

  # create method get_page
  # return the attribute page_frame
  def get_page(self):
    self.page_frame


class SecondPage():
    ################# Creating init method ###################
    # create a method init with arguments self, parent, root
  def __init__(self, parent, root):

    ########################## Creating Frames #########################
    # create an attribute page_frame Frame at parent and background white
    self.page_frame = tkinter.Frame(parent, background = "white")
    # create an attribute frame_top Frame at attribute page_frame
    self.frame_top = tkinter.Frame(self.page_frame)
    # create an attribute frame_middle Frame at attribute page_frame
    self.frame_middle = tkinter.Frame(self.page_frame)
    # create an attribute frame_bottom Frame at attribute page_bottom
    self.frame_bottom = tkinter.Frame(self.page_frame)

    ########################## Creating Labels #########################
    # create an attribute label_title Label at attribute frame_top, text EDIT FLASHCARDS, font LARGE_FONT, background white
    self.label_tittle = tkinter.Label(self.frame_top, text = "EDIT FLASHCARDS", font = LARGE_FONT, background = "white")
    # create an attribute label_word Label at attribute frame_middle, text "Enter word:    ", justify left, font MED_FONT
    self.label_word = tkinter.Label(self.frame_middle, text = "Enter word:    ", justify = "left", font = MED_FONT)
    # create an attribute label_def Label at attribute frame_middle, text "Enter defition:" , justify left, font MED_FONT
    self.label_def = tkinter.Label(self.frame_middle, text = "Enter Definition: ", justify = "left", font = MED_FONT)

    ########################## Creating Entry #########################
    # create an attribute entry_word Entry at attribute frame_middle, width 30
    self.entry_word = tkinter.Entry(self.frame_middle, width = 30)
    # create an attribute entry_definition Entry at attribute frame_middle, width 30
    self.entry_definition = tkinter.Entry(self.frame_middle, width = 30)
    
    ######################## Creating Buttons #########################   
    # create an attribute button_add Button at attribute page_bottom, text Add, width 10, command self.add
    self.button_add = tkinter.Button(self.frame_bottom, text = "Add", width = 10, command = self.add)
    # create an attribute button_next Button at attribute page_bottom, text Study, width 10, command self.next   
    self.button_next = tkinter.Button(self.frame_bottom, text = "Study", width = 10, command = self.next)
    # create an attribute button_back Button at attribute page_bottom, text Menu, width 10, command self.back
    self.button_back = tkinter.Button(self.page_frame, text = "Menu", width = 10, command = self.back)
    # create an attribute button_exit Button at attribute page_bottom, text Done, width 10, command self.done
    self.button_exit = tkinter.Button(self.page_frame, text = "Done", width = 10, command = self.done)

    ####################### Adding to the pack #########################
    # add the attribute label_title to the pack
    self.label_tittle.pack()
    # add the attribute label_word to grid row = 0, column = 0, ipadx = 0
    self.label_word.grid(row = 0, column = 0, ipadx = 0)
    # add the attribute label_def to grid row = 1, column = 0, ipadx = 0
    self.label_def.grid(row = 1, column = 0, ipadx = 0)
    # add the attribute entry_word to grid row = 0, column = 1
    self.entry_word.grid(row = 0, column = 1)
    # add the attribute entry_definition to grid row = 1, column = 1
    self.entry_definition.grid(row = 1, column = 1)
    # add the attribute button_add to the pack
    self.button_add.pack()
    # add the attribute button_next to the pack
    self.button_next.pack()
    # add the attribute button_back to the pack
    self.button_back.pack()
    # add the attribute button_exit to the pack
    self.button_exit.pack()
    # add the attribute frame_top to the pack side = 'top', pady = (150,20)
    self.frame_top.pack(side = 'top', pady = (150, 20))
    # add the attribute frame_middle to the pack
    self.frame_middle.pack()
    # add the attribute frame_bottom to the pack
    self.frame_bottom.pack()

  ###################### Creating methods ########################
  # create method next
  # call the method show_page with argument ThirdPage
  def next(self):
      show_page(ThirdPage)

  # create method done
  # call the method show_page with argument FourthPage
  def done(self):
      show_page(FourthPage)

  # create method back
  # call the method show_page with argument StartPage
  def back(self):
      show_page(StartPage)

  # create method get_page
  # return the attribute page_frame
  def get_page(self):
      return self.page_frame

##################### do not touch down here #########################

  def get_flashcards(self):
    return self.flashcards

  def add(self):
    dictionary.add_word(self.entry_word.get(),self.entry_definition.get() )
    flashcards[self.entry_word.get()] = self.entry_definition.get()
    tkinter.messagebox.showinfo('New Word Added', f'The word "{self.entry_word.get()}" and definition "{self.entry_definition.get()}" have been added')


####################### do not touch up here #########################

class ThirdPage():
  ################# Creating init method ###################
  # create a method init with arguments self, parent, root
  def __init__(self, parent, root):

####################### do not touch down here #########################
    self.flashcards = flashcards
    list_keys = self.flashcards.keys()
    quest_list = list(list_keys)
    self.key = quest_list[0]
####################### do not touch up here #########################

    ####################### Creating Frames #########################
    # create an attribute page_frame Frame at parent and background white
    self.page_frame = tkinter.Frame(parent, background = 'white')

    ############# Creating Labels and variable #########################
    # create an attribute value as a StringVar
    self.value = tkinter.StringVar()
    # create an attribute next_value as a StringVar
    self.next_value = tkinter.StringVar()
    # create an attribute label_value Label at attribute page_frame, textvariable  self.value, borderwidth  2, relief  'groove', justify "center", wraplength 500, font MED_FONT
    self.label_value = tkinter.Label(self.page_frame, textvariable = self.value, borderwidth = 2, relief = 'groove', justify = 'center', wraplength = 500, font = MED_FONT)
    # create an attribute label Label at attribute page_frame, text "STUDY PAGE", font  LARGE_FONT, background  'white'
    self.label = tkinter.Label(self.page_frame, text = "STUDY PAGE", font = LARGE_FONT, background = 'white')

    ####################### Creating Buttons #########################
    # create an attribute button_next Button at attribute page_frame, text Next, width 10, command self.turn 
    self.button_next = tkinter.Button(self.page_frame, text = "Next", width = 10, command = self.turn)
    # create an attribute button_exit Button at attribute page_frame, text Done, width 10, command self.next 
    self.button_exit = tkinter.Button(self.page_frame, text = "Done", width = 10, command = self.next)
    # create an attribute button_back Button at attribute page_frame, text Menu, width 10, command root.back   
    self.button_back = tkinter.Button(self.page_frame, text = "Menu", width = 10, command = self.back)
    # create an attribute button_card Button at attribute page_frame, text Flip, width 10, command self.card 
    self.button_card = tkinter.Button(self.page_frame, text = "Flip", width = 10, command = self.card)

    ##################### Adding to the pack #########################
    # add the attribute label to the pack side = 'top', pady = (100,20)
    self.label.pack(side = 'top', pady = (100, 20))
    # add the attribute label_value to the pack pady = (0,20), ipadx = 100, ipady = 50
    self.label_value.pack(pady = (0, 20), ipadx = 100, ipady = 50)
    # add the attribute button_next to the pack
    self.button_next.pack()
    # add the attribute button_card to the pack
    self.button_card.pack()
    # add the attribute button_back to the pack
    self.button_back.pack()
    # add the attribute button_exit to the pack
    self.button_exit.pack()

  ###################### Creating methods ########################
  # create method next
  # call the method show_page with argument FourthPage
  def next(self):
      show_page(FourthPage)

  # create method back
  # call the method show_page with argument StartPage
  def back(self):
      show_page(StartPage)

  # create method get_page
  # return the attribute page_frame
  def get_page(self):
    return self.page_frame

##################### do not touch down here #########################
  
  def turn(self):
    dictionary.flip('False')
    self.next_card()
    self.card()

  def card(self):
    if dictionary.count() == 'True':
      dictionary.flip('False')
      self.value.set(flashcards[self.key])
    elif dictionary.count() == 'False':
      dictionary.flip('True')
      self.value.set(self.key)

  def next_card(self):
    list_keys = flashcards.keys()
    quest_list = list(list_keys)
    self.key = random.choice(quest_list)
    
####################### do not touch up here #########################
class FourthPage:

  ################# Creating init method ###################
  # create a method init with arguments self, parent, root
  def __init__(self, parent, root):

    ########################## Creating Frames #########################
    # create an attribute page_frame Frame at parent and background white
    self.page_frame = tkinter.Frame(parent, background = 'white')

    ########################## Creating Label #########################
    # create an attribute label Label at attribute page_frame, text  "GOOD LUCK ON YOUR TEST", font  LARGE_FONT, background  'white'
    self.label = tkinter.Label(self.page_frame, text = "GOOD LUCK ON YOUR TEST", font = LARGE_FONT, background = 'white')

    ####################### Creating Buttons #########################
    # create an attribute button_next Button at attribute page_frame, text Start, width 10, command self.next 
    self.button_next = tkinter.Button(self.page_frame, text = "Start", width = 10, command = self.next)
    # create an attribute button_back Button at attribute page_frame, text Exit, width 10, command root.destroy     
    self.button_back = tkinter.Button(self.page_frame, text = "Exit", width = 10, command = root.destroy)

    ##################### Adding to the pack #########################
    # add the attribute label to the pack side = 'top', pady = (150,20)
    self.label.pack(side = 'top', pady = (150, 20))
    # add the attribute button_next to the pack
    self.button_next.pack()
    # add the attribute button_back to the pack
    self.button_back.pack()

  ###################### Creating methods ########################
  # create method next
  # call the method show_page with argument StartPage
  def next(self):
      show_page(StartPage)

  # create method back
  # call the method show_page with argument ThirdPage
  def back(self):
      show_page(ThirdPage)


  # create method get_page
  # return the attribute page_frame
  def get_page(self):
      return self.page_frame
