internal class Neuron
{
    public double[] Weights { get; }
    private double Bias { get; set; }
    public double Output { get; set; }
    private int WeigthsCount { get; }
    public Neuron(int weightsCount)
    {
        WeigthsCount = weightsCount;
        Weights = new double[WeigthsCount];
        InitializeWeights();
        Bias = 0;
        Output = 0;
    }
    public void InitializeWeights()
    {
        var _random = new Random();
        for (var i = 0; i < WeigthsCount; i++)
            Weights[i] = (_random.NextDouble() - 0.5) * 2; // случайные веса от -1 до 1.
    }
    public double ActivationFunction(double[] inputs)
    {
        double scalarProd = 0;
        for (var i = 0; i < WeigthsCount; i++)
            scalarProd += inputs[i] * Weights[i];
        scalarProd += Bias;
        Output = Sigmoid(scalarProd);
        return Output;
    }
    public void UpdateWeights(double learningRate, double errorGradient, double[] inputs)
    {
        for (var i = 0; i < WeigthsCount; i++)
            Weights[i] += learningRate * errorGradient * inputs[i];
        Bias += learningRate * errorGradient;
    }
    private double Sigmoid(double x)
    {
        return 1.0 / (1.0 + Math.Exp(-x));
    }
}
public class NeuralNetwork
{
    private Neuron[] _inputLayer;
    private Neuron[] _hiddenLayer;
    private Neuron _outputNeuron;
    private int InputLayerSize { get; init; }
    private int HiddenLayerSize { get; init; }
    public NeuralNetwork(int inputLayerSize, int hiddenLayerSize)
    {
        InputLayerSize = inputLayerSize;
        HiddenLayerSize = hiddenLayerSize;
        _inputLayer = new Neuron[InputLayerSize];
        _hiddenLayer = new Neuron[HiddenLayerSize];
        InitializeLayers();
        _outputNeuron = new Neuron(HiddenLayerSize);
    }
    private void InitializeLayers()
    {
        for (var i = 0; i < InputLayerSize; i++)
            _inputLayer[i] = new Neuron(1); // каждый нейрон входного слоя принимает по одному входу
        for (var i = 0; i < HiddenLayerSize; i++)
            _hiddenLayer[i] = new Neuron(InputLayerSize);
    }
    public void Train(double[] inputs, double target, double learningRate, int
   epochs)
    {

        // Прямое распространение (feedforward)
        var hiddenOutputs = new double[HiddenLayerSize];
        for (var i = 0; i < HiddenLayerSize; i++)
            hiddenOutputs[i] = _hiddenLayer[i].ActivationFunction(inputs);
        double output = _outputNeuron.ActivationFunction(hiddenOutputs);

        // Вычисление ошибки
        var error = target - output;

        // Обратное распространение ошибки (backpropagation)
        // Это необходимо для изменения весов и смещения (обучения)
        var outputGradient = output * (1 - output) * error; //из методички
        for (var i = 0; i < HiddenLayerSize; i++)
        {
            var hiddenLayerGradient = hiddenOutputs[i] * (1 - hiddenOutputs[i]) * _outputNeuron.Weights[i] * outputGradient;
            _hiddenLayer[i].UpdateWeights(learningRate, hiddenLayerGradient, inputs);
        }
        _outputNeuron.UpdateWeights(learningRate, outputGradient,
       hiddenOutputs);
    }

    public double GetTrainingResult()
    {
        return _outputNeuron.Output;
    }
    public double Predict(double[] inputs)
    {
        var hiddenOutputs = new double[HiddenLayerSize];
        for (var i = 0; i < HiddenLayerSize; i++)
            hiddenOutputs[i] = _hiddenLayer[i].ActivationFunction(inputs);
        return _outputNeuron.ActivationFunction(hiddenOutputs);
    }
}
internal class Program
{
    private static void Main()
    {
        var inputLayerSize = 3;
        var hiddenLayerSize = 2;

        var neuralNetwork = new NeuralNetwork(inputLayerSize, hiddenLayerSize);

        double[][] vectors =
        {
            new double[] { 0, 0, 0 },
            new double[] { 0, 0, 1 },
            new double[] { 0, 1, 0 },
            new double[] { 0, 1, 1 },
            new double[] { 1, 0, 0 },
            new double[] { 1, 0, 1 },
            new double[] { 1, 1, 0 },
            new double[] { 1, 1, 1 },
        };

        //исследуем функцию & (конъюнкция)
        double[] marks = { 0, 0, 0, 0, 0, 0, 0, 1 }; //разметка правильных данных

        var learningRate = 0.1;
        var epochs = 25000;
        //Обучение
        for (int epoch = 0; epoch < epochs; epoch++)
            for (var i = 0; i < vectors.Length; i++)
            {
                var input = vectors[i];
                var target = marks[i];
                neuralNetwork.Train(input, target, learningRate, epochs);
                var output = neuralNetwork.GetTrainingResult();

                if (epochs - epoch <= 12 || epochs - epoch >= epochs - 12)
                    //вывести только первые и последние 12 итераций обучения
                    Console.WriteLine($"Input: [{string.Join(", ", input)}], Target: {target}, Output: {output: 0.0000}");
            }
        var testSelection = GenerateInputs(15);
        // Тест
        Console.WriteLine("Predictions:");
        for (var i = 0; i < testSelection.Length; i++)
        {
            var testInput = testSelection[i];
            var prediction = neuralNetwork.Predict(testInput);
            Console.WriteLine($"Input: [{string.Join(", ", testInput)}], Prediction: {prediction: 0.0000}");
        }
    }
    private static double[][] GenerateInputs(int selectionSize)
    {
        Random random = new Random();
        var vectors = new List<double[]>();
        for (int i = 0; i < selectionSize; i++)
        {
            vectors.Add(new double[] { random.Next(0, 2), random.Next(0, 2), random.Next(0, 2) });
        }
        return vectors.ToArray();
    }
}