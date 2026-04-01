fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        var K = readLine()!!.toInt()

        if (K == 1) {
            println("YES")
            println(1)
            println("*")
            println(".")
            return@repeat
        }

        when {
            K % 5 == 0 -> {
                val ans = 3 * (K / 5)
                println("YES")
                println(ans)
                println((0 until ans).joinToString("") { i -> if ((i - 1) % 3 == 0) "*" else "." })
                println(".".repeat(ans))
            }
            (K - 3) % 5 == 0 -> {
                K -= 3
                val ans = 3 * (K / 5) + 2
                println("YES")
                println(ans)
                println((0 until ans).joinToString("") { i -> if (i % 3 == 0) "*" else "." })
                println(".".repeat(ans))
            }
            (K - 6) % 5 == 0 -> {
                K -= 6
                val ans = 3 * (K / 5) + 4
                println("YES")
                println(ans)
                println((0 until ans).joinToString("") { i -> if (i % 3 == 0) "*" else "." })
                println(".".repeat(ans))
            }
            else -> {
                println("NO")
            }
        }
    }
}
