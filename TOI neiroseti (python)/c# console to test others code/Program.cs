class HebbianNetwork
{
    static void Main()
    {
        double[] weights = InitializeWeights(2);

        double[][] trainigData = {
            new double[] { 1, 0 },
            new double[] { 0, 1 },
            new double[] { 1, 1 },
        };
        foreach (var input in trainigData)
        {
            Train(input, weights);
        }
        for (double x = 0; x <= 2; x += 0.5)
        {
            for (double y = 0; y <= 2; y += 0.5)
            {
                double[] vectorInput = { x, y };
                double output = OutputLayer(vectorInput, weights);
                Console.WriteLine($"Vector :[{string.Join(", ", vectorInput)}] - length claster: { Math.Round(output)}");
            }
        }
    }

    static double[] InitializeWeights(int size)
    {
        double[] weights = new double[size];
        for (int i = 0; i < size; i++)
        {
            weights[i] = 0;
        }
        return weights;
    }

    static void Train(double[] input, double[] weights)
    {
        for (int i = 0; i < weights.Length; i++)
        {
            weights[i] += input[i] * input[i];
        }

        NormalizeWeights(weights);
    }

    static void NormalizeWeights(double[] weights)
    {
        double sum = 0;
        for (int i = 0; i < weights.Length; i++)
        {
            sum += weights[i] * weights[i];
        }
        double magnitude = Math.Sqrt(sum);
        for (int i = 0; i < weights.Length; i++)
        {
            weights[i] /= magnitude;
        }
    }
    //нейросеть без нейронов…
    static double OutputLayer(double[] input, double[] weights)
    {
        double output = 0;
        for (int i = 0; i < input.Length; i++)
        {
            output += input[i] * weights[i];
        }
        return output;
    }
}
