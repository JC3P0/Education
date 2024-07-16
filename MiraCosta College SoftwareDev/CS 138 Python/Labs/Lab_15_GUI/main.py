from tkinter import *
import vaccine_record
from vaccine_record import VaccineRecord

#this method should be called when "Submit"   button is clicked
def process():
  # print("submit was clicked")
  person_record = VaccineRecord(f_name_entry.get(), l_name_entry.get(), dob_entry.get(), manufacture_1_entry.get(), batch_1_entry.get(), date_1_entry.get(), location_1_entry.get(), manufacture_2_entry.get(), batch_2_entry.get(), date_2_entry.get(), location_2_entry.get())
  person_record.printCard()

#this method should be called when checkbox is ticked/unticked. Have an IF for off, ELSE   for on
def checkbox_process():
  # print("checkbox interaction")
  # print(no_second_dose.get())
  if no_second_dose.get() == 1:
      manufacture_2_entry.delete(0,100)
      batch_2_entry.delete(0,100)
      date_2_entry.delete(0,100)
      location_2_entry.delete(0,100)
      
      manufacture_2.grid_remove()
      batch_2.grid_remove()
      date_2.grid_remove()
      location_2.grid_remove()
      
      manufacture_2_entry.grid_remove()
      batch_2_entry.grid_remove()
      date_2_entry.grid_remove()
      location_2_entry.grid_remove()
  else:
      manufacture_2.grid(row = 9, column = 0)
      batch_2.grid(row = 10, column = 0)
      date_2.grid(row = 11, column = 0)
      location_2.grid(row = 12, column = 0)
      manufacture_2_entry.grid(row = 9, column = 1)
      batch_2_entry.grid(row = 10, column = 1)
      date_2_entry.grid(row = 11, column = 1)
      location_2_entry.grid(row = 12, column = 1)

#begin code for GUI 

main_window = Tk()
main_window.title("Vaccine Entry")
main_window.geometry("600x600")

#labels

f_name = Label(main_window, text = "First Name")
l_name = Label(main_window, text = "Last Name")
dob = Label(main_window, text = "Date of Birth(mm/dd/yyyy)")
first_dose_1 = Label(main_window, text = "First Dose Information")
manufacture_1 = Label(main_window, text = "Manufacture")
batch_1 = Label(main_window, text = "Batch")
date_1 = Label(main_window, text = "Date(mm/dd/yyyy)")
location_1 = Label(main_window, text = "Location")
first_dose_2 = Label(main_window, text = "Second Dose Information")
manufacture_2 = Label(main_window, text = "Manufacture")
batch_2 = Label(main_window, text = "Batch")
date_2 = Label(main_window, text = "Date(mm/dd/yyyy)")
location_2 = Label(main_window, text = "Location")

#buttons

submit_button = Button(main_window, text = "Submit", command = process)
no_second_dose = IntVar()
check_box = Checkbutton(main_window, text = "No second dose", variable = no_second_dose, onvalue = 1, offvalue = 0, command = checkbox_process)

#entry
f_name_entry = Entry(main_window, bd = 5)
l_name_entry = Entry(main_window, bd = 5)
dob_entry = Entry(main_window, bd = 5)

manufacture_1_entry = Entry(main_window, bd = 5)
batch_1_entry = Entry(main_window, bd = 5)
date_1_entry = Entry(main_window, bd = 5)
location_1_entry = Entry(main_window, bd = 5)

manufacture_2_entry = Entry(main_window, bd = 5)
batch_2_entry = Entry(main_window, bd = 5)
date_2_entry = Entry(main_window, bd = 5)
location_2_entry = Entry(main_window, bd = 5)

#frames

f_name.grid(row = 0, column = 0)
l_name.grid(row = 1, column = 0)
dob.grid(row = 2, column = 0)
first_dose_1.grid(row = 3, column = 1)
manufacture_1.grid(row = 4, column = 0)
batch_1.grid(row = 5, column = 0)
date_1.grid(row = 6, column = 0)
location_1.grid(row = 7, column = 0)
first_dose_2.grid(row = 8, column = 1)
manufacture_2.grid(row = 9, column = 0)
batch_2.grid(row = 10, column = 0)
date_2.grid(row = 11, column = 0)
location_2.grid(row = 12, column = 0)

f_name_entry.grid(row = 0, column = 1)
l_name_entry.grid(row = 1, column = 1)
dob_entry.grid(row = 2, column = 1)

manufacture_1_entry.grid(row = 4, column = 1)
batch_1_entry.grid(row = 5, column = 1)
date_1_entry.grid(row = 6, column = 1)
location_1_entry.grid(row = 7, column = 1)

manufacture_2_entry.grid(row = 9, column = 1)
batch_2_entry.grid(row = 10, column = 1)
date_2_entry.grid(row = 11, column = 1)
location_2_entry.grid(row = 12, column = 1)

submit_button.grid(row = 9, column = 2)
check_box.grid(row = 8, column = 2)