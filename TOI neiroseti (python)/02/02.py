from __future__ import annotations # объявление ссылок на класс внутри самого класса (Node.Left, Node.Right)

# для словаря (символ - код)
class DictionaryEntry:
    Char: str
    Code: str
    
    def __init__(self, char, code):
        self.Char = char
        self.Code = code

# символ и частота его появления в тексте
class CharFrequency:
    Char: str
    Used: int
    
    def __init__(self, char, used):
        self.Char = char
        self.Used = used

# узел дерева: символ, его вес и соседи слева и справа
class Node:
    Char: str = None
    Order: int
    Left: Node
    Right: Node
    
    def __init__(self, ch = None, priority = None, left = None, right = None):
        if (left == None and right == None):
            self.Char = ch
            self.Order = priority
        else:
            self.Left = left
            self.Right = right
            self.Order = left.Order + right.Order

def TreeBase(str, letters):
# отсортированный список символов и их частот в тексте
    list = []
    for c in letters:
        list.append(CharFrequency(c, str.count(c)))
    list = sorted(list, key=lambda x: x.Used)
# построение дерева и возврат его корня
    nodes = []
    for item in list:
        nodes.append(Node(item.Char, item.Used))
    nodes = sorted(nodes, key=lambda x: x.Order)
    while (len(nodes) > 1):
        left = nodes[0]
        right = nodes[1]
        nodes = nodes[2:]
        nodes.append(Node(None, None, left, right))
        nodes = sorted(nodes, key=lambda x: x.Order)
    return nodes[0]

# заполнение словаря кодами с использованием построенного дерева
def FillDictionary(node, code = ""):
    if (hasattr(node, "Left") and node.Left != None): FillDictionary(node.Left, code + "0")
    if (hasattr(node, "Right") and node.Right != None): FillDictionary(node.Right, code + "1")
    if (hasattr(node, "Char") and node.Char != None):
        ch = DictionaryEntry(node.Char, code)
        dictionary.append(ch)

def HuffmanEncode(str):
    res = ""
    for s in str:
        res += next((x.Code for x in dictionary if x.Char == s), "")
    return res

def HuffmanDecode(code):
    res = ""
    temp = ""
    while (len(code) > 0):
        temp += code[0]
        code = code[1:len(code)]
        if (any([e.Code == temp for e in dictionary])):
            res += next((e.Char for e in dictionary if e.Code == temp), "")
            temp = ""
    return res

dictionary = []
print("Введите любую строку:")
text = input()
FillDictionary(TreeBase(text, set(text)));
code = HuffmanEncode(text);
print("Закодированная строка:", code)
decodedStr = HuffmanDecode(code);
print("Декодированная строка:", decodedStr)
for el in dictionary:
    print("Символ: ", el.Char, " Код: ", el.Code)