'''
 https://techdevguide.withgoogle.com/paths/foundational/interpreter-problems-for-python/#!

 Write a simple interpreter which understands "+", "-", and "*" operations.
 Apply the operations in order using command/arg pairs starting with the
 initial value of `value`. If you encounter an unknown command, return -1.

 interpret(1, ["+"], [1]) → 2
 interpret(4, ["-"], [2]) → 2
 interpret(1, ["+", "*"], [1, 3]) → 6
'''
def main():
    print(interpret(1, ['+'], [1]))
    print(interpret(4, ['-'], [2]))
    print(interpret(1, ['+', '*'], [1, 3]))

def interpret(value, commands, args):
    for i in range(len(commands)):
        if commands[i] == '+':
            value += args[i]
        elif commands[i] == '-':
            value -= args[i]
        elif commands[i] == '*':
            value *= args[i]
        else:
            return -1
    return value
        
main()