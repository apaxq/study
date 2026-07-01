void GetMinMaxFromFile(String filename){
    int min = 0, max = 0;
    File myObj = new File(filename);

    try (Scanner myReader = new Scanner(myObj)) {
        if(myReader.hasNextLine()){
            int integer = Integer.parseInt(myReader.nextLine());
            min = integer;
            max = integer;
        }

        while (myReader.hasNextLine()) {
            int integer = Integer.parseInt(myReader.nextLine());
            if (integer < min){
                min = integer;
            } else if (integer > max) {
                max = integer;
            }
        }

        System.out.println("The min is " + min + "\nThe max is " + max);
    } catch (FileNotFoundException e) {
        System.out.println("File not found.");
    }
}

void main(String[] args) {
    if(args.length > 0){
        GetMinMaxFromFile(args[0]);
    } else {
        System.out.println("No command line arguments found.");
    }
}
