import java.io.*
import java.util.*

fun  main (args: Array<String>)
{
    System.setIn(FileInputStream(File("in.txt")))
    System.setOut(PrintStream(File("out.txt")))
    println("Hello World")
}
