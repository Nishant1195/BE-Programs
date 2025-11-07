import java.lang.reflect.Method;

// Simulated "Dynamic Link Library" class
class MathLibrary {
    public int add(int a, int b) { return a + b; }
    public int sub(int a, int b) { return a - b; }
    public int mul(int a, int b) { return a * b; }
    public double div(int a, int b) {
        if (b == 0) throw new ArithmeticException("Division by zero");
        return (double) a / b;
    }
}

// Application program that dynamically loads the above "library"
public class DynamicMathLoader {
    public static void main(String[] args) {
        try {
            // Simulate DLL loading using reflection
            Class<?> mathClass = Class.forName("MathLibrary");
            Object mathInstance = mathClass.getDeclaredConstructor().newInstance();

            // Use reflection to call its methods dynamically
            Method add = mathClass.getMethod("add", int.class, int.class);
            Method sub = mathClass.getMethod("sub", int.class, int.class);
            Method mul = mathClass.getMethod("mul", int.class, int.class);
            Method div = mathClass.getMethod("div", int.class, int.class);

            int a = 12, b = 4;

            System.out.println("Dynamically Loaded Math Operations:");
            System.out.println("add(" + a + "," + b + ") = " + add.invoke(mathInstance, a, b));
            System.out.println("sub(" + a + "," + b + ") = " + sub.invoke(mathInstance, a, b));
            System.out.println("mul(" + a + "," + b + ") = " + mul.invoke(mathInstance, a, b));
            System.out.println("div(" + a + "," + b + ") = " + div.invoke(mathInstance, a, b));

            // Demonstrate error handling
            try {
                System.out.println("div(" + a + ",0) = " + div.invoke(mathInstance, a, 0));
            } catch (Exception e) {
                System.out.println("Error: " + e.getCause().getMessage());
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
