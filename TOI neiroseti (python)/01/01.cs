using System;
using System.Collections.Generic;
using System.Linq;
// (1) найдём частоту встречаемости каждого символа:
double[] FindFrequency(string str, char[] symbols)
{
    var frequency = new List<double>(); // список частот встречаемости
    foreach (char c in symbols)
    {
        var match = str.Where(x => x == c); // находим одинаковые символы
        frequency.Add((double)match.Count() / str.Length); // считаем частоту встречаемости каждого символа
    }
    return frequency.ToArray(); // возвращаем список в виде массива
}
// определим отрезки для каждого символа (мы уже имеем символы и их частоту):
Section[] DefineSection(char[] symbols, double[] frequency)
{
    Section[] section = new Section[symbols.Length]; // отрезок
    double l = 0; // левая граница отрезка
    for (int i = 0; i < symbols.Length; i++)
    {
        section[i].Left = l; // берём левую границу отрезка символа (сначала - от 0 до 1)
        section[i].Right = l + frequency[i]; // и правую, которая есть левая граница + частота символа
        section[i].Symbol = symbols[i]; // сохраняем сам символ
        l = section[i].Right; // переходим на следующий отрезок, что правее
    }
    return section; // сохраняем отрезок: символ, левая и правая границы
}
// АРИФМЕТИЧЕСКОЕ КОДИРОВАНИЕ:
// получаем кодируемое сообщение, его символы и их частоту
double ArithmeticEncoding(char[] symbols, double[] frequency, string str)
{
    // определяем отрезки:
    var section = DefineSection(symbols, frequency);
    // берём полный отрезок (от 0 до 1)
    double left = 0, right = 1;
    // проходимся по всей длине кодируемого сообщения:
    for (int i = 0; i < str.Length; i++)
    {
        int symb = Array.IndexOf(symbols, str[i]); // каждый символ сообщения
                                                   // делим отрезок:
        double newRight = left + (right - left) * section[symb].Right;
        double newLeft = left + (right - left) * section[symb].Left;
        // определяем следующий отрезок (который будем делить в след. раз)
        left = newLeft;
        right = newRight;
    }
    return (left + right) / 2; // возвращает длину отрезка
}
// ДЕКОДИРОВАНИЕ:
// получаем закодированное сообщение, длину отрезка, символы и их частоты
string ArithmeticDecoding(char[] symbols, double[] frequency, double code,
int n)
{ // определяем отрезки:
    var section = DefineSection(symbols, frequency);
    string str = ""; // берём строку, сначала пустую, далее она станет нашим ответом
    for (int i = 0; i < n; i++) // проходимся по всей длине отрезка
    {
        for (int j = 0; j < symbols.Length; j++) // проходимся по длине символа
        {
            // если закодированное сообщение находится в отрезке символа, то...
            if (code >= section[j].Left && code < section[j].Right)
            {
                str += section[j].Symbol; // прибовляем к строке символ
                                          //вычитаем из закодированного сообщения проверенные отрезки
                code = (code - section[j].Left) / (section[j].Right -
                section[j].Left);
                break;
            }
        }
    }
    return str; //выводим декодированное сообщение
}
Console.WriteLine("Write a string to encode: "); //запросим сообщение для кодирования:
string str = Console.ReadLine();
var symbols = str.Distinct().ToArray();
var frequency = FindFrequency(str, symbols);
var code = ArithmeticEncoding(symbols, frequency, str);
var decode = ArithmeticDecoding(symbols, frequency, code, str.Length);
//выводим результата и проверку:
Console.WriteLine("Encoded string: " + code);
Console.WriteLine("Decoded string: " + decode);
if (decode == str)
{
    Console.WriteLine("Success! Congratulations!");
}
else
{
    Console.WriteLine("Something went wrong");
}
//запись структуры (отрезков)
record struct Section(char Symbol, double Left, double Right);