import random

attempts = 5
random_num = random.randrange(0, 99, 2)
user_num = int(input("Guess the number from 0 to 99, you have " + str(attempts) + " attempts: "))

print(random_num)
while(random_num != user_num and attempts > 1):
    attempts -= 1
    user_num = int(input("Wrong number, try again (" + str(attempts) + " attempts): "))

if random_num != user_num:
    print("Loose, attempts finished")
else:
    print("Guessed!")
