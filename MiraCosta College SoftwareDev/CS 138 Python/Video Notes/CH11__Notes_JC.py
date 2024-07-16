from automobile import Automobile
from car import Car

#####################################
def main():
    used_car_1 = Automobile('Audi', 2007, 125000, 12500)
    used_car_2 = Automobile('BMW', 2020, 100000, 45000)
    print(used_car_1)
    print(used_car_2)
    # list_1.append(element) list_1 is an object of the type Class List
    print(used_car_1.get_make())
    print(used_car_2.get_make())
    used_car_1.set_price(10000)
    print(used_car_1)
    print(used_car_2)

    car_1 = Car('Mercedes', 2001, 50000, 20000, 4)
    print(car_1)
    used_car_1.car_noise()
    car_1.car_noise()

    print(isinstance(used_car_1, Automobile))
    print(isinstance(used_car_1, Car))
    print(isinstance(car_1, Automobile))
    print(isinstance(car_1, Car))

if __name__ == "__main__":
    main()
	
#################################################
	
## this is super class = base class = parent class, (general for of a class)
class Automobile:
    def __init__(self, make, model, mileage, price):
        self.__make = make
        self.__model = model
        self.__mileage = mileage
        self.__price = price

    def get_make(self):
        return self.__make
    def get_model(self):
        return self.__model
    def get_mileage(self):
        return self.__mileage
    def get_price(self):
        return self.__price

    def set_make(self, make):
        self.__make = make
    def set_model(self, model):
        self.__model = model
    def set_mileage(self, mileage):
        self.__mileage = mileage
    def set_price(self, price):
        self.__price = price

    def __str__(self):
        return f'{self.__make} {self.__model} {self.__mileage} {self.__price}'

    def car_noise(self):
        print("Vroooom. . . vroom")
		
################################################


from automobile import Automobile

###sub class
#Car is sub class of Automobile
class Car(Automobile):
    def __init__ (self, make, model, mileage, price, doors):
        Automobile.__init__(self, make, model, mileage, price)
        self.__doors = doors

    def get_doors(self):
        return self.__doors

    def set_doors(self, doors):
        self.doors = doors

    def __str__(self):
        return f'{Automobile.__str__(self)} {self.__doors}'
    def car_noise(self):
        print("Squeekkyy. . . squeeek")