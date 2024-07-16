import java.io.*;
import java.util.*;

public class Assembler {

    private final SymbolTable symbols; //stores symbols and labels
    private int countLine; //count line
    private Parser parser; //parse into segments

    //constructor
    public Assembler() {
        symbols = new SymbolTable();
        countLine = 0;
    }

    public void preAssemble(String filename) {
        try {
            final BufferedReader input = new BufferedReader(new FileReader(filename));
            boolean parseCheck;
            String line;

            while ((line = input.readLine()) != null) {
                parser = new Parser();
                parseCheck = parser.parseCheck(line);

                if (parseCheck) {
                    if (line.trim().charAt(0) == '(') { 
                        //extract label symbol
                        String symbol = line.trim().substring(line.indexOf("(") + 1, line.lastIndexOf(")"));

                        if (!symbols.contains(symbol))
                            symbols.put(symbol, countLine);

                        countLine--; //dont count labels
                    }
                    countLine++; //only count true lines
                }
            }
            input.close();
        } catch (final IOException ioe) {
            System.out.println(ioe);
            return;
        }
    }

    public void assemble(String filename) {
        
        try {
            //change file from .asm to .hack
            String outputFilename = filename.substring(0, filename.indexOf(".")) + ".hack";
            BufferedReader input = new BufferedReader(new FileReader(filename));
            PrintWriter output = new PrintWriter(outputFilename);

            countLine = 0;
            boolean parseCheck;
            String line;

            while ((line = input.readLine()) != null) {
                parser = new Parser();
                parseCheck = parser.parseCheck(line);

                if (parseCheck && line.trim().charAt(0) != '(') {
                    //C-instruction
                    if (parser.bit() == null) { 
                        String comp = Code.getCompCode(parser.comp());
                        String dest = Code.getDestCode(parser.dest());
                        String jump = Code.getJumpCode(parser.jump());
                        output.printf("111%s%s%s\n", comp, dest, jump);
                    } 
                    //A-instruction
                    else { 
                        String var = parser.bit();

                        Scanner sc = new Scanner(var);
                        if (sc.hasNextInt()) { 
                            String bit = Integer.toBinaryString(Integer.parseInt(var));
                            //write 16-bit to output
                            output.println(checkBit(bit));
                        } else {
                            symbols.addVariable(var);
                            final String bit = Integer.toBinaryString(symbols.get(var));
                            output.println(checkBit(bit));
                        }
                        sc.close();
                    }
                    countLine++;
                }
            }
            input.close();
            output.close();
        } catch (final IOException ioe) {
            System.out.println(ioe);
            return;
        }
    }

    //adds 0's as needed
    private String checkBit(String bit) {
        String addZeros = "";
        int zerosNeeded = 16 - bit.length();

        //add needed 0's to complete bit length
        for (int i = 0; i < zerosNeeded; i++) {
            addZeros += "0";
        }

        return addZeros + bit;
    }
}