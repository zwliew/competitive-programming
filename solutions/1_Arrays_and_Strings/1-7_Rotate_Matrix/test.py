from solution import solve

'''
[a, b, c, d]
[e, f, g, h]
[i, j, k, l]
[m, n, o, p]

i = 0
[m, i, e, a]
[n, f, g, b]
[o, j, k, c]
[p, l, h, d]

i = 1
[m, i, e, a]
[n, j, f, b]
[o, k, g, c]
[p, l, h, d]
'''

'''
[21, 16, 11, 6, 1]
[22, 7, 8, 9, 2]
[23, 12, 13, 14, 3]
[24, 17, 18, 19, 4]
[25, 20, 15, 10, 5]

q: 5 10 15 20 25
q: 5, 24, 23, 22, 21
'''
def test(t):
    data = [
        ([
            [1, 2, 3, 4, 5],
            [6, 7, 8, 9, 10],
            [11, 12, 13, 14, 15],
            [16, 17, 18, 19, 20],
            [21, 22, 23, 24, 25]
        ], [
            [21, 16, 11, 6, 1],
            [22, 17, 12, 7, 2],
            [23, 18, 13, 8, 3],
            [24, 19, 14, 9, 4],
            [25, 20, 15, 10, 5]
        ])
    ]

    for [test_matrix, expected] in data:
        actual = solve(test_matrix)
        t.assertEqual(actual, expected)
