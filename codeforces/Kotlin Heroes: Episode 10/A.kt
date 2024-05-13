// 做到签到题抽个奖

import java.util.Scanner
import kotlin.math.min

fun main() {
    val scanner = Scanner(System.`in`)
    val n = scanner.nextInt()
    repeat(n) {
        val input = scanner.nextInt()
        var mi = 100;
        for (i in 0..34) {
            for (j in 0..20) {
                val total = i*3+j*5
                if(total>input) break
                mi = min(mi,input-total)
            }
        }
        println(mi)
    }
}
