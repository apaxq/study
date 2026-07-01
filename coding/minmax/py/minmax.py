import sys

def get_min_max_from_file(filename):
    min, max = 0, 0

    with open(filename, 'r', encoding='utf-8') as file:
        for index,line in enumerate(file):
            if index == 0:
                min = int(line)
                max = int(line)
            else:
                if int(line) > max:
                    max = int(line)
                elif int(line) < min:
                    min = int(line)

    print("The min is " + str(min))
    print("The max is " + str(max))

if len(sys.argv) > 1:
    get_min_max_from_file(sys.argv[1])
else:
    print("Please input the file name", file=sys.stderr)
    exit(1)