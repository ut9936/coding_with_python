myPets = ['zophie','Pooka','Fat-Tail']
print('Enter a pet name:')
name = input()

if  name not in myPets :
    print('I don\'t have that pet')
else :
    print('I have '+name+' .')
