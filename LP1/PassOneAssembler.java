import java.util.*;

// Class to store symbol information
class Symbol {
    String name;
    int address;

    Symbol(String name, int address) {
        this.name = name;
        this.address = address;
    }

    public String toString() {
        return name + "\t" + address;
    }
}

// Class to store intermediate code lines
class IntermediateCode {
    String code;
    IntermediateCode(String c) {
         code = c;
          }
    public String toString() {
         return code; 
         
}

// Main Assembler Pass-I
public class PassOneAssembler {
    static Map<String, Integer> MOT = new HashMap<>();
    static Map<String, Integer> POT = new HashMap<>();
    static List<Symbol> symbolTable = new ArrayList<>();
    static List<IntermediateCode> intermediate = new ArrayList<>();

    public static void main(String[] args) {
        initTables();

        String[] program = {
            "START 100",
            "LOOP MOV AREG, NUM",
            "ADD AREG, ONE",
            "SUB AREG, TWO",
            "MOV RESULT, AREG",
            "NUM DS 1",
            "ONE DC 1",
            "TWO DC 2",
            "RESULT DS 1",
            "END"
        };

        passOne(program);
    }

    static void initTables() {
        MOT.put("MOV", 1);
        MOT.put("ADD", 2);
        MOT.put("SUB", 3);

        POT.put("START", 1);
        POT.put("END", 2);
        POT.put("DS", 3);
        POT.put("DC", 4);
    }

    static void passOne(String[] code) {
        int LC = 0;
        System.out.println("----- PASS-I OUTPUT -----");

        for (String line : code) {
            line = line.trim();
            if (line.isEmpty()) continue;

            String label = "", opcode = "", operand = "";
            String[] parts = line.split("\\s+", 2);

            // Detect label if first token not an opcode/directive
            if (parts.length == 2 && !MOT.containsKey(parts[0]) && !POT.containsKey(parts[0])) {
                label = parts[0];
                line = parts[1];
            }

            // Extract opcode and operand
            parts = line.split("\\s+", 2);
            opcode = parts[0];
            operand = (parts.length > 1) ? parts[1].replace(",", "") : "";

            if (opcode.equals("START")) {
                LC = Integer.parseInt(operand);
                System.out.println("Program starts at address: " + LC);
                intermediate.add(new IntermediateCode("(AD, START) (C, " + operand + ")"));
                continue;
            }

            if (!label.isEmpty()) symbolTable.add(new Symbol(label, LC));

            if (MOT.containsKey(opcode)) {
                intermediate.add(new IntermediateCode("(IS, " + MOT.get(opcode) + ") (" + operand + ")"));
                LC++;
            } else if (POT.containsKey(opcode)) {
                switch (opcode) {
                    case "DS":
                        intermediate.add(new IntermediateCode("(DL, DS) (C, " + operand + ")"));
                        LC += Integer.parseInt(operand);
                        break;
                    case "DC":
                        intermediate.add(new IntermediateCode("(DL, DC) (C, " + operand + ")"));
                        LC++;
                        break;
                    case "END":
                        intermediate.add(new IntermediateCode("(AD, END)"));
                        break;
                }
            } else {
                System.out.println("Error: Invalid opcode " + opcode);
            }
        }

        // Print Symbol Table
        System.out.println("\n----- SYMBOL TABLE -----");
        System.out.println("Symbol\tAddress");
        for (Symbol s : symbolTable) {
            System.out.println(s);
        }

        // Print Intermediate Code
        System.out.println("\n----- INTERMEDIATE CODE -----");
        for (IntermediateCode ic : intermediate) {
            System.out.println(ic);
        }
    }
}