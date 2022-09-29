'''
    Quiz Game
    - iterate the program, at the end ask the user if it wants to continue pressing Y
    - random extraction of two artists from data/authors.json
    - get the id of the data extracted and call the Deezer APIs to get the number of album
    - ask the user if the first or the second artists published more album
        - generate exception if the input isn't 1 or 2
'''
import json
import random
import requests

def quiz(json_data):
    '''
        Quiz function
        param json_data: dict - key:value = name:id 
    '''

    print("-----")

    random_artists = random.sample(list(json_data.items()), 2)

    first_artist_data = requests.get(
            "https://api.deezer.com/artist/" + str(random_artists[0][1])).json()
    second_artist_data = requests.get(
            "https://api.deezer.com/artist/" + str(random_artists[1][1])).json()

    user_answer = input("Who has more fans, "
            + random_artists[0][0] + " (1) or " + random_artists[1][0] + " (2) ? ")

    if user_answer not in ["1", "2"]:
        raise Exception("Answer must be 1 or 2")

    if user_answer == "1":
        if first_artist_data["nb_fan"] > second_artist_data["nb_fan"]:
            print("Correct!")
        else:
            print("Wrong!")

    if user_answer == "2":
        if second_artist_data["nb_fan"] > first_artist_data["nb_fan"]:
            print("Correct!")
        else:
            print("Wrong!")

start = "Y"
while start == "Y":
    with open("data/artists.json", "r", encoding = "UTF-8") as json_file:
        json_data = json.load(json_file)
    
    quiz(json_data)

    start = input("Press Y if you want to continue? ")
