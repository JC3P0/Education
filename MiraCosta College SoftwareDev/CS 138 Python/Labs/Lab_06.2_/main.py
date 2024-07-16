'''
DEVELOPER: Josh Clemens
'''
""" This program can be used to create an amortization schedule for a loan.
"""

##### FUNCTION DEFINITIONS #####

def loan_amount():
    principle = float(input("Please enter the initial loan amount: $"))
    while principle <= 0:
        principle = float(input("Invalid input. Please enter the initial loan amount: $"))
    return principle

def loan_interest():
    interest_rate = float(input("Please enter the annual interest rate in percentages: "))
    while interest_rate > 100:
        interest_rate = float(input("Invalid input. Please enter the annual interest rate in percentages: "))       
    while interest_rate <= 0:
        interest_rate = float(input("Invalid input. Please enter the annual interest rate in percentages: "))   
    return interest_rate

def loan_years():
    years = int(input("Please enter the number of years to pay off the loan within: "))
    while years <= 0:
        years = int(input("Invalid input. Please enter the number of years to pay off the loan within: "))
    return years

def create_schedule(principle, interest_rate, years):
    m_interest_rate = interest_rate / 1200
    terms = years * 12
    m_payment = principle * (m_interest_rate * (1+m_interest_rate)**terms) / ((1+m_interest_rate)** terms - 1)
    balance = principle
    print(f'{"Payment Number":^15}{"Payment":>12}  {"Interest ":>17} {"Principle ":>17}{"Balance ":>17} ')
    for month in range (1, terms +1):
        m_interest = balance * m_interest_rate
        m_principle = m_payment - m_interest
        balance = balance - m_principle
        print(f"{month:^15}(${m_payment:>10,.2f})     (${m_interest:>10,.2f})     (${m_principle:>10,.2f})     ${balance:>10,.2f}")

##### MAIN PROGRAM #####

print("Welcome to the Amortization Calculator! With its help we can calculate and display the complete Amortization Schedule for a loan.\n")

principle = loan_amount()
interest_rate = loan_interest()
years = loan_years()
create_schedule(principle, interest_rate, years)