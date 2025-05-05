package Java;

import java.util.Scanner;

public class Io {
    public static void main(String[] args) {
        
        Scanner sc= new Scanner(System.in);

        int i= sc.nextInt();
        float f=sc.nextFloat();
        char c=sc.next().charAt(0);
        
        System.out.println("Printing");
        System.out.printf("Int=%d",i);
        System.out.printf("Float=%f",f);
        System.out.printf("Char=%c",c);

        sc.close();
    }
    
}
