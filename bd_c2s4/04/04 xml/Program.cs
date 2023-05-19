using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;
using System.Threading.Tasks;
namespace programcatalog
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument xmlDoc = new XmlDocument();
            XmlDeclaration xmlDec1 = xmlDoc.CreateXmlDeclaration("1.0", "utf-8", null);
            xmlDoc.AppendChild(xmlDec1);
            XmlElement catalogElement = xmlDoc.CreateElement("catalog");
            string answer;
            do
            {
                Console.WriteLine("введите 1, чтобы вписать данные, 2, чтобы просмотреть данные, 3, чтобы выйти:");
                answer = Console.ReadLine();
                if (answer == "1")
                {
                    string line = Console.ReadLine();
                    string[] fields = line.Split('|');
                    XmlElement catalogsElement = xmlDoc.CreateElement("catalog");
                    Console.WriteLine("Введите catalog:\n");
                    string catalog = Console.ReadLine();
                    catalogElement.SetAttribute("type", catalog);
                    XmlElement amountElement = xmlDoc.CreateElement("amount");
                    Console.WriteLine("Введите amount:\n");
                    string amount = Console.ReadLine();
                    amountElement.InnerText = amount;
                    XmlElement dateElement = xmlDoc.CreateElement("date");
                    Console.WriteLine("Введите date:\n");
                    string date = Console.ReadLine();
                    dateElement.InnerText = date;
                    XmlElement descriptionElement = xmlDoc.CreateElement("description");
                    Console.WriteLine("Введите description:\n");
                    string description = Console.ReadLine();
                    XmlCDataSection cdataDescription = xmlDoc.CreateCDataSection(description);
                    descriptionElement.AppendChild(cdataDescription);
                    XmlElement categoryElement = xmlDoc.CreateElement("category");
                    Console.WriteLine("Введите category:\n");
                    string category = Console.ReadLine();
                    categoryElement.InnerText = category;
                    catalogsElement.AppendChild(amountElement);
                    catalogsElement.AppendChild(dateElement);
                    catalogsElement.AppendChild(descriptionElement);
                    catalogsElement.AppendChild(categoryElement);
                    catalogElement.AppendChild(catalogsElement);
                    xmlDoc.AppendChild(catalogElement); xmlDoc.Save("../../../catalog.xml");
                }
                else if (answer == "2")
                {
                    StreamReader sr = new StreamReader("../../../catalog.xml");
                    string c;
                    while (sr.EndOfStream != true)
                    {
                        c = sr.ReadLine();

                        Console.WriteLine(c);
                    }

                    sr.Close();
                }
            }
            while (answer != "3");
}
        }   
    }