package Java;
import java.util.Scanner;

public class Methods {
    private static int sum(int n1, int n2){
        return n1+n2;
    }

    public static void main(String[] arg){

        Scanner sc= new Scanner(System.in);
        
        int i1 = sc.nextInt();
        int i2 = sc.nextInt();
        
        System.out.printf("%d + %d = %d", i1,i2,sum(i1, i2) );
        sc.close();
    }
}
