'''Functions used to calculate statistics on wikimorti dataset.

Dataset filled by wikipedia free-text scraping from 1992 to 2021
Some deaths weren't added to the dataset due to bad formatting
'''
import json
import matplotlib.pyplot as plt

def get_deaths_per_year(deads_dataset):
    '''Returns the number of deaths for each year
    
    :param deads_dataset: dictionary - dead persons to extract data
    :return: dictionary - key:value pair of years:deaths
    
    '''
    dt_deaths = {}
    
    for dead in deads_dataset["dead_people"]:
        year = dead["death_date"][-4:]
        if year in dt_deaths.keys():
            dt_deaths[year] += 1
        else:
            dt_deaths[year] = 1

    return dt_deaths


def plot_deaths_per_year(deads_dataset):
    '''Shows death per year graphically.

    :param deads_dataset: dictionary - dead persons to extract the deads.
    '''

    deaths_per_year = get_deaths_per_year(deads_dataset)
    
    years = list(deaths_per_year.keys())
    deaths_num = list(deaths_per_year.values())
    
    plt.plot(years, deaths_num)
    plt.suptitle("Deaths by year")
    plt.show()


def get_deads_by_age(deads_dataset, age):
    '''Returns list of deads filtered by age.

    :param deads_dataset: dictionary - dead persons to extract the deads.
    :param age: int - used to filter the list
    :return: list - dictionaries representing the deads
    '''
    
    deads = []
    for dead in deads_dataset["dead_people"]:
        if dead["age"] == age:
            deads.append(dead)
    
    return deads


def youngest_death(deads_dataset):
    '''Print the youngest death.

    :param deads_dataset: dictionary - dead persons to extract the youngest death.
    
    Assumes that the list has at least one element.
    First iterate to get the lower age, after extract all the people with that age.
    '''
    youngest_age = deads_dataset["dead_people"][0]["age"]

    for dead in deads_dataset["dead_people"]:
        if dead["age"] < youngest_age:
            youngest_age = dead["age"]
   
    print(get_deads_by_age(deads_dataset, youngest_age))


def oldest_death(deads_dataset):
    '''Print the oldest death.

    :param deads_dataset: dictionary - dead persons to extract the oldest death.
    
    Assumes that the list has at least one element.
    First iterate to get the lower age, after extract all the people with that age.
    '''
    oldest_age = deads_dataset["dead_people"][0]["age"]

    for dead in deads_dataset["dead_people"]:
        if dead["age"] > oldest_age:
            oldest_age = dead["age"]
   
    print(get_deads_by_age(deads_dataset, oldest_age))


def get_ages(deads_dataset):
    '''Return the ages of death.

    :param deads_dataset: dictionary - dead persons to extract the ages.
    :return: list - ages in deads_dataset.
    '''
    return [dead["age"] for dead in deads_dataset["dead_people"]]


def average_death_age(deads_dataset):

    print("The average death age is: {}".format(
        sum(get_ages(deads_dataset)) / count_deaths(deads_dataset)))
    

def get_names_occurences(deads_dataset):
    '''Return the names number of occurrences. 

    :param deads_dataset: dictionary - dead persons to extract the occurences.
    :return: dictionary - names:number of occurrences. 
    '''
    names = {}
    
    for dead in deads_dataset["dead_people"]:
        if dead["name"] in names.keys():
            names[dead["name"]] += 1
        else:
            names[dead["name"]] = 1
    return names 


def twenty_common_names(deads_dataset):
    '''Prints the twenty common names and their number of occurences.
    
    :param deads_dataset: dictionary - dead persons to analyze.
    
    Function that obtains the key:value pair of name and occurrences,
    parse the dictionary in a list of tuple with key value with in inverted position,
    because of the chance to sort the list by occurences of the names (first tuple element).
    Printed only the first 20 element of the list.
    '''
    names = get_names_occurences(deads_dataset) 

    reverted_tuple_list = [(value, key) for key, value in names.items()]
    reverted_tuple_list.sort(reverse = True)
    reverted_tuple_list = reverted_tuple_list[:20]
    
    print("First twenty occurences (other names with 5 occurrences omitted)")
    for tuple_elem in reverted_tuple_list:
        print("{} appeared {} times".format(tuple_elem[1], tuple_elem[0]))


def monthly_average_deaths(deads_dataset):
    '''Prints the monthly average deaths on the dataset years range.
    
    :param deads_dataset: dictionary - dead persons to analyze.
    '''
    num_months = len(range(1992, 2022)) * 12
    num_deaths = count_deaths(deads_dataset)
    
    print("The monthly average of deaths is {}".format(num_deaths / num_months))


def print_num_deaths(deads_dataset):
    '''Prints the number of dead in the dataset.
    
    :param deads_dataset: dictionary - dead persons to count.
    '''
    print("At least {} well-known people died from 1992 to 2021:"
            .format(count_deaths(deads_dataset)))


def count_deaths(deads_dataset):
    '''Returns the number of dead in the dataset.

    :param deads_dataset: dictionary - dead persons to count.
    :return: int - number of deaths.
    '''
    return len(deads_dataset["dead_people"])


def find_death_date(deads_dataset):
    '''Prints the death date of a person given by the user.
     
    :param deads_dataset: dictionary - dead persons to search in.

    The function iterates over all the dataset, all matches will be printed.
    '''
    person = input("Put the complete name of a dead person: ")
    
    for dead in deads_dataset["dead_people"]:
        if person.lower() in dead["name"].lower():
            print(dead["name"], dead["death_date"], dead["age"], dead["info"])


def pprint(json_dict):
    '''Pretty print dictionary in json-like.
    
    :param json_dict: dictionary - dead persons to be printed.
    '''
    print(json.dumps(json_dict, indent=3))
    

def load_json():
    '''Open and load the json dataset.
    
    :return: dictionary - parsed json dataset.
    '''
    with open("data/deadge.json", "r", encoding = "UTF-8") as json_file:
        return json.load(json_file)     


def main():
    '''Entrypoint.
    '''
    deads_dataset = load_json()
    #pprint(deads_dataset)
    #find_death_date(deads_dataset)
    #print_num_deaths(deads_dataset)
    #monthly_average_deaths(deads_dataset)
    #twenty_common_names(deads_dataset)
    #average_death_age(deads_dataset)
    #youngest_death(deads_dataset)
    #oldest_death(deads_dataset) #error in the dataset
    plot_deaths_per_year(deads_dataset)

if __name__ == "__main__":
    main()
else:
    print("Bad invocation.")
