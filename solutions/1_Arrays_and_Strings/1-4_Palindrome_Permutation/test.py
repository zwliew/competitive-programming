from solution import solve

def test(t):
    data = [
        ('Tact Coa', True),
        ('jhsabckuj ahjsbckj', True),
        ('Able was I ere I saw Elba', True),
        ('So patient a nurse to nurse a patient so', False),
        ('Random Words', False),
        ('Not a Palindrome', False),
        ('no x in nixon', True),
        ('azAZ', True)
    ]

    for [test_string, expected] in data:
        actual = solve(test_string)
        t.assertEqual(actual, expected)
