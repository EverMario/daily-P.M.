public class Client {
    public static void main(String[] args) {

        Singleton object1 = Singleton.getSingleton();
        Singleton object2 = Singleton.getSingleton();

        object1.showMessage();
        object2.showMessage();
    }
}
