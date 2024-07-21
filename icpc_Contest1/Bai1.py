def process_reversals(s, reversals):
    s = list(s)  # Convert string to list for mutable operations
    n = len(s)

    # Perform each reversal
    for ai in reversals:
        l = ai - 1
        r = n - ai
        if l < r:
            while l < r:
                s[l], s[r] = s[r], s[l]
                l += 1
                r -= 1

    return ''.join(s)


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the string
    s = data[0]
    # Read number of reversals
    M = int(data[1])
    # Read the reversal indices
    reversals = list(map(int, data[2:2 + M]))

    # Process and print the result
    result = process_reversals(s, reversals)
    print(result)


if __name__ == "__main__":
    main()
