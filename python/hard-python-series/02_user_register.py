def choose_exercise():
    print("1 - Reverse List")
    print("2 - Merge List")
    print("3 - User Register")

    exercise = int(input("Insert the exercise number: "))
    print("")

    if exercise == 1:
        reverse_list()
    elif exercise == 2:
        merge_list()
    elif exercise == 3:
        user_register()
    else:
        print("Wrong exercise")

def merge_list():
    print("MERGE LIST\n")

    print("Fill first list")
    list_a = []
    
    for i in range(5):
        list_a.append(input("Insert the " + str(i + 1) + "/5 value: "))

    print("Fill second list")
    list_b = []
    for i in range(5):
        list_b.append(input("Insert the " + str(i + 1) + "/5 value: "))

    print("list_a", list_a)
    print("list_b", list_b)

    list_c = [None] * (len(list_a) * 2)

    for i in range(len(list_a)):
        list_c[i] = list_a[i]
        list_c[i + len(list_a)] = list_b[i]

    print("list_c", list_c, "\n")
    
    print("-------------")

def reverse_list():
    print("REVERSE LIST\n")

    list_a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    print("list_a", list_a)

    index = -1
    while index + len(list_a) != 0:
        print(list_a[index])
        index -= 1

def user_register():
    print("USER REGISTER\n")
    
    user_num = int(input("Insert tue number of user to register: "))
    
    user_list = []
    
    for i in range(user_num):
        username = input("Insert the " + str(i + 1) + "/" + str(user_num) + " user username: ")
        for user in user_list:
            if user["username"] == username:
                raise Exception("Username already inserted, program destroyed")

        age = int(input("Insert the " + str(i + 1) + "/" + str(user_num) + " user age: "))
        gender = input("Insert the " + str(i + 1) + "/" + str(user_num) + " user gender (M/F): ")
        games = input("Insert the {}/{} user list of games, divided by ',': ".format(i + 1, user_num)).split(",")
        games = [game.strip() for game in games]

        user_dic = {"username" : username, "age": age, "gender": gender, "games": games}
        user_list.append(user_dic)

    print("")
    print("--Statistics--")
    
    male_number = 0
    max_age = user_list[0]["age"]
    min_age = user_list[0]["age"]
    age_sum = 0
    dic_games_counter = {}

    for user in user_list:
        if user["gender"] == "M":
            male_number += 1
        if user["age"] > max_age:
            max_age = user["age"]
        if user["age"] < min_age:
            min_age = user["age"]
        
        age_sum += user["age"]

        for game in user["games"]:
            if game in dic_games_counter.keys():
                dic_games_counter[game] += 1
            else:
                dic_games_counter[game] = 1


    male_percent = (male_number * 100) / len(user_list)
    fem_percent = 100 - male_percent
    avarage_age = age_sum / len(user_list)

    favorite_games = dic_games_counter.copy() 
    for key, value in dic_games_counter.items():
        if value < max(dic_games_counter.values()):
            del favorite_games[key]

    print("Males:", str(male_percent) + "%")
    print("Females:", str(fem_percent) + "%")
    print("Max age:", max_age)
    print("Min age:", min_age)
    print("Avarage age:", avarage_age)
    print("Favorite games are:", favorite_games)

choose_exercise()
