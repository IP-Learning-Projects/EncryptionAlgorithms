import operator


def frequency(text):
    frequencyDict = {}
    excludeList = ['\n', ' ', '    ', '\t\n']
    for i in text:
        if i not in excludeList:
            if i in frequencyDict:
                frequencyDict[i] += 1
            else:
                frequencyDict[i] = 1
    return sorted(frequencyDict.items(), key=operator.itemgetter(1), reverse=True)


def readFile(file):
    with open(file) as file:
        data = file.read()
        prettyPrint(frequency(data))


def readInput():
    data = input()
    prettyPrint(frequency(data))


def prettyPrint(dictionary):
    print(dictionary)
    for key, value in dictionary:
        print(key, ':', value)


if __name__ == "__main__":
    print("Input file or text to receive the letter frequency:\n1)file\n2)text")
    choice = int(input())
    if(choice == 1):
        print("Input file path:")
        readFile(input())
    else:
        print("Input text:")
        readInput()
