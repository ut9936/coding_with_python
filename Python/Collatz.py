def collatz(number) :
    if number%2 == 0 :
        print(str(number//2))
        return number//2
    else :
        print(str(3*number + 1))
        return 3*number + 1

print('Enter one positive integer value:',end = '')
try :
    number = int(input())
    if(number <= 0) :
        print('Invalid input')
        number = 1
except :
    number = 1
    print('Invalid input')
while(number != 1) :
    number = collatz(number)
