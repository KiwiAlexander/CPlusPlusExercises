import random

def slice():

    value = "0123456789"
    print(value)

    #Question 1A
    print(value[4:8])
    print(value[-6:-2])

    #Question 1B
    print(value[5:])

    #Question 1C
    print(value[1:8:2])

    #Qustion 1D
    print(value[-3:-10:-2])

def sequenceTypes():

    #Question 2A
    value = 1;
    rGen = random.randrange(2)
    if value in [rGen]: print("heads")

    #Question 2B
    if value not in[rGen]: print("tails")

    #Question 2C
    value = "pie"
    print(value + value)

    #Question 2D
    print(value * 3)

    #Question 2E
    value = "GuessTheLengthOfThisString"
    print(len(value))

    #Question 2F
    values = [1,2,3,4,5]
    print(min(values))
    print(max(values))

    #Question 2G
    values = ["First", "Second", "Third"]
    print(values.index("Second"))

    #Question 2H
    values = [1,2,2,3,3,3,4,4,4,4]
    print(values.count(4))

    #Question 2I
    print(values)
    del values[2]
    del values[1]
    print(values)

    #Question 2J
    values = [1,2,3,4]
    values.append(5)
    print(values)

    #Question 2K
    setOne = ["Dogs", "Cats"]
    setTwo = ["Fish", "Monkeys"]
    setOne.extend(setTwo)
    print(setOne)

    #Question 2L
    values = ["One", "Three"]
    values.insert(1,"Two")
    print(values)

    #Question 2M
    values.remove("One")
    print(values)

    #Question 2N
    value = values.pop(1)
    print(value)

    #Question 2O
    order = [1,2,3,4,5]
    order.reverse()
    print(order)

#Question 3 !CODE NOT WORKING!

class Dog:

    count = 0

    def __INIT__(self,name,breed):
        self.name = name
        self.breed = breed
        self.count += 1

    def dogCount(self):
        print(self.count)

def staticClass():
    print("a")
    dogOne = Dog('Rex', "German Shepherd")
    dogTwo = Dog('Buddy', "Poodle")
    print("b")

    print(dogOne.dogCount)
    print("c")

# Explain
# Because count is shared by all the class instances when they add count
# create an instance and add to count they all share that added ammount
# in the example on the sheet you created three dogs then tried to output
# their dogCount method, because three dogs had been made they all added one
# to count therefore making it three in total. Count is static and shared.

slice()
sequenceTypes()
staticClass()