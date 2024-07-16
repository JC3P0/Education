# The VaccineRecord encapsulates the COVID-19 vaccine data (doses 1 and 2) for a person.
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
    def __init__(self, first, last, dob, d1_manufacture, d1_batch, d1_date, d1_location, d2_manufacture, d2_batch, d2_date, d2_location):
        self.__first_name = first
        self.__last_name = last
        self.__dob = dob
        self.__d1_manufacture = d1_manufacture
        self.__d1_batch = d1_batch
        self.__d1_date = d1_date
        self.__d1_location = d1_location
        self.__d2_manufacture = d2_manufacture
        self.__d2_batch = d2_batch
        self.__d2_date = d2_date
        self.__d2_location = d2_location

    def get_first_name(self):
        return self.__first_name
    def get_last_name(self):
        return self.__last_name
    def get_dob(self):
        return self.__dob
    def get_d1_manufacture(self):
        return self.__d1_manufacture
    def get_d1_batch(self):
        return self.__d1_batch
    def get_d1_date(self):
        return self.__d1_date
    def get_d1_location(self):
        return self.__d1_location
    def get_d2_manufacture(self):
        return self.__d2_manufacture
    def get_d2_batch(self):
        return self.__d2_batch
    def get_d2_date(self):
        return self.__d2_date
    def get_d2_location(self):
        return self.__d2_location

    def set_first_name(self, first):
        self.__first_name = first
    def set_last_name(self, last):
        self.__last_name = last
    def set_dob(self, dob):
        self.__dob = dob
    def set_d1_manufacture(self, d1_manufacture):
        self.__d1_manufacture = d1_manufacture
    def set_d1_batch(self, d1_batch):
        self.__d1_batch = d1_batch
    def set_d1_date(self, d1_date):
        self.__d1_date = d1_date
    def set_d1_location(self, d1_location):
        self.__d1_location = d1_location
    def set_d2_manufacture(self, d2_manufacture):
        self.__d2_manufacture = d2_manufacture
    def set_d2_batch(self, d2_batch):
        self.__d2_batch = d2_batch
    def set_d2_date(self, d2_date):
        self.__d2_date = d2_date
    def set_d2_location(self, d2_location):
        self.__d2_location = d2_location

    def __str__(self):
        return f'{self.__first_name} {self.__last_name} {self.__dob} {self.__d1_manufacture} {self.__d1_batch} {self.__d1_date} {self.__d1_location} {self.__d2_manufacture} {self.__d2_batch} {self.__d2_date} {self.__d2_location}'