def rev(list_a):
    i_left = 0
    i_right = len(list_a) - 1

    while i_left < i_right:
        left_to_right = list_a[i_left]
        list_a[i_left] = list_a[i_right]
        list_a[i_right] = left_to_right
    
        i_left += 1
        i_right -= 1

    return list_a

def is_positive(num):
    if num < 0:
        return False
    else:
        return True

def remove_duplicates(list_a):
    new_list = []
    for value in list_a:
        if value not in new_list:
            new_list.append(value)

    return new_list

def is_palindrome(string_a):
    i_left = 0
    i_right = len(string_a) - 1

    while i_left < i_right:
        if string_a[i_left] != string_a[i_right]:
            return False

        i_left += 1
        i_right -= 1
    
    return True

def recursive_factorial(num):
    if num == 2:
        return 2
    
    return num * recursive_factorial(num - 1)

def main():
    
    print("TEST rev(list)...")
    list_a = [0, 1, 2, 3, 4]
    list_b = rev(list_a)
    if list_b == [4, 3, 2, 1, 0]:
        print("OK")
    else:
        print("NOT OK")

    print("TEST is_positive(num)")
    num = -3
    if not is_positive(-3):
        print("OK")
    else:
        print("NOT OK")
    
    print("TEST remove_duplicates(list)")
    list_a = [0, 1, 2, 2, 3, 4, 4]
    list_b = remove_duplicates(list_a)
    if list_b == [0, 1, 2, 3, 4]:
        print("OK")
    else:
        print("NOT OK")

    print("TEST is_palindrome(string)")
    pal_string = "radar"
    if is_palindrome(pal_string):
        print("OK")
    else:
        print("NOT OK")

    print("TEST recursive_factorial(num)")
    num = 4
    if recursive_factorial(num) == 24:
        print("OK")
    else:
        print("NOT OK")

        

if __name__ == "__main__":
    main()
