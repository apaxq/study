public static class FizzBuzz {
	private static void fizzbuzz(int max) {
        if (max != 1) {
            fizzbuzz(max - 1);
        }

        if (max % 3 == 0 || max % 5 == 0) {
            if (max % 3 == 0) {
            	Console.Write("Fizz");
        	}
        	if (max % 5 == 0) {
            	Console.Write("Buzz");
        	}
        } else {
			Console.Write(max);
		}
		Console.WriteLine();
    }

	public static int Main(string[] args) {
		if (args.Length > 0) {
			fizzbuzz(int.Parse(args[0]));
			return 0;
		}
		
		Console.Error.WriteLine("Usage: ./fizzbuzz <multiplicand> <multiplier>");
        return 1;
	}
}