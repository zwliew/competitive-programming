import unittest
import test
import timeit

class Test(unittest.TestCase):
    def test(self):
        global t
        t = self
        print(timeit.timeit('test.test(t)', globals=globals()))

if __name__ == '__main__':
    unittest.main()
