def cezar(inputText, key):
    inputAsList = list(inputText)
    symbols = [' ', '', '\\', '!', '@', '#', '$', '%', '^', '&', '*',
               '(', ')', '-', '=', '`', ',', '.', '?', ':', ';', '<', '>', '\n', '\t\n']
    for index, letterAsChar in enumerate(inputAsList):
        letterAsInt = ord(letterAsChar)
        if(letterAsChar not in symbols):
            if(letterAsInt + key > ord('Z') or letterAsInt + key < ord('A')):
                if(letterAsInt + key > ord('Z')):
                    letterAsInt = ord('A') + (ord('Z') -
                                              (letterAsInt + key - 1))
                if(letterAsInt + key < ord('A')):
                    letterAsInt = ord('Z') - (ord('A') -
                                              (letterAsInt + key + 1))
            else:
                letterAsInt = letterAsInt + key
            inputAsList[index] = chr(letterAsInt)
    inputText = ''.join(inputAsList)
    return inputText


def crypt(inputText, key):
    encrypted = cezar(inputText, key)
    print("key: ", key, "\ntext: ", encrypted)


def decrypt(inputText, key):
    decrypted = cezar(inputText, -key)
    print("key: ", key, "\ntext: ", decrypted)


def decryptForce(text):
    for i in range(0, 27):
        decrypted = cezar(text, -i)
        print("key: ", i, "\ntext: ", decrypted)


def readFile(file):
    with open(file) as file:
        data = file.read()
        print("insert key (can be empty if you selected decrypt brutforce): ")
        key = int(input())
        return [data, key]


def readInput():
    print("insert key (can be empty if you selected decrypt brutforce): ")
    key = int(input())
    print("insert text: ")
    data = input()
    return [data, key]


if __name__ == "__main__":
    print("Chose :\n1)encrypt\n2)decrypt\n3)decrypt - Bruteforce")
    choice = int(input())

    print("Input file or text to receive the letter frequency:\n1)file\n2)text")
    choiceRead = int(input())
    if(choiceRead == 1):
        print("Input file path:")
        data = readFile(input())
    else:
        print("Input text:")
        data = readInput()

    if choice == 1:
        crypt(data[0].upper(), data[1])
    elif choice == 2:
        decrypt(data[0].upper(), data[1])
    else:
        decryptForce(data[0].upper())
