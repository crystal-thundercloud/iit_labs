internal class GeneticAlgorithm
{
    private readonly int[,] _cities;
    private readonly int _generationsCount;
    private readonly double _mutationRate;
    private readonly int _populationSize;
    private readonly int _printGenerationInterval;
    private readonly Random _random;
    public GeneticAlgorithm(int[,] cities, int generationsCount, double mutationRate, int populationSize, int printGenerationInterval = 0)
    {
        _cities = cities;
        _generationsCount = generationsCount;
        _mutationRate = mutationRate;
        _populationSize = populationSize;
        _random = new Random();
        _printGenerationInterval = printGenerationInterval; // для визуализации
        CitiesCount = _cities.GetLength(0);
        Population = InitializePopulation();
    }
    private int[][] Population
    {
        get;
        set;
    }
    private int CitiesCount { get; }
    public (int[], int) FindBestSolution()
    {
        for (var generation = 0; generation < _generationsCount + 1;
             generation++)
        {
            Population = Population.OrderBy(tour => CalculateTourLenght(tour)).ToArray();
            var newPopulation = new int[_populationSize][];
            for (var i = 0; i < _populationSize; i++)
            {
                var parent1 = SelectParent(Population);
                var parent2 = SelectParent(Population);
                var child = Recombination(parent1, parent2);
                child = TryMutate(child);
                newPopulation[i] = child;
            }
            Population = newPopulation;
            if (_printGenerationInterval != 0 &&
                generation % _printGenerationInterval == 0)
                PrintProgress(generation);
        }

        // лучшее поколение - первое, потому что мы сортируем по возрастанию
        var bestTour = Population.OrderBy(tour => CalculateTourLenght(tour)).First();
        return (bestTour, CalculateTourLenght(bestTour));
    }
    public int[][] InitializePopulation()
    {
        var population = new int[_populationSize][];
        for (var i = 0; i < _populationSize; i++) {
            population[i] = Enumerable.Range(0, CitiesCount).OrderBy(x => _random.Next()).ToArray();
        }
        return population;
    }
    public int[] SelectParent(int[][] population)
    {
        var tournamentSize = 8;
        var tournament = new int[tournamentSize][];
        for (var i = 0; i < tournamentSize; i++)
            tournament[i] = population[_random.Next(_populationSize)];
        return tournament.OrderBy(tour => CalculateTourLenght(tour)).First();
    }
    // мы не можем что-либо добавлять,
    // поэтому мутация - это случайная перестановка городов в последовательности
    // важная оговорка: с некоторым шансом
    private int[] TryMutate(int[] chromosome)
    {
        if (_random.NextDouble() < _mutationRate)
        {
            var swapIndex1 = _random.Next(chromosome.Length);
            var swapIndex2 = _random.Next(chromosome.Length);
            (chromosome[swapIndex1], chromosome[swapIndex2]) =
                (chromosome[swapIndex2],
                 chromosome[swapIndex1]);
        }
        return chromosome;
    }
    // меняем местами гены двух родителей, чтобы получить ребенка
    private int[] Recombination(int[] parent1, int[] parent2)
    {
        var child = new int[parent1.Length];
        var startPos = _random.Next(parent1.Length - 1);
        var endPos = _random.Next(startPos, parent1.Length);
        for (var i = startPos; i < endPos; i++)
            child[i] = parent1[i];
        var currentIndex = endPos % parent1.Length;
        foreach (var parent in parent2)
            if (!child.Contains(parent))
            {
                child[currentIndex] = parent;
                currentIndex = (currentIndex + 1) % parent1.Length;
            }
        return child;
    }
    public int CalculateTourLenght(int[] tour)
    {
        var length = 0;
        for (var i = 0; i < tour.Length - 1; i++)
            length += _cities[tour[i], tour[i + 1]];
        length += _cities[tour[^1], tour[0]];
        return length;
    }
    private void PrintProgress(int generationNum)
    {
        var bestTour = Population.OrderBy(tour => CalculateTourLenght(tour)).First();
        Console.WriteLine($"Generation {generationNum}: Best tour length - {CalculateTourLenght(bestTour)}");
    }
}
internal static class Program
{
    private static void Main()
    {
        int[,] costs =
            {
                {0, 29, 20, 21, 16, 31, 100, 12, 4, 31},
                {29, 0, 15, 29, 28, 40, 72, 21, 29, 41},
                {20, 15, 0, 15, 14, 25, 81, 9, 23, 27},
                {21, 29, 15, 0, 4, 12, 92, 12, 25, 13},
                {16, 28, 14, 4, 0, 16, 95, 24, 36, 3},
                {31, 40, 25, 12, 16, 0, 97, 35, 45, 18},
                {100, 72, 81, 92, 95, 97, 0, 63, 84, 89},
                {12, 21, 9, 12, 24, 35, 63, 0, 16, 22},
                {4, 29, 23, 25, 36, 45, 84, 16, 0, 38},
                {31, 41, 27, 13, 3, 18, 89, 22, 38, 0}};
        var geneticAlgorithm = new GeneticAlgorithm(costs, 2000, 0.15, 20, 200);
        // последний аргумент необязательный параметр для визуализации поколений
        var bestSolution = geneticAlgorithm.FindBestSolution();
        Console.WriteLine("Best tour: " + string.Join(" -> ", bestSolution.Item1));
        Console.WriteLine("Best tour length: " + bestSolution.Item2);
    }
}
