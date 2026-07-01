public static class Multiply {
    private static int multiply(int a, int b) {
        if (b == 0) {
            return 0;
        }

        if (b  < 0) {
            return -a + multiply(a, b+1);
        }

        return a + multiply(a, b-1);
    }

    public static int Main(string[] args) {
        if (args.Length > 1) {
            Console.WriteLine(args[0] + " * " + args[1] + " = " + multiply(int.Parse(args[0]), int.Parse(args[1])));
            return 0;
        }
        
        Console.Error.WriteLine("Usage: ./multiply <multiplicand> <multiplier>");
        return 1;
    }
}