import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class VMTranslator {

    private static CodeWriter codeWriter;
    private static Parser parser;
    private String fileName;

    //constructor
    public VMTranslator(String inputFile){
        this.fileName = inputFile;
    }

    public void translate(){
        try{
            String outputFileName = fileName.substring(0, fileName.indexOf(".")) + ".asm";
            BufferedReader inputFile = new BufferedReader(new FileReader(fileName));
            codeWriter = new CodeWriter(outputFileName);
            String line;
            while ((line = inputFile.readLine()) != null) {
                parser = new Parser(line);
                switch (parser.commandType()) {
                    case C_PUSH:
                    case C_POP:
                        codeWriter.writePushPop(parser.commandType(), parser.arg1(), parser.arg2());
                        break;
                    case C_ARITHMETIC:
                        codeWriter.writeArithmetic(parser.arg1());
                        break;
                    case C_COMMENT:
                        break;
                }
            }
            inputFile.close();
            codeWriter.close();
        } catch (final IOException ioe) {
            System.out.println(ioe);
            return;
        }
    }
}