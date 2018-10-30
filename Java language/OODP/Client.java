import java.util.Scanner;

public class Client {
    public static void main(String[] args){
        System.out.println("Please add a person:");
        System.out.println("Name:");
        Scanner scan1 = new Scanner(System.in);
        String name = scan1.nextLine();
        System.out.println("Status:");
        Scanner scan2 = new Scanner(System.in);
        String status = scan2.nextLine();

        Person person =new Person(name, status);
        person.print();

        System.out.println("Please enter a new status:");
        Scanner scan3 = new Scanner(System.in);
        String st = scan3.nextLine();
        person.changeStatus(st);

        System.out.println("After the status is changed...");
        person.print();
    }
}
