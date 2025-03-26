public class PrimitiveDataTypes {
    // Instance variables to demonstrate default values
    int defaultInt;
    double defaultDouble;
    char defaultChar;
    boolean defaultBoolean;

    public static void main(String[] args) {
        // Declare and initialize variables of different primitive data types
        int intValue = 42;
        double doubleValue = 3.14159;
        char charValue = 'A';
        boolean booleanValue = true;

        // Print initialized values
        System.out.println("Initialized Values:");
        System.out.println("int value: " + intValue);
        System.out.println("double value: " + doubleValue);
        System.out.println("char value: " + charValue);
        System.out.println("boolean value: " + booleanValue);

        // Print default values using an object
        PrimitiveDataTypes obj = new PrimitiveDataTypes();
        System.out.println("\nDefault Values (for instance variables):");
        System.out.println("int default value: " + obj.defaultInt);
        System.out.println("double default value: " + obj.defaultDouble);
        System.out.println("char default value: [" + obj.defaultChar + "] (char default is empty or \u0000)");
        System.out.println("boolean default value: " + obj.defaultBoolean);
    }
}