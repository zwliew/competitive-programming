from solution import solve

def test(t):
    data = [
        ('waterbottle', 'erbottlewat', True),
        ('foo', 'bar', False),
        ('foo', 'foofoo', False)
    ]


    for [s1, s2, expected] in data:
        actual = solve(s1, s2)
        t.assertEqual(actual, expected)
