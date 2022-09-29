'''Exception exercise'''

num = input("Insert a number greather than 10: ")
try:
    num = int(num)
    if num <= 10:
        raise ValueError("Number too small")
except ValueError as error:
    print(error)
