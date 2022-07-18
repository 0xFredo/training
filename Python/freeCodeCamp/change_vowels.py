def change_wovels(phrase):
    changed = ""

    for letter in phrase:
        if letter.lower() in "aeiou":
            if letter.isupper():
                changed = changed + "G"
            else:
                changed = changed + "g"
        else:
            changed = changed + letter
    
    return changed

print(change_wovels(input("Insert frase: ")))
