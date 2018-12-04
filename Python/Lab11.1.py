import random

#Practical One
myString = "abcdefg"
def oddWord(myString):
    outputString = ""

    for i in range(len(myString)):
        if(i % 2 == 1):
            outputString += myString[i]

    print(outputString)

#Practical Two
def minMax():
    min = 100
    max = 0

    for i in range(10):
        rGen = random.randrange(100)
        if(rGen < min):
            min = rGen
        if(rGen > max):
            max = rGen
    print(min)
    print(max)

oddWord(myString)
minMax()