import json
from datetime import datetime

def read_json():
    with open("data/01_data.json", "r", encoding="us-ascii") as file_handler:
        data = json.load(file_handler)
    return data

def print_mails(data):
    print("Mail list:")
    for element in data:
        print(element["email"])
        if element["email"] == "hollandoliver@electonic.com":
            friends = len(element["friends"])

    print("N° of friends for hollandoliver@electonic.com:", friends)


def friends_longest_name(data):
    dic_friends_names = {}
    for element in data:
        for friend in element["friends"]:
            dic_friends_names[friend["name"]] = len(friend["name"])

    print("Friend's longest name:", [key for key, value in dic_friends_names.items() if value == max(dic_friends_names.values())])


def first_last_registered_user(data):
    registration_dates = []
    date_format = "%Y-%m-%dT%H:%M:%S %z"
    for element in data:
        reg_date = datetime.strptime(element["registered"], date_format)
        registration_dates.append(reg_date)
    
    str_min_date = min(registration_dates).strftime(date_format)
    str_min_date = "{0}:{1}".format(str_min_date[:-2], str_min_date[-2:])
    str_max_date = max(registration_dates).strftime(date_format)
    str_max_date = "{0}:{1}".format(str_max_date[:-2], str_max_date[-2:])
    
    print("First registered account:", [element["_id"] for element in data if element["registered"] == str_min_date])
    print("Last registered account:", [element["_id"] for element in data if element["registered"] == str_max_date])


def active_users(data):
    active_list = []
    for element in data:
        if element["isActive"]:
            active_list.append(element["_id"])
    
    print("Active users:", active_list)

def richest_users(data):
    dic_balances = {} 
    for element in data:
        dic_balances[element["_id"]] = float(element["balance"].replace("$", "").replace(",", ""))
   
    richest_keys = [key for key,value in dic_balances.items() if value == max(dic_balances.values())]
    dic_richest = {}
    for element in data:
        if element["_id"] in richest_keys:
            dic_richest[element["_id"]] = element["balance"]
    
    print("Richest:", dic_richest)

def main():
    data = read_json()
    print_mails(data)
    friends_longest_name(data)
    first_last_registered_user(data)
    active_users(data)
    richest_users(data)

if __name__ == "__main__":
    main()
else:
    print("Not Main")
