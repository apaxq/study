void fizzbuzz(int max){
    if (max != 0) {
        fizzbuzz(max - 1);
    }

    if (max % 3 == 0 || max % 5 == 0) {
        if (max % 3 == 0) {
            System.out.print("Fizz");
        }
        if (max % 5 == 0) {
            System.out.print("Buzz");
        }
    }else {
        System.out.print(max);
    }
    System.out.println("");
}

void main(String[] args) {
    if(args.length > 0){
        fizzbuzz(Integer.parseInt(args[0]));
    }else{
        System.err.println("No command line arguments found.");
    }
}
