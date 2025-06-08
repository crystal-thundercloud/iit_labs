const double ALPHA = 2;
const double BETA = 1;
const double CITIES_NUMBER = 5;
const double STEPS = 10;
const int ANT_COUNT = 5;
const int CITIES_COUNT = ANT_COUNT;
const double EVAPORATION_FACTOR = 0.6;
(List<int> Route, int RouteLength) BestRoute = (new List<int>(), 9999);
int[,] RouteLens =
{
    { 0, 3, 3, 5, 3 },
    {3, 0, 2, 7, 1 },
    {3, 2, 0, 4, 7},
    {5, 7, 4, 0, 2 },
    {3, 1, 7, 2, 0},
};
double[,] Phrmns =
{
    {0, 1, 1, 1, 1 },
    {1, 0, 1, 1, 1 },
    {1, 1, 0, 1, 1 },
    {1, 1, 1, 0, 1 },
    {1, 1, 1, 1, 0},
};

for (int i = 0; i < STEPS; i++)
{
    Console.WriteLine($"\nStep - {i + 1}");
    double[,] allAddPhrmnsOnStep =
    {
        { 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 0, 0}, 
        { 0, 0, 0, 0, 0},
    };

    for (int ant = 0; ant < ANT_COUNT; ant++)
    {
        var route = AntRoute(ant);
        allAddPhrmnsOnStep = UpdatePhrmns(allAddPhrmnsOnStep, route.PhrmnsMap, false);
        Print((route.Route, GetRoutelenght(route.Route)), ant);
        CheckRoute(route. Route);
    }
    Phrmns = UpdatePhrmns(Phrmns, allAddPhrmnsOnStep, true);
}

string str = "";
for (int i = 0; i < BestRoute.Route.Count - 1; i++)
{
    str += $"{BestRoute.Route[i]} - ";
}
str += $"{BestRoute.Route[BestRoute.Route.Count - 1]}";

Console.WriteLine($"\n\n Optimal path - {str}, Length - {BestRoute.RouteLength}");

double ProbabilityOnePath(int current, int next, List<int> taboo)
{
    double currentWish = Math.Pow(Phrmns[current, next], ALPHA) * (10 / Math.Pow(RouteLens[current, next], BETA));
    double alltWish = 0;
    for (int i = 0; i < CITIES_NUMBER; i++)
    {
        if (i != current && !taboo.Contains(i))
            alltWish += Math.Pow(Phrmns[current, i], ALPHA) * (10 / Math.Pow(RouteLens[current, i], BETA));
    }
    return currentWish / alltWish;
}

List<(int, double)> AllowedSitiesList(int ant, List<int> taboo = null)
{
    List<(int, double)> allowedList = new List<(int, double)>();
    taboo = taboo ?? new List<int>();
    for (int s = 0; s < CITIES_COUNT; s++)
    {
        if (!taboo.Contains(s))
        {
            if (RouteLens[ant, s] > 0)
            {
                var probability = ProbabilityOnePath(ant, s, taboo);
                allowedList.Add((s, probability));
            }
        }
    }
    return allowedList;
}

int SelectCity(List<(int, double)> allowedCities)
{
    double temp = 0;
    var rand = new Random().NextDouble();
    for (int i = 0; i < allowedCities.Count; i++)
    {
        temp += allowedCities[i].Item2;
        if (rand < temp)
        {
            return allowedCities[i].Item1;
        }
    }
    return allowedCities[allowedCities.Count - 1].Item1;
}

(List<int> Route, double[,] PhrmnsMap) AntRoute(int ant)
{
    int currPos = ant;
    double[,] addPhrmns =
    {
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    var route = new List<int>();
    route.Add(currPos);
    var notTaboo = AllowedSitiesList(currPos);
    while (notTaboo.Count > 0)
    {
        var selectedCity = SelectCity(notTaboo);
        addPhrmns[currPos, selectedCity] += 1 / (double)RouteLens[currPos, selectedCity];
        addPhrmns[selectedCity, currPos] += 1 / (double)RouteLens[selectedCity, currPos];
        currPos = selectedCity;
        route.Add(currPos);
        notTaboo = AllowedSitiesList(currPos, route);
    }
    return (route, addPhrmns);
}

double[,] UpdatePhrmns(double[,] a, double[,] b, bool isNeedEvaparation = true)
{
    for (int i = 0; i < CITIES_COUNT; i++)
    {
        for (int j = 0; j < CITIES_COUNT; j++)
        {
            a[i, j] = (isNeedEvaparation ? EVAPORATION_FACTOR : 1) * a[i, j] + b[i, j];
        }
    }
    return a;
}

int GetRoutelenght (List<int> route)
{
    int Length = 0;
    for (int i = 0; i < route.Count - 1; i++)
    {
        Length += RouteLens[route[i], route[i + 1]];
    }
    Length += RouteLens[route[route.Count - 1], route[0]];
    return Length;
}

void CheckRoute(List<int> route)
{
    var routeLenght = GetRoutelenght(route);
    if (routeLenght < BestRoute.RouteLength) BestRoute = (route, routeLenght);
}

void Print((List<int> Route, int Lenght) route, int number)
{
    Console.WriteLine($"Ant - {number}");
    string str = "";
    for (int i = 0; i < route.Route.Count - 1; i++)
    {
        str += $"{route.Route[i]} - ";
    }
    str += $"{route.Route[route.Route.Count - 1]}";
    Console.WriteLine($"Path - {str}, Length - {route.Lenght}");
}