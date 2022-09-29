'''
    Wikimorti json dataset builder
    Better approach could be to make a working solution for the most cases.
    Only after find the accurancy
    So before document and write code. But think about the corner cases only after
    Methods are not well designed and decoupled
'''
import json
import wikipediaapi


def write_json_db(dead_dict):
    '''Writes on json file

    :param dead_dict: dictionary - json structure that contains an array dictionary (dead people)

    Function that takes a dictionary and dump the content to a file in JSON format.
    The file is created or the content will be overwritten.
    '''

    print("Dumping...")

    with open("data/deadge.json", "w", encoding = "UTF-8") as json_file:
        json.dump(dead_dict, json_file)

    print("Dumped.")
    print(dead_counter, "Dead analyzed")
    print(dead_saved, "Dead saved")

def get_dead_people_array(text):
    '''Create a list of people

    :param text: string - contains the text of the wikipedia section

    Function that split the string by new line and clean the list by empty elements or values with
    '=' assuming that are not part of the name
    '''

    people_array = text.split("\n")
    clean_array = [people for people in people_array if len(people) > 0 and not people.startswith("=")]
    return clean_array


def fill_dead_dict(section, dead_dict, month_year):
    '''Fill the dead_people array

    :param section: object - part of the wikipedia page to be analyzed
    :param dead_dict: dictionary - empty to be filled here
    :param month_year: string - useful to build the death_date field
    :return: dictionary - filled data structure to be dumped as json
    '''
    people_array = get_dead_people_array(section.text)
    
    #ugly
    global dead_counter
    global dead_saved

    for dead in people_array:
        dead_counter += 1
        #Following iteration assumes that what is before a digit is part of the name.
        to_dead_dict = {}
        attributes = dead.split(", ")
        
        #Assumes that the second element is age, that can have a hyphen,
        #otherwise it's other piece of name and the age is the third element
        try:    
            dead_name = attributes[0]
            info = []
            
            if attributes[1].split("-")[0].strip().isdigit():
                age = int(attributes[1].split("-")[0].strip())
                if len(attributes) > 2:
                    info = attributes[2:]
            else: 
                dead_name += ", " + attributes[1]
                age = int(attributes[2].split("-")[0].strip())
                if len(attributes) > 3:
                    info = attributes[3:]
                 
            to_dead_dict["name"] = dead_name
            to_dead_dict["age"] = age
            to_dead_dict["death_date"] = section.title + "-" + month_year
            to_dead_dict["info"] = info

            dead_dict["dead_people"].append(to_dead_dict)
            dead_saved += 1
        except (ValueError, IndexError):
            print("Dead too bad formatted, not saved on DB:", dead)


def navigate_sections(sections, month_year, dead_dict, level=0):
    '''
    Better to write this before implementation
    '''
    for section in sections:
        if level == 1:
            fill_dead_dict(section, dead_dict, month_year)

        navigate_sections(section.sections, month_year, dead_dict, level + 1)


def get_month_year(title_link):
    '''
    Write this before implementation
    '''
    splitted_title = title_link.split(" ")
    month_year = splitted_title[
            len(splitted_title) - 2] + "-" + splitted_title[len(splitted_title) - 1]

    return month_year.lower()


def get_death_page_titles(wiki):
    '''
    Write this before implementation
    '''
    monthly_death_links = []
    general_deaths_page = wiki.page("Lists of deaths by year")
    for title_link in general_deaths_page.links.keys():
        for year in range(1992, 2022):
            if str(year) in title_link and len(title_link) > 4:
                monthly_death_links.append(title_link)
    return monthly_death_links


def analyze_wikipedia(wiki):
    '''
    Write this before implementation
    '''
    dead_dict = {"dead_people": []}
    monthly_death_links = get_death_page_titles(wiki)

    for title_link in monthly_death_links:
        monthly_deaths_page = wiki.page(title_link)
        #Used to build date of death.
        month_year = get_month_year(title_link)
        navigate_sections(monthly_deaths_page.sections, month_year, dead_dict)

    return dead_dict


def init_wiki():
    '''
    Write this before implementation
    '''
    wiki = wikipediaapi.Wikipedia(
        language = "en",
        extract_format = wikipediaapi.ExtractFormat.WIKI
    )
    return wiki

#ugly
dead_counter = 0
dead_saved = 0

def main():
    '''
    Main function (useful to create a local scope)
    '''
    wiki = init_wiki()
    dead_dict = analyze_wikipedia(wiki)
    write_json_db(dead_dict)


if __name__ == "__main__":
    print("START")
    main()
else:
    print("Bad invocation!")
