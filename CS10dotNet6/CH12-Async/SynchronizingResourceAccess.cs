using static System.Console;
using System.Diagnostics;


WriteLine("Please wait for the tasks to complete.");
var watch = Stopwatch.StartNew();
var a = Task.Factory.StartNew(MethodA);
var b = Task.Factory.StartNew(MethodB);

Task.WaitAll(new Task[] { a, b });
watch.Stop();
WriteLine();
WriteLine($"Results: {SharedObjects.Message}.");
WriteLine($"{watch.ElapsedMilliseconds:N0} elapsed milliseconds.");
WriteLine($"{SharedObjects.Counter} string modifications.");


// ********************************************************
// lock keyword implemented by Monitor class with try-finally in IL. 
// It may cause deadlock. Only uses lock when there is no deadlock case.
// ********************************************************
// static void MethodA()
// {
//     lock (SharedObjects.Conch)
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             Thread.Sleep(SharedObjects.Random.Next(2000));
//             SharedObjects.Message += "A";
//             Write(".");
//         }
//     }
// }
// static void MethodB()
// {
//     lock (SharedObjects.Conch)
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             Thread.Sleep(SharedObjects.Random.Next(2000));
//             SharedObjects.Message += "B";
//             Write(".");
//         }
//     }
// }

// *************************************************************************
// To use Monitor.TryEnter instead of lock to avoid any potential deadlocks.
// *************************************************************************
// static void MethodA()
// {
//     try
//     {
//         if (Monitor.TryEnter(SharedObjects.Conch, TimeSpan.FromSeconds(15)))
//         {
//             for (int i = 0; i < 5; i++)
//             {
//                 Thread.Sleep(SharedObjects.Random.Next(2000));
//                 SharedObjects.Message += "A";
//                 Write(".");
//             }
//         }
//         else
//         {
//             WriteLine("Method A timed out when entering a monitor on conch.");
//         }
//     }
//     finally
//     {
//         Monitor.Exit(SharedObjects.Conch);
//     }

// }
// static void MethodB()
// {
//     try
//     {
//         if (Monitor.TryEnter(SharedObjects.Conch, TimeSpan.FromSeconds(15)))
//         {
//             for (int i = 0; i < 5; i++)
//             {
//                 Thread.Sleep(SharedObjects.Random.Next(2000));
//                 SharedObjects.Message += "B";
//                 Write(".");
//             }
//         }
//         else
//         {
//             WriteLine("Method B timed out when entering a monitor on conch.");
//         }
//     }
//     finally
//     {
//         Monitor.Exit(SharedObjects.Conch);
//     }
// }

// ********************************************************
// interlock 
// ********************************************************
static void MethodA()
{
    try
    {
        if (Monitor.TryEnter(SharedObjects.Conch, TimeSpan.FromSeconds(15)))
        {
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(SharedObjects.Random.Next(2000));
                SharedObjects.Message += "A";
                Interlocked.Increment(ref SharedObjects.Counter);
                Write(".");
            }
        }
        else
        {
            WriteLine("Method A timed out when entering a monitor on conch.");
        }
    }
    finally
    {
        Monitor.Exit(SharedObjects.Conch);
    }

}
static void MethodB()
{
    try
    {
        if (Monitor.TryEnter(SharedObjects.Conch, TimeSpan.FromSeconds(15)))
        {
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(SharedObjects.Random.Next(2000));
                SharedObjects.Message += "B";
                Interlocked.Increment(ref SharedObjects.Counter);
                Write(".");
            }
        }
        else
        {
            WriteLine("Method B timed out when entering a monitor on conch.");
        }
    }
    finally
    {
        Monitor.Exit(SharedObjects.Conch);
    }
}

static class SharedObjects
{
    public static Random Random = new();
    public static string? Message; // a shared resource for lock and Monitor

    public static object Conch = new();

    public static int Counter; // shared resouce for interlock
}
