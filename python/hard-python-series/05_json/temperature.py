'''
    Italian province actual temperatures
'''

import datetime

import json
import requests

provincia = input("Insert an italian provincia (extended name): ").capitalize()

with open("data/province.json", "r", encoding="utf-8") as fileHandler:
    data = json.load(fileHandler)

try:
    prov_coords = data[provincia]

except KeyError as err:
    print("Provincia non trovata")

response = requests.get("https://api.open-meteo.com/v1/forecast?latitude=" +
                        prov_coords["lat"] + "&longitude=" + prov_coords["lon"] +
                        "&hourly=temperature_2m&hourly=apparent_temperature")

now = datetime.datetime.now().strftime("%Y-%m-%dT%H:00")

try:
    response_json = response.json()
    meteo_index = response_json["hourly"]["time"].index(now)

    temp = response_json["hourly"]["temperature_2m"][meteo_index]
    app_temp = response_json["hourly"]["apparent_temperature"][meteo_index]

    print("Temperature", temp)
    print("Apparent temperature", app_temp)

except ValueError as err:
    print("No data for the actual meteo", err)

#temp starts from 00:00 of today to six day ahead. I could have only take the actula hour and use it as the index in the array. 
