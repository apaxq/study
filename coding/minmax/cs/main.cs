public static class MinMax {
    private static int GetMinMaxFromFile(string fileName) {
        int min = 0, max = 0;
        
        try {
            var file = new StreamReader(fileName);
            
            var line = file.ReadLine();
            if (line != null) {
                min = int.Parse(line);
                max = int.Parse(line);
            }

            line = file.ReadLine();
            while (line != null) {
                if (int.Parse(line) < min) {
                    min = int.Parse(line);
                }else if (int.Parse(line) > max) {
                    max = int.Parse(line);
                }
                
                line = file.ReadLine();
            }
            
            file.Close();
            Console.WriteLine("The min is: " + min + "\nThe max is " + max);
        }
        catch(Exception e)
        {
            Console.WriteLine("Exception: " + e.Message);
            return 1;
        }
        
        return 0;
    }
    
    public static int Main(string[] args) {
        if (args.Length > 0)
        {
            return GetMinMaxFromFile("../integers.txt");
        }

        Console.Error.WriteLine("Usage: ./minmax <file>");
        return 1;
    }
}