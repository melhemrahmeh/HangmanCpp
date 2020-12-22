def isWordGuessed(secretWord, lettersGuessed):
    state = True
    for i in range(len(secretWord)):
        if secretWord[i] not in lettersGuessed:
            state = False
            break
    return state

def getGuessedWord(secretWord, lettersGuessed):
    c=''
    for i in secretWord:
        if i.lower() in lettersGuessed:
            c+=i
        else:
            c+="_"
    return c

def getAvailableLetters(lettersGuessed):
    alphabet = ""
    for i in range(ord('a'),ord('z')+1):
        if not chr(i) in lettersGuessed:
            alphabet+=chr(i)
    return alphabet

def hangman(secretWord):
    print('Welcome to the game, Hangman!')
    print(f'I am thinking of a word that is {len(secretWord)} letters long.')
    print("----------------------------------")

    lettersGuessed=[]
    i=8
    while i > 0:
        print(f"You have {i} guesses left.")
        print(f"Available letters: {getAvailableLetters(lettersGuessed)}")
        n = input("Please guess a letter: ")
        if n in secretWord:
            if n not in lettersGuessed:
                lettersGuessed.append(n)
                print("Good guess:",getGuessedWord(secretWord, lettersGuessed))
            else:
                print("Oops! You’ve already guessed that letter:",getGuessedWord(secretWord, lettersGuessed))
        else:
            i-=1
            print("Oops! That letter is not in my word:", getGuessedWord(secretWord, lettersGuessed)) 
        print("----------------------------------")
        if isWordGuessed(secretWord , lettersGuessed):
            print("Congratulations, you won!")
            break
    if not isWordGuessed(secretWord , lettersGuessed):
        print("Sorry, you ran out of guesses. The word was", secretWord)

secretWord = "hello"
hangman(secretWord)