import java.util.*;

public class pass2 {
    static Map<String,Integer> MOT = new HashMap<>();
    static Map<String,Integer> SYMTAB = new HashMap<>();

    public static void main(String[] args) {
        MOT.put("MOV",1); MOT.put("ADD",2); MOT.put("SUB",3);
        SYMTAB.put("LOOP",100); SYMTAB.put("NUM",104);
        SYMTAB.put("ONE",105); SYMTAB.put("TWO",106);
        SYMTAB.put("RESULT",108);

        String code[] = {
            "MOV AREG, NUM",
            "ADD AREG, ONE",
            "SUB AREG, TWO",
            "MOV RESULT, AREG"
        };

        System.out.println("---- PASS-II (Machine Code) ----");
        for(String line : code) {

            line = line.replace(",", "").trim();
            String p[] = line.split("\\s+");

            String op = p[0];
            String r = (p.length > 1) ? p[1] : "";
            String s = (p.length > 2) ? p[2] : "";

            int opc = MOT.getOrDefault(op, 0);
            int reg = getReg(r);
            int addr = SYMTAB.getOrDefault(s, 0);

            System.out.println(opc + " " + reg + " " + addr);
        }
    }

    static int getReg(String r) {
        if (r == null) return 0;
        switch (r) {
            case "AREG": return 1;
            case "BREG": return 2;
            case "CREG": return 3;
            case "DREG": return 4;
            default: return 0;
        }
    }
}