import sys

def multiply(a, b):
    if (b == 0):
        return 0

    if (b < 0):
        return -a + multiply(a, b+1)

    return a + multiply(a, b-1)

if len(sys.argv) > 2:
    print(sys.argv[1] + " * " + sys.argv[2] + " = "
          + str(multiply(int(sys.argv[1]), int(sys.argv[2]))))
else:
    print("Usage: " + sys.argv[0] + " <multiplicand> <multiplier>", file=sys.stderr)
    exit(1)