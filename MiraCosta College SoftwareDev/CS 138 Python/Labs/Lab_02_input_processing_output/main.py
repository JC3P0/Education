'''
DEVELOPER: Josh Clemens
LAST MODIFIED: June 19, 2022
'''
""" 
This program scales ingredients for a recipe.
TODO: Step 1 - Explain where you got the recipe from (Ex: aunt Jane, grandpa Mario, foodnetwork.com, etc.) and why you chose it. Also state what the original number of servings is.
"""
print(f'This "Everything Cookies" recipe is from the website www.allrecipes.com and the original number of servings or cookies is 36.\n')

#INPUT SECTION
#TODO: Step 2 - get user input for the number of servings they want to make.
servings = int(input("Enter the number of cookies you want to make.(Recommended 36) "))

#PROCESSING SECTION 
#TODO: Step 3 - calculate your scaling ratio
# original serving ingredient / recomended amount * user int(input)
flour = 3/36 * servings
brown_sugar = 1/36 * servings
white_sugar = 1/36 * servings
eggs = 1/36 * servings
butter = 1/36 * servings
chips = 2/36 * servings
rice_cereal = 1/36 * servings
salt = 1/36 * servings
vanilla = 2/36 * servings
baking_soda = 1/36 * servings
cream_tartar = 1/36 * servings
oats = 1/36 * servings
oil = 1/36 * servings

#OUTPUT SECTION
#TODO: Step 4 - output scaled ingredient list and recipe directions
print(f'\nHere are the scaled ingredients for "{servings}" Everything cookies!')
print(f'{flour:.2f} Cups of Flour\n{brown_sugar:.2f} Cups of Brown Sugar\n{white_sugar:.2f} Cups of White Sugar\n{eggs:.2f} Eggs\n{butter:.2f} Cups of Butter\n{chips:.2f} Cups of Chocolate Chips\n{rice_cereal:.2f} Cups of Crisp Rice Cereal\n{salt:.2f} teaspoons of Salt\n{vanilla:.2f} tablespoons of Vanilla Extract\n{baking_soda:.2f} teaspoons of Baking Soda\n{cream_tartar:.2f} teaspoons of Cream of Tartar\n{oats:.2f} Cups of quick cooking oats\n{oil:.2f} Cups of Vegetable oil\n')