'''Json read, manipulate, table print'''

import requests
from prettytable import PrettyTable

response_todos = requests.get("https://jsonplaceholder.typicode.com/todos")
response_users = requests.get("https://jsonplaceholder.typicode.com/users")
json_todos = response_todos.json()
json_users = response_users.json()

user_list = []

for user in json_users:
    table_user = { "id": user["id"], "name": user["username"], "todos": [] }

    for todo in json_todos:
        if todo["userId"] == table_user["id"]:
            table_todo = { "title": todo["title"], "completed": todo["completed"] }
            table_user["todos"].append(table_todo)

    user_list.append(table_user)

print(user_list)

for user in user_list:
    table = PrettyTable()
    table.field_names = [user["name"], "Status"]
    for todo in user["todos"]:
        if todo["completed"]:
            SYMBOL = "V"
        else:
            SYMBOL = "X"

        table.add_row([todo["title"], SYMBOL])
    print(table)
