from solution import solve

def test(t):
    dataT = [('abcd'), ('s4fad'), ('')]
    dataF = [('23ds2'), ('hb 627jh=j ()')]

    for test_string in dataT:
        actual = solve(test_string)
        t.assertTrue(actual)

    for test_string in dataF:
        actual = solve(test_string)
        t.assertFalse(actual)
