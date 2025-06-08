using System;
using System.Collections.Generic;
namespace lab4
{
    internal class Program
    {
        static int Fitness(List<int> chessboard)
        {
            int safeQueensCount = 0;
            for (int i = 0; i < chessboard.Count; i++)
            {
                int hasConflict = 1;
                for (int j = 0; j < i; j++)
                {
                    if (Math.Abs(i - j) == Math.Abs(chessboard[i] -
                    chessboard[j]))//i и j это вертикаль ферзей, а chessboard[i] и chessboard[j] горизонталь
                    {
                        hasConflict = 0;
                        break;
                    }
                }
                safeQueensCount += hasConflict;
            }
            return safeQueensCount;
        }
        static readonly Random random = new Random();
        static List<int> SimulatedAnnealingAlgorithm(int size)
        {
            List<int> chessboard = new List<int>();//ферзи по горизонтали
            for (int i = 0; i < size; i++)
            {
                chessboard.Add(i);// просто ставим их как попала, но все на своей горизонтали
            }
            List<int> currentSolution = new List<int>(chessboard);// проверяем как сейчас дела у ферзей, и конечно они все бьют друг друга
            int currentFitness = Fitness(currentSolution);// оцениваем функцией нынешнюю ситуацию
            decimal temperature = 1;// начальная температура
            decimal alpha = 0.99m;// параметр изменения температуры
            decimal minTemperature = 0.0001m;// конечная температуры
            while (temperature > minTemperature)
            {
                temperature *= alpha;// уменьшаем температуру (вообще бы это в конце делать, но пусть тут будет)
                List<int> newSolution = new List<int>(currentSolution);// новое решение, ну скоро будет
                int indexA = random.Next(size);// рандомная вертикаль 1
                int indexB = random.Next(size);// рандомная вертикаль 2
                (newSolution[indexB], newSolution[indexA]) = (newSolution[indexA],
                newSolution[indexB]);// меняем ферзей вертикалями
                int newFitness = Fitness(newSolution);// проверяем новое решение
                if (newFitness > currentFitness || 0.5 <
                Math.Exp((double)((newFitness - currentFitness) / temperature)))// мы либо хорошо сделали, либо вероятность так решила(Шаг 4)
                {
                    currentSolution = newSolution;
                    currentFitness = newFitness;
                }
                if (currentFitness == size) break; //мы нашли решения, дальше не нужно вычислять алгоритм
            }
            return currentSolution;
        }
        static void PrintBoard(List<int> chessboard)
        {
            int size = chessboard.Count;
            Console.WriteLine("Доска:");
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (chessboard[i] == j)
                        Console.Write("Q ");
                    else
                        Console.Write(". ");
                }
                Console.WriteLine();
            }
        }
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("Введите количество ферзей (введите число меньше 4 для выхода):");
                string input = Console.ReadLine();
                if (!int.TryParse(input, out int size))
                {
                    Console.WriteLine("Ошибка: Введите корректное целое число.");
                    continue; // Перейти к следующей итерации цикла
                }
                if (size < 4)
                    break;
                List<int> solution = SimulatedAnnealingAlgorithm(size);
                PrintBoard(solution);
            }
        }
    }
}
