import random
secretNumber = random.randint(1,20)
print('I\'m thinking of a number between 1-20')
for guessTaken in range(0,6) :
    print('Take a guess')
    guess = int(input())
    if guess > secretNumber :
        print('Your guess is to high')
    elif guess < secretNumber :
        print('Your guess is too low')
    else :
        break

if(guessTaken < 6) :
    print('Good job! you guessed the number in '+str(guessTaken+1)+' guesses.')
else :
    print('Number I was thinking was '+str(secretNumber)+'.')
    
input()
