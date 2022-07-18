def sum(num1, num2):
    return num1 + num2

def diff(num1, num2):
    return num1 - num2

def mul(num1, num2):
    return num1 * num2

def div(num1, num2):
    return num1 / num2

def mod(num1, num2):
    return num1 % num2

num1 = float(input("Insert the first number: "))
operator = input("Insert the operator: ")
num2 = float(input("Insert the second number: "))

if operator == "+":
    print(sum(num1, num2))
elif operator == "-":
    print(diff(num1, num2))
elif operator == "*":
    print(mul(num1, num2))
elif operator == "/":
    print(div(num1, num2))
elif operator == "%":
    print(mod(num1, num2))
else:
    print("Wrong operator")
