import java.util.*;

// Class for MNT entries
class MNTEntry {
    String name;
    int mdtIndex;

    MNTEntry(String name, int mdtIndex) {
        this.name = name;
        this.mdtIndex = mdtIndex;
    }
}

// Main Pass-II Processor
public class MacroProcessorPass2 {
    static List<MNTEntry> MNT = new ArrayList<>();
    static List<String> MDT = new ArrayList<>();

    public static void main(String[] args) {
        // Step 1: Initialize MNT and MDT (normally read from Pass-I files)
        initTables();

        // Step 2: Intermediate program without macro definitions
        String[] program = {
            "START",
            "MOV AREG, NUM",
            "INCR AREG, ONE",
            "END"
        };

        // Step 3: Process program for macro expansion
        expandMacros(program);
    }

    static void initTables() {
        // Example MNT (Macro Name Table)
        MNT.add(new MNTEntry("INCR", 1));

        // Example MDT (Macro Definition Table)
        MDT.add("ADD #1, #2");
        MDT.add("MEND");
    }

    static void expandMacros(String[] program) {
        System.out.println("----- PASS-II OUTPUT (Expanded Code) -----");

        for (String line : program) {
            String[] parts = line.trim().split("\\s+|,\\s*");
            String name = parts[0];

            // Check if the line is a macro call
            if (isMacro(name)) {
                MNTEntry mntEntry = getMNTEntry(name);
                int mdtIndex = mntEntry.mdtIndex - 1; // MDT is 0-indexed

                // Build ALA for actual arguments
                Map<String, String> ALA = new HashMap<>();
                for (int i = 1; i < parts.length; i++) {
                    ALA.put("#" + i, parts[i]); // #1=Areg, #2=ONE
                }

                // Expand using MDT
                while (!MDT.get(mdtIndex).equalsIgnoreCase("MEND")) {
                    String expandedLine = MDT.get(mdtIndex);
                    for (Map.Entry<String, String> e : ALA.entrySet()) {
                        expandedLine = expandedLine.replace(e.getKey(), e.getValue());
                    }
                    System.out.println(expandedLine);
                    mdtIndex++;
                }
            } else {
                // Normal assembly line → copy as is
                System.out.println(line);
            }
        }
    }

    static boolean isMacro(String name) {
        for (MNTEntry e : MNT) {
            if (e.name.equalsIgnoreCase(name))
                return true;
        }
        return false;
    }

    static MNTEntry getMNTEntry(String name) {
        for (MNTEntry e : MNT) {
            if (e.name.equalsIgnoreCase(name))
                return e;
        }
        return null;
    }
}