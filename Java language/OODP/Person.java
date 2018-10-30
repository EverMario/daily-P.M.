public class Person {
    MaritalStatus ms;
    String name;

    Person(){
        ms = new MaritalStatus();
        name = "";
    }

    Person(String name, String st){
        this.ms = new MaritalStatus(st);
        this.name = name;
    }

    public void print(){
        System.out.println("Name : "+name);
        System.out.println("Matiral Status : " +ms.getStatus());

    }

    public void changeStatus(String st){
        ms.changeStatus(st);
    }
}
