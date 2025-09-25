// See https://aka.ms/new-console-template for more information
using static System.Console;

await foreach (var num in GetNumbersAsync())
{
    WriteLine($"Number: {num}");
}

async static IAsyncEnumerable<int> GetNumbersAsync()
{
    Random r = new();

    await Task.Delay(r.Next(1500, 3000));
    yield return r.Next(0, 1001);
    await Task.Delay(r.Next(1500, 3000));
    yield return r.Next(0, 1001);
    await Task.Delay(r.Next(1500, 3000));
    yield return r.Next(0, 1001);
}

Console.WriteLine("Hello, World!");
