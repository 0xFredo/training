

def insert_word():
    return input("Insert a word to build phrases, (only .,!? admitted as punctuation): ")

def create_phrase(last_word):

    global phrase
    
    phrase = phrase + last_word
    phrase = phrase.capitalize()
    phrase_list.append(phrase)
    phrase = ""
 
def add_word_to_phrase(word):
    global phrase
    phrase = phrase + word + " "

def remove_last_space():
    global phrase
    phrase = phrase.rstrip()

def fill_dic_char_counter():
    global phrase_list
    global dic_char_counter
    for phrase in phrase_list:
        for char in phrase:
            
            if char == ' ':
                continue

            char = char.lower()
            if char in dic_char_counter.keys():
                dic_char_counter[char] += 1
            else:
                dic_char_counter[char] = 1

def get_most_frequent_char_dic():
    global dic_char_counter
    dic_most = dic_char_counter.copy()

    for key, value in dic_char_counter.items():
        if value < max(dic_char_counter.values()):
            del dic_most[key]
    
    return dic_most 

def get_less_frequent_char_dic():
    global dic_char_counter
    dic_less = dic_char_counter.copy()

    for key, value in dic_char_counter.items():
        if value > min(dic_char_counter.values()):
            del dic_less[key]
    
    return dic_less

word_list = []
word = insert_word()

while word != "stop":
    word_list.append(word)
    word = insert_word()

phrase = ""
phrase_list = []
index = 0
only_word_counter = 0
punctuation_counter = 0
dic_char_counter = {}

print("Word list:", word_list)

for word in word_list:
    if word in [".", "!", "?"]:
        remove_last_space()
        create_phrase(word)
        punctuation_counter += 1
    elif word == ",":
        remove_last_space()
        add_word_to_phrase(word)
        punctuation_counter += 1
    elif index == len(word_list) - 1:
        create_phrase(word)
        only_word_counter += 1
    else:
        add_word_to_phrase(word)
        only_word_counter += 1

    index += 1

fill_dic_char_counter()

print("Phrase list:", phrase_list)
print("Word number:", only_word_counter)
print("Punctuation number:", punctuation_counter)
print("Phrase number:", len(phrase_list))
print("Most frequent chars:", get_most_frequent_char_dic())
print("Less frequent chars:", get_less_frequent_char_dic())

