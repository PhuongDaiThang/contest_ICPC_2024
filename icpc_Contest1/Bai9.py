import re
import sys


def main():
    int32_max = 2147483647
    int64_max = 9223372036854775807
    total_sum = 0

    data = sys.stdin.read()

    numbers = re.findall(r'\d+', data)

    for num_str in numbers:
        num = int(num_str)
        if int32_max < num <= int64_max:
            total_sum += num

    print(total_sum)


if __name__ == "__main__":
    main()
