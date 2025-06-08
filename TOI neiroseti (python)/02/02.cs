// https://www.youtube.com/watch?v=uzaVPg79bfQ
List<CharCode> dictionary = new();

string str = "testing string";
CheckNode(ToTree(FindProbability(str, FindLetters(str))), "");
var code = Code(str);
var decode = Decode(code);
Console.WriteLine($"Source message - {str}");
Console.WriteLine($"Encode message - {code}");
Console.WriteLine($"Decode message - {decode}");
Print();

char[] FindLetters(string str) {
    return str.Distinct().ToArray();
}

List<CharFrequency> FindProbability(string str, char[] letters) {
    var probability = new List<CharFrequency>();
    foreach (char c in letters) {
        var match = str.Where(x => x == c);
        probability.Add(new() { Used = match.Count(), Char = c });
    }
    probability = probability.OrderBy(e => e.Used).ToList();
    return probability;
}


Node ToTree(List<CharFrequency> list) {
    var nodes = new List<Node>();
    foreach (CharFrequency item in list)
    {
        nodes.Add(new(item.Char, item.Used));
    }
    nodes = nodes.OrderBy(e => e.Order).ToList();
    while (nodes.Count() > 1)
    {
        var left = nodes[0];
        var right = nodes[1];
        nodes.RemoveAt(0);
        nodes.RemoveAt(0);
        nodes.Add(new(left, right));
        nodes = nodes.OrderBy(e => e.Order).ToList();
    }
    return nodes[0];
}


void CheckNode(Node node, string code)
{
    if (node.Left is not null)
    {
        CheckNode(node.Left, code + "0");
    }
    if (node.Right is not null)
    {
        CheckNode(node.Right, code + "1");
    }
    if (node.Char is not null)
    {
        dictionary.Add(new() { Char = (char)node.Char, Code = code });
    }
}

string Code(string str)
{
    string result = "";
    foreach (var s in str)
    {
        result += dictionary.Where(e => e.Char == s).Select(e => e.Code).FirstOrDefault();
    }
    return result;
}


string Decode(string code)
{
    string result = "", temp = "";
    while (code.Length > 0)
    {
        temp += code.Substring(0, 1);
        code = code.Substring(1, code.Length - 1);
        if (dictionary.Any(e => e.Code == temp))
        {
            result += dictionary.Where(e => e.Code == temp).Select(e => e.Char).FirstOrDefault();
            temp = "";
        }
    }
    return result;
}

void Print()
{
    Console.WriteLine("");
    foreach (var el in dictionary)
    {
        Console.WriteLine($"Symbol: {el.Char} Code: {el.Code}");
    }
    Console.WriteLine("");
}


public class Node
{
    public char? Char;
    public int Order;
    public Node Left;
    public Node Right;

    public Node(char ch, int priority)
    {
        Char = ch;
        Order = priority;
    }
    public Node(Node left, Node right)
    {
        Left = left;
        Right = right;
        Order = left.Order + right.Order;
    }
}
record struct CharCode (char Char, string Code);
record struct CharFrequency(char Char, int Used);