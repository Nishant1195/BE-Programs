import java.util.*;

class MacroProcessorPass1 {
    Map<String, Integer> MNT = new LinkedHashMap<>();
    List<String> MDT = new ArrayList<>();
    List<String> intermediate = new ArrayList<>();

    void pass1(String[] code) {
        boolean inMacro = false;
        String macroName = "";
        int mdtPtr = 0;

        for (String line : code) {
            line = line.trim();

            if (line.equals("MACRO")) {         // macro starts
                inMacro = true;
                continue;
            }

            if (inMacro) {
                if (macroName.equals("")) {
                    // first line of macro -> macro name
                    macroName = line.split("\\s+")[0];
                    MNT.put(macroName, mdtPtr);
                } else if (line.equals("MEND")) {
                    MDT.add("MEND");
                    mdtPtr++;
                    inMacro = false;
                    macroName = "";
                } else {
                    MDT.add(line);  // store macro body
                    mdtPtr++;
                }
            } else {
                // outside macro → intermediate code
                intermediate.add(line);
            }
        }
    }

    void printTables() {
        System.out.println("\nMNT (Macro Name Table)");
        System.out.println("----------------------");
        MNT.forEach((k, v) -> System.out.println(k + " -> MDT[" + v + "]"));

        System.out.println("\nMDT (Macro Definition Table)");
        System.out.println("---------------------------");
        for (int i = 0; i < MDT.size(); i++) {
            System.out.println(i + " : " + MDT.get(i));
        }

        System.out.println("\nIntermediate Code");
        System.out.println("------------------");
        intermediate.forEach(System.out::println);
    }
}

public class Main {
    public static void main(String[] args) {
        String program[] = {
            "MACRO",
            "INCR A,B",
            "ADD A,B",
            "MEND",
            "START",
            "INCR X,Y",
            "END"
        };

        MacroProcessorPass1 mp = new MacroProcessorPass1();
        mp.pass1(program);
        mp.printTables();
    }
}