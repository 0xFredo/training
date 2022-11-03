print("LOGIN\n")

is_user_authorized = False

while not is_user_authorized:

    name = input("Insert name: ")
    surname = input("Insert surname: ")
    age = int(input("Insert age: "))

    print("RESUME\n")

    name = name.capitalize()
    surname = surname.capitalize()
    print("Name: " + name)
    print("Surname: " + surname)
    print("Age:", age)

    if len(name) > 1 and len(surname) > 1 and age >= 18:
        print("User authorized\n")
        is_user_authorized = True
    else:
        print("Access denied, try with different inputs\n")
