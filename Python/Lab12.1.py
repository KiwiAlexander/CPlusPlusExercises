#Question 1

starWars = "A long time ago in a galaxy far far away"

longWords = map(lambda s: s.upper(), filter(lambda x: len(x) > 3, starWars.split()))

print(list(longWords))

#Question 2

def child(correctAnswers, incorrectAnswers):
    return (correctAnswers * 15) - (incorrectAnswers / 2)

def adult(correctAnswers, incorrectAnswers):
    return (correctAnswers * 10) - (incorrectAnswers * 1)

def quiz(correctAnswers, incorrectAnswers, isChild):
    if(isChild == True):
        return child(correctAnswers,incorrectAnswers)
    else:
        return adult(correctAnswers,incorrectAnswers)

childTotal = quiz(8,2,True)
adultTotal = quiz(8,2,False)

print(childTotal)
print(adultTotal)


