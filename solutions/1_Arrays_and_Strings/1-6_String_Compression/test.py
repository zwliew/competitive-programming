from solution import solve

def test(t):
    data = [
        ('aabcccccaaa', 'a2b1c5a3'),
        ('abcdef', 'abcdef')
    ]

    for [test_string, expected] in data:
        actual = solve(test_string)
        t.assertEqual(actual, expected)
