
# primitive data types: int, float, double, boolean, character
# built-in data types: string, list, tuples, dictionaries, sets
# classes will allow you to make tou own data types
# for example i want to make a data type car, bankAccount, Coin

from bankAccount import *
from coin import *
from car import *

def main():
    # my_car_object = Car() #creates an instance of object
    my_car_object = Car("Ben", 2, 4, "4MYEGO", "123456789ABCDEF", "Black", 140.0)  #creates an instance of object
    print(my_car_object) #this uses the __str__ method to print the object
    my_car_object.drive()
    my_car_object.breaks()
    print(my_car_object.__str__())
    print(my_car_object.get_license_plate())
    my_car_object.set_name("Ben")
    print(my_car_object)
    my_car_object.set_doors(2)
    print(my_car_object)
    coin = Coin()
    print(f'This side is up: {coin.get_sideup()}')
    print('I am going to toss the coin ten times:')
    for count in range (10):
        coin.toss()
        print(coin.get_sideup())

    start_balance = float(input('Enter you starting balance: '))
    savings_account = BankAccount(start_balance)
    pay = float(input('How much were you paid this week? '))
    savings_account.deposit(pay)
    print(savings_account)
    cash = float(input('How much would you like to withdraw: '))
    print(f'I will withdraw ${cash} fram you account.')
    savings_account.withdraw(cash)
    print(savings_account)

if __name__ == "__main__":
  main()
  
  ####################################################################
  
  
  class BankAccount:
    def __init__(self, balance):
        self.__balance = balance

    def deposit(self, amount):
        self.__balance = self.__balance + amount
    def withdraw(self, amount):
        if self.__balance >= amount:
            self.__balance = self.__balance - amount
        else:
            print("Error: Insufficient funds")
    def get_balance(self):
        return self.__balance

    def set_balance(self, amount):
        self.__balance = amount
    def __str__(self):
        return f'The balance is ${self.__balance}'
		
######################################################################

class Car:
    # to define the initialization of the object
    # def __init__ (self):
    #     # attributes of the car: describes the class
    #     self.name = ""
    #     self.door = 4
    #     self.wheels = 4
    #     self.licence_plate = "123ABCD"
    #     self.vin_number = "123456789ABCDEFG"
    #     self.color = "black"
    #     self.max_speed = 15.0

    # def __init__ (self):
    #     # attributes of the car: describes the class
    #     self.name = ""
    #     self.door = 4
    #     self.wheels = 4
    #     self.licence_plate = "123ABCD"
    #     self.vin_number = "123456789ABCDEFG"
    #     self.color = "black"
    #     self.max_speed = 15.0

    def __init__ (self, name, doors, wheels, license_plate, vin_number, color, max_speed):
        # attributes of the car: describes the class
        self.__name = name
        self.__doors = doors
        self.__wheels = wheels
        self.__license_plate = license_plate
        self.__vin_number = vin_number
        self.__color = color
        self.__max_speed = max_speed

    # defining methods, which are the actions of the class
    # creating getters and setters
    def get_name(self):
        return self.__name
    def get_doors(self):
        return self.__doors
    def get_license_plate(self):
        return self.__license_plate
    def get_vin_number(self):
        return self.__vin_number
    def get_color(self):
        return self.__color
    def get_max_speed(self):
        return self.__max_speed

    def set_name(self, name):
        self.name = name
    def set_doors(self, doors):
        self.doors = doors
    def set_wheels(self, wheels):
        self.wheels = wheels
    def set_license_plate(self, license_plate):
        self.license_plate = license_plate
    def set_vin_number(self, vin_number):
        self.vin_number = vin_number
    def set_color(self, color):
        self.color = color
    def set_max_speed(self, max_speed):
        self.max_speed = max_speed

    def drive(self):
        print("Car is moving")
    def breaks(self):
        print("Car stops.")

    def __str__(self):
        return f'The car name is {self.__name} with {self.__doors} doors, {self.__wheels} wheels, license plate {self.__license_plate}, {self.__vin_number} vin number, color {self.__color}, and maximum speed {self.__max_speed}.'
		
###########################################################################

import random


class Coin:
    def __init__(self):
        self.__sideup = "Heads"

    def toss(self):
        if random.randint(0,1) == 0:
            self.__sideup = "Heads"
        else:
            self.__sideup = "Tails"

    def get_sideup(self):
        return self.__sideup

    def set_sideup(self, sideup):
        self.__sideup = sideup

    def __str__(self):
        return self.__sideup