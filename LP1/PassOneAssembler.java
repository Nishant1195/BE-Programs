import java.util.*;

class Symbol {
    String name; int addr;
    Symbol(String n, int a) { name = n; addr = a; }
    public String toString() { return name + "\t" + addr; }
}

public class PassOneAssembler {
    static Map<String,Integer> MOT = new HashMap<>();
    static Map<String,Integer> POT = new HashMap<>();
    static List<Symbol> SYMTAB = new ArrayList<>();

    public static void main(String[] args) {
        init();
        String code[] = {
            "START 100","LOOP MOV AREG,NUM","ADD AREG,ONE","SUB AREG,TWO",
            "MOV RESULT,AREG","NUM DS 1","ONE DC 1","TWO DC 2",
            "RESULT DS 1","END"
        };
        passOne(code);
    }

    static void init() {
        MOT.put("MOV",1); MOT.put("ADD",2); MOT.put("SUB",3);
        POT.put("START",1); POT.put("END",2); POT.put("DS",3); POT.put("DC",4);
    }

    static void passOne(String[] p) {
        int LC = 0;
        System.out.println("---- PASS-I ----");
        
        for (String line : p) {
            String parts[] = line.split("\\s+");
            String label = "", op = parts[0], opd = "";
            if (parts.length > 1) opd = parts[1];
            if (parts.length == 3) { label = parts[0]; op = parts[1]; opd = parts[2]; }

            if (op.equals("START")) { LC = Integer.parseInt(opd); continue; }
            if (!label.isEmpty()) SYMTAB.add(new Symbol(label, LC));

            if (op.equals("DS")) LC += Integer.parseInt(opd);
            else if (op.equals("DC")) LC++;
            else if (op.equals("END")) break;
            else if (MOT.containsKey(op)) LC++;
            else System.out.println("Invalid opcode: " + op);
        }

        System.out.println("\n-- SYMBOL TABLE --");
        System.out.println("Symbol\tAddress");
        SYMTAB.forEach(System.out::println);
    }
}