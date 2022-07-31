import sys


def read_file_by_lines(filename):
    with open(filename, "r") as f:
        return set([line for line in f])


def write_to_file(filename, lines):
    with open(filename, "w") as f:
        for line in lines:
            f.write(line)


def filter_comments(lines):
    return set([line for line in lines if not line.startswith("####")])


def main():
    first = read_file_by_lines(sys.argv[1])
    second = read_file_by_lines(sys.argv[2])
    write_to_file("diff.txt", filter_comments(first - second))


if __name__ == "__main__":
    main()
