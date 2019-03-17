# CTCI Notes

## General
- Is there a recursive way to define a category? For example, all the permutations of the string 'ABC' can be defined as all the permutations of the substring 'AB' with the character 'C' inserted at each possible position of each permutation.

## Chapter 1 - Arrays and String

### 1.1 Is Unique
- When keeping memory of keys to values is needed, a hash table/hash map, a set, a bit vector, or even a bit field may be the tool for the job. Use cases include mapping keys to counters and mapping keys to lists of items.
- Sets, and bit vectors are useful mainly for keeping track of presence of keys or boolean states of keys - for example, on/off, present/absent, or even/odd. On the other hand, hash tables are useful for keeping track of any other mappings.
- If no extra space can be used due to constraints, sorting an array in-place can be an option. However, this brings the minimum time complexity of the algorithm to O(NlogN).
- If no other options can be thought of, brute search is always a fallback.
- Usually, a faster solution can be attained by sacrificing some space. For example, a hash table can be used instead of sorting or brute searching.

### 1.2 Check Permutation
- When checking whether a given input can be put under a specific category, start with a definition of the category. Can the input be checked against that definition? For example, a String is a permutation of another String when both Strings have the same length and same number of occurences for each character.

### 1.3 URLify
- It is easier to edit a string in-place from the back (with a buffer when extra characters are needed).

### 1.4 Palindrome Permutation
- Sometimes, it is unfeasible to generate all possible options and check the input against them. This is especially true for O(N!) time cases like generating permutations.

### 1.5 One Away
- Identify separate cases which can be individually checked for based on some conditions.
- Even then, can checks for separate cases be merged and done in 1 pass?

### 1.6 String Compression
- It is inefficient to naively concatenate strings (i.e. str3 = str1 + str2). Instead, construct a list and append strings to it before joining the elements in the list to a string (similar to a StringBuilder).
- For certain input cases, doing some extra work upfront for preliminary checking and short-circuiting can reduce the runtime of the algorithm.

### 1.7 Rotate Matrix
- Rotate multiple values by keeping 1 value in a temporary variable and overwriting the values in backwards order.

### 1.8 Zero Matrix
- Rather than using extra memory for storing data, can the input be repurposed to store the data instead? This saves space but may negatively impact runtime.

### 1.9 String Rotation
- Rotating an array/string means that it is split into two parts, x and y, such that the input is xy and the output is yx
- Checking if an s2 is a rotation of s1 is simply checking if len(s1) == len(s2) and if s1 is a substring of s2 + s2

## Chapter 2 - Linked Lists

### 2.1 Remove Dups
- A runner pointer that 'runs ahead' of the current pointer can be used to look ahead when traversing linked lists. This is useful when searching for nodes with specific data or specific types of nodes, but still keeping track of the current node (possibly to find a relation between the 2 nodes).
- A pointer to the previous node may not be necessary when deleting a node from a linked list depending on how the current node is being tracked.

### 2.2 Return Kth to Last
