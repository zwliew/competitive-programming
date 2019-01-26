# Printing all permutations of a given string
# 2 similar approaches
# Input == a string, Output == a list of permutations of the string
# O(N^2 * N!) time?
# N == len(S)

def get_permutations(S):
    N = len(S)
    if N == 1:
        return [S]

    permutations = []

    # Extract a character from each position in string S
    # and insert it at the front of each permutation of the
    # remaining substring
    for i in range(N):
        ch = S[i]
        remainder = S[:i] + S[i + 1:]
        for permutation in get_permutations(remainder):
            permutations.append(ch + permutation)
    return permutations

def get_permutations2(S):
    N = len(S)
    if N == 1:
        return [S]

    permutations = []

    # Extract the first character of string S
    # and insert it at each position of the each permutation
    # of the remaining substring
    for permutation in get_permutations2(S[1:]):
        for i in range(len(permutation) + 1):
            permutations.append(permutation[:i] + S[0] + permutation[i:])
    return permutations

def print_permutations(S):
    permutations = get_permutations(S)
    print(len(permutations))
    for s in permutations:
        print(s)

if __name__ == '__main__':
    print_permutations('abcd')
