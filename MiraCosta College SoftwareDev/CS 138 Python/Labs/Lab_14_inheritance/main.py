import mammal
import polarbear
import snowleopard
# create your main definition
def main():
  # create an instance Mammal object
  mammal_1 = mammal.Mammal()
  mammal_2 = mammal.Mammal()  

  mammal_1.set_kindom("Animal")
  print(mammal_1)
  print(mammal_2)
    
  polarbear_1 = polarbear.PolarBear("PolarBear")
  print(polarbear_1)
    
  # create an instance SnowLeopard object
  #  print SnowLeopard's taxonomy
  snowleopard_1 = snowleopard.SnowLeopard("SnowLeopard")
  print(snowleopard_1)
    
  # leave this part as it is
  print("Climate change extreme weather events not only affect us economically, air quality health, and the destruction of cities by tornados, wildfires, hurricanes; we never think about how is affecting other species we share this world with.\n")
  print("Nikhil Advani conducted animal species assessments affected by Climate Change and determined their vulnerability, resilience, and status.\n")

  # create your menu to choose between Polar Bear, Snow Leopard and Exit follow by a submenu to choose between Vulnerability, Resilience, Status, and Exit

  while True:
    choose = input("\na) Polar Bear\nb) Snow Leopard\nc) Exit\nChoose animal under danger: ")
    if choose == "a":
        while True:
            choose = input("\na) Vulnerabiliy\nb) Resilience\nc) Status\nd) Exit\nChoose animal's: ")
            if choose == "a":
                print(polarbear_1.get_vulnerability())
            elif choose == "b":
                print(polarbear_1.get_resilience())
            elif choose == "c":
                print(polarbear_1.get_status())
            elif choose == 'd':
                break

    elif choose == "b":
        while True:
            choose = input("\na) Vulnerabiliy\nb) Resilience\nc) Status\nd) Exit\nChoose animal's: ")
            if choose == "a":
                print(snowleopard_1.get_vulnerability())
            elif choose == "b":
                print(snowleopard_1.get_resilience())
            elif choose == "c":
                print(snowleopard_1.get_status())
            elif choose == 'd':
                break
    else:
        print("Goodbye!")
        break
    
if __name__ == '__main__':
  main()