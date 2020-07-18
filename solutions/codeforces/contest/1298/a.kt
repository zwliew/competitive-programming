private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
fun main() {
  var (ab, ac, bc, abc) = readInts()
  if (ab > abc) {
    var t = ab
    ab = abc
    abc = t
  } else if (ac > abc) {
    var t = ac
    ac = abc
    abc = t
  } else if (bc > abc) {
    var t = bc
    bc = abc
    abc = t
  }
  print(abc - bc)
  print(" ")
  print(abc - ac)
  print(" ")
  print(abc - ab)
}
