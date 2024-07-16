# The VaccineRecord encapsulates the COVID-19 vaccine data for a person.
'''
VaccineRecord
------------------------------
- first_name : string
- last_name : string
- dob : string
- d1_manufacturer : string
- d1_batch : string
- d1_date : string
- d1_location : string
- d2_manufacturer : string
- d2_batch : string
- d2_date : string
- d2_location : string
------------------------------

'''
class VaccineRecord:

  # Full constructor to initialize new VaccineRecord object
  def __init__(self,first,last,dob,d1_manufacturer, d1_batch, d1_date, d1_location, d2_manufacturer, d2_batch, d2_date, d2_location):
    self.__first_name = first
    self.__last_name = last
    self.__dob = dob
    self.__d1_manufacturer = d1_manufacturer
    self.__d1_batch = d1_batch
    self.__d1_date = d1_date
    self.__d1_location = d1_location
    self.__d2_manufacturer = d2_manufacturer
    self.__d2_batch = d2_batch
    self.__d2_date = d2_date
    self.__d2_location = d2_location
    
    #str method that returns a string containing all data about object
  def __str__(self):
    all = f'First Name: {self.__first_name}\n'
    all += f'Last Name: {self.__last_name}\n'
    all += f'DOB: {self.__dob}\n'
    all += f'Dose 1 Manufacturer: {self.__d1_manufacturer}\n'
    all += f'Dose 1 Batch Number: {self.__d1_batch}\n'
    all += f'Dose 1 Date: {self.__d1_date}\n'
    all += f'Dose 1 Location: {self.__d1_location}\n'
    all += f'Dose 2 Manufacturer: {self.__d2_manufacturer}\n'
    all += f'Dose 2 Batch Number: {self.__d2_batch}\n'
    all += f'Dose 2 Date: {self.__d2_date}\n'
    all += f'Dose 2 Location: {self.__d2_location}\n'
    return all
    
# This method should print out the card info in a nice format
    # similar to how a vaccine card would look in real life
  def printCard(self):
    # print("formatted card output here")
    str = f''' 
    {self.__last_name:<30}{self.__first_name}
    {'-'*40}
    {"Last Name":<30}{"First Name"}
    {'-'*40}
    {self.__dob}
    {'-'*40}
    {"Date of Birth"}

    {'-'*70}
    {"Vaccine":<10}|{"Manufacture/Lot Number":<25}|{"Date":<10}
    {'-'*70}
    {"1st Dose":<10}|{self.__d1_manufacturer:<25}|{self.__d1_date:<10}|Location
    {"COVID 19":<10}|{self.__d1_batch:<25}|{"mm dd yyyy":<10}|{self.__d1_location}
    {'-'*70}
    {"2nd Dose":<10}|{self.__d2_manufacturer:<25}|{self.__d2_date:<10}|Location
    {"COVID 19":<10}|{self.__d2_batch:<25}|{"mm dd yyyy":<10}|{self.__d2_location}
    '''
    print(str)