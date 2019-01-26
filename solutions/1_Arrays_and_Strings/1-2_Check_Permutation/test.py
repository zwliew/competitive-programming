from solution import solve

def test(t):
    dataT = (
        ('abcd', 'bacd'),
        ('3563476', '7334566'),
        ('wef34f', 'wffe34'),
    )
    dataF = (
        ('abcd', 'd2cba'),
        ('2354', '1234'),
        ('dcw4f', 'dcw5f'),
    )

    for test_strings in dataT:
        result = solve(*test_strings)
        t.assertTrue(result)

    for test_strings in dataF:
        result = solve(*test_strings)
        t.assertFalse(result)
