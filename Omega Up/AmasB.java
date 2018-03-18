import java.io.*;
import java.util.*;

public class AmasB{

	private static BufferedReader stdIn = new BufferedReader
					(new InputStreamReader(System.in));

	public static void main(String [] args) throws IOException{

		int n;
		String num;
		int ans = 0;
		String [] arr;

		n = Integer.parseInt(stdIn.readLine());

		for(int i = 1; i <= n;i++){
			num = stdIn.readLine();
			arr = num.split("\\.");
			ans += Integer.parseInt(arr[1]);
		}

		System.out.println(ans);

	}
}