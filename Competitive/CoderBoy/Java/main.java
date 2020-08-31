import java.io.*;
import java.util.*;

public class main extends BaseC implements BaseI {
    public static void main(String[] args)throws Exception
    {
        System.setIn(new FileInputStream(new File("in.txt")));
        System.setOut(new PrintStream(new File("out.txt")));

        //Your logic goes here
    }
}
