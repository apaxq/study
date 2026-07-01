int multiply(int a, int b){
    if (b == 0) {
        return 0;
    }
    
    // Edge case for negative integers
    if (b < 0){
        return -a + multiply(a, b+1);
    }

    return a + multiply(a, b-1);
}

void main(String[] args) {
    if(args.length > 1){
        System.out.println(args[0] + " * " + args[1] + " = "
                + multiply(Integer.parseInt(args[0]), Integer.parseInt(args[1])));
    } else {
        System.out.println("No command line arguments found.");
    }
}
