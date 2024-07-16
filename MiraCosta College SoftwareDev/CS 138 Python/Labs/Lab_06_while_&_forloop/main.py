'''
DEVELOPER: Josh Clemens
'''
""" This program can be used to create an amortization schedule for a loan.
"""

##### FUNCTION DEFINITIONS #####

def create_schedule(principle, interest_rate, years):
    m_interest_rate = interest_rate / 1200
    terms = years * 12
    monthly_payment = principle * (m_interest_rate * (1+m_interest_rate)**terms) / ((1+m_interest_rate)** terms - 1)
    balance = principle
    print(f'{"Payment Number":^15}{"Payment":>12}  {"Interest ":>17} {"Principle ":>17}{"Balance ":>17} ')
    for month in range (1, terms +1):
        m_interest = balance * m_interest_rate
        m_principle = monthly_payment - m_interest
        balance = balance - m_principle
        print(f"{month:^15}(${monthly_payment:>10,.2f})     (${m_interest:>10,.2f})     (${m_principle:>10,.2f})     ${balance:>10,.2f}")

##### MAIN PROGRAM #####

print("Welcome to the Amortization Calculator! With its help we can calculate and display the complete Amortization Schedule for a loan.\n")
    
principle = 20000
interest_rate = 3.5
years = 2
create_schedule(principle, interest_rate, years)