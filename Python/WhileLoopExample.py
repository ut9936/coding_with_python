while True :
    print('Who are you?')
    name = input()
    if name != 'joe' :
        continue
    print('Hello joe, what is the password for your accout?')
    password = input()
    if password == 'SwordFish' :
        break
print('Access Granted')
