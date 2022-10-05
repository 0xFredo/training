"""
"""

class Contact:
    name = ''
    surname = ''
    number = 0

    def __init__(self, name, surname, number):
        self.name = name
        self.surname = surname
        self.number = number

def read_file():
    contacts_file_list = []
    with open('data/contacts.txt', 'r', encoding='UTF-8') as txt_file:
        for line in txt_file:
            contacts_file_list.append(line.replace('\n', ''))
    
    return contacts_file_list

def build_contacts_list(contacts_file_list):
    contacts_list = []
    for contact in contacts_file_list:
        splitted_contact = contact.split(',')
        contacts_list.append(Contact(splitted_contact[0],
                                     splitted_contact[1],
                                     splitted_contact[2]))
    
    return contacts_list

def remove_duplicates(contacts_list):
    duplicate_contacts = []
    for index_compare, value in enumerate(contacts_list):
        for index in range(index_compare+1, len(contacts_list)):
            if value.number == contacts_list[index].number:
                duplicate_contacts.append(contacts_list[index])

    print(len(duplicate_contacts), "duplicate found, removing...")
    for duplicate in duplicate_contacts:
        contacts_list.remove(duplicate)

def print_address_book(contacts_list):
    print("Number of contacts:", len(contacts_list))
    print("Address book printing...")
    for contact in contacts_list:
        print("Name:", contact.name, "- Surname:", contact.surname, "- Number:", contact.number)

def main():
    contacts_file_list = read_file()
    contacts_list = build_contacts_list(contacts_file_list)
    remove_duplicates(contacts_list)
    print_address_book(contacts_list)

if __name__ == '__main__':
    main()
