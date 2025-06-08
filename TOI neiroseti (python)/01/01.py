from decimal import *
getcontext().prec = 80 # чем больше знаков после запятой, тем длиннее строку можно закодировать

class Sector:
    char: str
    left: Decimal
    right: Decimal

def SetSectors(str, chars):
    # частота появления каждого уникального символа в строке
    freq = [[0 for k in range(2)] for j in range(len(chars))]
    i = 0
    for char in chars:
       freq[i][0] = char
       freq[i][1] = str.count(char) / len(str)
       i += 1
    # распределение границ секторов символов
    sector = [Sector() for i in range (len(freq))]
    left = Decimal(0)
    for i in range (0, len(freq)):
        sector[i].left = left
        sector[i].right = left + Decimal(freq[i][1])
        sector[i].char = freq[i][0]
        left = Decimal(sector[i].right)
    return sector

def ArithmeticEncode(str, sector):
    left = 0
    right = 1
    for i in range (len(str)):
        charSector = [x for x in sector if x.char == str[i]]
        newLeft = left + (right-left) * charSector[0].left
        newRight = left + (right-left) * charSector[0].right
        left = newLeft
        right = newRight
    return (left + right) / 2

def ArithmeticDecode(sector, chars, code, strLength):
    str = ""
    for i in range (strLength):
        for j in range (len(chars)):
            if (code >= sector[j].left and code < sector[j].right):
                str += sector[j].char
                code = (code - sector[j].left) / (sector[j].right - sector[j].left)
                break
    return str

print("Введите любую строку: ")
str = input()
chars = set(str) # сет каждый раз меняет порядок символов
sector = SetSectors(str, chars)
code = ArithmeticEncode(str, sector)
print("Закодированная строка:", code)
decodedStr = ArithmeticDecode(sector, chars, code, len(str))
print("Декодированная строка:", decodedStr)
if (str != decodedStr): print("Необходимо увеличить число знаков после запятой. Текущее число:", getcontext().prec)