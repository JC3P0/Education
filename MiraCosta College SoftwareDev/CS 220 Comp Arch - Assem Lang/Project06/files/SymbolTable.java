import java.util.Hashtable;

public class SymbolTable {
    
    private int countRegister;
    private final Hashtable<String, Integer> symbolTable;

    //constructor
    public SymbolTable() {
        countRegister = 16;
        symbolTable = new Hashtable<String, Integer>(25);

        //initialize pre-defined variables
        for (int i = 0; i <= 15; i++) {
            final String key = "R" + i;
            symbolTable.put(key, i);
        }

        symbolTable.put("SCREEN", 16384);
        symbolTable.put("KBD", 24576);
        symbolTable.put("SP", 0);
        symbolTable.put("LCL", 1);
        symbolTable.put("ARG", 2);
        symbolTable.put("THIS", 3);
        symbolTable.put("THAT", 4);
    }

    public boolean addVariable(final String symbol) {
        if (!symbolTable.containsKey(symbol)) {
            symbolTable.put(symbol, countRegister);
            countRegister++;
            return true;
        }
        return false;
    }

     public void put(final String symbol, final int value) {
        symbolTable.put(symbol, value);
    }

    public boolean contains(final String symbol) {
        return symbolTable.containsKey(symbol);
    }

    public int get(final String symbol) {
        return symbolTable.get(symbol);
    }
}