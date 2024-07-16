from gui import MyGUI

def main():
    my_gui = MyGUI()
    print("Hello World")
    
if __name__ == "__main__":
    main()
	
######################################################


import tkinter
import tkinter.messagebox
# from tlinter import *
class MyGUI:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title("This is my Window")
        self.main_window.geometry("800x500")

######### frames
        self.frame_top = tkinter.Frame(self.main_window, borderwidth = 4, relief = 'raised', background = "white")
        self.frame_middle = tkinter.Frame(self.main_window, borderwidth = 4, relief = 'raised', background = "white")
        self.frame_bottom = tkinter.Frame(self.main_window, borderwidth = 4, relief = 'raised')

############## label
        self.label_title = tkinter.Label(self.frame_top, text = "This is the title for my frame")
        self.label_question = tkinter.Label(self.frame_bottom, text = "What is your favorite animal?")
        self.value = tkinter.StringVar()
        self.label_display = tkinter.Label(self.frame_bottom, textvariable = self.value)

################ entry
        self.entry_answer = tkinter.Entry(self.frame_bottom, text = 'Values', width = 10)


################### buttons
        self.button_click_me_top = tkinter.Button(self.frame_top, text = "Click me", command = self.hello)
        self.button_click_me_middle = tkinter.Button(self.frame_middle, text = "Click me", command = self.message_box)
        self.button_click_me_bottom = tkinter.Button(self.frame_bottom, text = "Click me", command = self.enter_display)



#################### add label to the frame using pack

        self.label_title.pack(pady = (10,10), padx = (30, 30), ipady = 15, ipadx = 10)
        self.button_click_me_top.pack(pady = (0, 10))

        self.button_click_me_middle.pack(pady = (10, 10), padx = (30, 30))
        # self.label_question.pack(side = 'left')
        # self.entry_answer.pack(side = 'left')
        # self.button_click_me_bottom.pack(side = 'left')
        # self.label_display.pack(side = 'left')
        self.label_question.grid(row = 0, column = 0)
        self.entry_answer.grid(row = 0, column = 1)
        self.button_click_me_bottom.grid(row = 1, column = 0)
        self.label_display.grid(row = 1, column = 1)

###################### add frames to the main_window using pack and grids
        # self.frame_top.pack(pady = (50, 50), padx = (30, 30))
        # self.frame_middle.pack(pady = (0, 50), padx = (30, 30))
        # self.frame_bottom.pack()
        self.frame_top.grid(row = 0, column = 0, ipadx = 10, ipady = 10, pady = (10, 5))
        self.frame_middle.grid(row = 1, column = 1, ipadx = 50, ipady = 10, pady = (10, 5))
        self.frame_bottom.grid(row = 2, column = 2, ipadx = 50, ipady = 10, pady = (10, 5))

        tkinter.mainloop()
    def hello(self):
        print("Hello world!!!")

    def message_box(self):
        tkinter.messagebox.showinfo("This is an Alert!", "You need to close this window!!!")

    def enter_display(self):
        message = self.entry_answer.get()
        self.value.set(message)