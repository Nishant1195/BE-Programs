import java.util.*;

// Class to represent Macro Name Table entry
class MNTEntry {
    String name;
    int mdtIndex;

    MNTEntry(String name, int mdtIndex) {
        this.name = name;
        this.mdtIndex = mdtIndex;
    }

    @Override
    public String toString() {
        return name + "\t" + mdtIndex;
    }
}

// Main Macro Processor Pass-I
public class MacroProcessorPass1 {
    static List<MNTEntry> MNT = new ArrayList<>();
    static List<String> MDT = new ArrayList<>();
    static Map<String, Integer> ALA = new LinkedHashMap<>();

    public static void main(String[] args) {
        // Sample input assembly program with macros
        String program[] = {
            "MACRO",
            "INCR &ARG1, &ARG2",
            "ADD &ARG1, &ARG2",
            "MEND",
            "START",
            "MOV AREG, NUM",
            "INCR AREG, ONE",
            "END"
        };

        processMacros(program);
    }

    static void processMacros(String[] program) {
        boolean inMacroDef = false;
        int mdtIndex = 0;

        for (int i = 0; i < program.length; i++) {
            String line = program[i].trim();
            String[] parts = line.split("\\s+|,\\s*");

            if (line.equalsIgnoreCase("MACRO")) {
                inMacroDef = true;
                continue;
            }

            if (inMacroDef) {
                // First line after MACRO -> macro prototype
                String macroName = parts[0];
                MNT.add(new MNTEntry(macroName, MDT.size() + 1)); // store macro name and MDT index

                // Build ALA (Argument List Array)
                ALA.clear();
                for (int j = 1; j < parts.length; j++) {
                    if (parts[j].startsWith("&")) {
                        ALA.put(parts[j], ALA.size() + 1);
                    }
                }

                // Now read the body until MEND
                i++;
                while (!program[i].trim().equalsIgnoreCase("MEND")) {
                    String bodyLine = program[i].trim();

                    // Replace arguments with positional notation (#1, #2, etc.)
                    for (Map.Entry<String, Integer> entry : ALA.entrySet()) {
                        bodyLine = bodyLine.replace(entry.getKey(), "#" + entry.getValue());
                    }

                    MDT.add(bodyLine);
                    i++;
                }

                MDT.add("MEND"); // add MEND to MDT
                inMacroDef = false;
                continue;
            }
        }

        // Print tables
        printTables();
    }

    static void printTables() {
        System.out.println("----- MACRO NAME TABLE (MNT) -----");
        System.out.println("Name\tMDT Index");
        for (MNTEntry e : MNT) {
            System.out.println(e);
        }

        System.out.println("\n----- MACRO DEFINITION TABLE (MDT) -----");
        int index = 1;
        for (String s : MDT) {
            System.out.println(index++ + "\t" + s);
        }

        System.out.println("\n----- ARGUMENT LIST ARRAY (ALA) -----");
        for (Map.Entry<String, Integer> e : ALA.entrySet()) {
            System.out.println(e.getKey() + " -> #" + e.getValue());
        }
    }
}