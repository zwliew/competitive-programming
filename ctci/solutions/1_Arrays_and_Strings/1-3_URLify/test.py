from solution import solve

def test(t):
    data = [
        (list('much ado about nothing      '), 22,
         list('much%20ado%20about%20nothing')),
        (list('Mr John Smith    '), 13, list('Mr%20John%20Smith'))
    ]

    for [test_string, length, expected] in data:
        actual = solve(test_string, length)
        t.assertEqual(actual, expected)
