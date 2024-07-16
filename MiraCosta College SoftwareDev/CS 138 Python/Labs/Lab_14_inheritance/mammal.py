# create your Mammal class
class Mammal:

  # __init__ method accepts the arguments for the kindom, phylum,and class_type. It initiliazes the data attributes with these values
    def __init__(self):
        self.__domain = "Eukaryota"
        self.__kindom = "Animalia"
        self.__phylum = "Chordata"
        self.__class_type = "Mammalia"

  # methods for the mutators/setters for the class's data attributes

    def set_domain(self, domain):
        self.__domain = domain
    def set_kindom(self, kindom):
        self.__kindom = kindom
    def set_phylum(self, phylum):
        self.__phylum = phylum
    def set_class_type(self, class_type):
        self.__class_type = class_type

  # methods for the accessors/getters for the class's data attributes

    def get_domain(self):
        return self.__domain
    def get_kindom(self):
        return self.__kindom
    def get_phylum(self):
        return self.__phylum
    def get_class_type(self):
        return self.__class_type

  # method for class string

    def __str__(self):
        return f'{self.__domain} {self.__kindom} {self.__phylum} {self.__class_type}'