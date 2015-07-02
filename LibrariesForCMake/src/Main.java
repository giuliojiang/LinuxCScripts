import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner input = new Scanner(new File("list.txt"));
		
		PrintStream out = System.out;
		
		while (input.hasNext())
		{
			String temp = input.nextLine();
			out.print("\"${LLVM_LIBDIR}/" + temp + "\" ");
		}
	}

}
