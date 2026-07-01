import sys

def fizzbuzz(n):
    if n != 0:
        fizzbuzz(n - 1)

    if n % 3 == 0:
        if n % 3 == 0 or n % 5 == 0:
            if n % 3 == 0:
                print("Fizz", end='')
            if n % 5 == 0:
                print("Buzz", end='')
    else:
        print(n, end='')
    print()

if len(sys.argv) > 1:
    fizzbuzz(sys.argv[1])
else:
    print("Usage: " + sys.argv[0] + " <number>", file=sys.stderr)
    exit(1)