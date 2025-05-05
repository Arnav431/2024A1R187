package Java;

public class Operators{
    public static void main(String[] args) {
        int a = 10;
        int b= 20;

        // Arithatic operators --> + - * / %
        System.out.println("Arithmatic Operators");
        System.out.println(a+b);
        System.out.println(a-b);
        System.out.println(a*b);
        System.out.println(a/b);
        System.out.println(a%b);

        // Urinary Operators --> ++a a++ --a a--
        System.out.println("Urinary Operators");
        System.out.println(a++);
        System.out.println(++a);
        System.out.println(b--);
        System.out.println(--b);

        boolean bo= true;
        System.out.println(!bo);

        // relational operator --> == != < > <= >=
        System.out.println(a=b);
        System.out.println(a!=b);
        System.out.println(a>=b);
        System.out.println(a<=b);
        System.out.println(a>b);
        System.out.println(a<b);

        // Logical Operators --> AND(&&) , OR(||)
        System.out.println("Logical Operators");
        System.out.println(true && true);
        System.out.println(true && false);
        //System.out.println(true || false);
        //System.out.println(true || true);

        // ternary operator --> (condition) ? true : false
        a=10;
        b=20;
        int result = (a == b) ? 1 : 0;
        System.out.println(result);  
    }
}