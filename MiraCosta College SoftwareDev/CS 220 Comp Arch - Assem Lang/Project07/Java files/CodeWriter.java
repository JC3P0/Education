import java.io.IOException;
import java.io.PrintWriter;

public class CodeWriter {

    private PrintWriter output;
    private final String fileName;

    private int labelCount = 0;

    //constructor
    public CodeWriter(String outputFileName) {
        output = null;
        fileName = outputFileName;
        try {
            PrintWriter outputFile = new PrintWriter(outputFileName);
            output = new PrintWriter(outputFile);
        } catch (final IOException ioe) {
            System.out.println(ioe);
            return;
        }
    }

    public void writePushPop(CommandType commandType, String segment, int index) {
        switch (commandType) {
            case C_PUSH:
                output.printf("// push %s %d\n", segment, index);
                switch (segment) {
                    case "constant":
                        output.println("@"+index);
                        output.println("D=A");
                        break;
                    case "local":
                        loadSegment("LCL", index);
                        output.println("D=M");
                        break;
                    case "argument":
                        loadSegment("ARG", index);
                        output.println("D=M");
                        break;
                    case "this":
                        loadSegment("THIS", index);
                        output.println("D=M");
                        break;
                    case "that":
                        loadSegment("THAT", index);
                        output.println("D=M");
                        break;
                    case "pointer":
                        output.println("@R"+ String.valueOf(3 + index));
                        output.println("D=M");
                        break;
                    case "temp":
                        output.println("@R"+ String.valueOf(5 + index));
                        output.println("D=M");
                        break;
                    case "static":
                        output.println("@"+ fileName.split("\\.")[0]+String.valueOf(index));
                        output.println("D=M");
                }
                pushDToStack();
                break;
            case C_POP:
                output.printf("// pop %s %d\n", segment, index);
                switch (segment) {
                    case "constant":
                        output.println("@"+index);
                        break;
                    case "local":
                        loadSegment("LCL", index);
                        break;
                    case "argument":
                        loadSegment("ARG", index);
                        break;
                    case "this":
                        loadSegment("THIS", index);
                        break;
                    case "that":
                        loadSegment("THAT", index);
                        break;
                    case "pointer":
                        output.println("@R"+ String.valueOf(3 + index));
                        break;
                    case "temp":
                        output.println("@R"+ String.valueOf(5 + index));
                        break;
                    case "static":
                        output.println("@"+ fileName.split("\\.")[0]+String.valueOf(index));
                        break;
                }
                output.println("D=A");
                output.println("@R13");
                output.println("M=D");
                popStackToD();
                output.println("@R13");
                output.println("A=M");
                output.println("M=D");
                break;
        }
    }

    public void writeArithmetic(String command) {
        output.printf("// %s\n", command);
        switch (command) {
            case "add":
                popStackToD();
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=D+M");
                incrementStackPointer();
                break;
            case "sub":
                popStackToD();
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=M-D");
                incrementStackPointer();
                break;
            case "neg":
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=-M");
                incrementStackPointer();
                break;
            case "eq":
                writeCompareLogic("JEQ");
                break;
            case "gt":
                writeCompareLogic("JGT");
                break;
            case "lt":
                writeCompareLogic("JLT");
                break;
            case "and":
                popStackToD();
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=D&M");
                incrementStackPointer();
                break;
            case "or":
                popStackToD();
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=D|M");
                incrementStackPointer();
                break;
            case "not":
                decrementStackPointer();
                loadStackPointerToA();
                output.println("M=!M");
                incrementStackPointer();
                break;
        }
    }

    private void incrementStackPointer() {
        output.println("@SP");
        output.println("M=M+1");
    }

    private void decrementStackPointer() {
        output.println("@SP");
        output.println("M=M-1");
    }

    private void popStackToD() {
        decrementStackPointer();
        output.println("A=M");
        output.println("D=M");
    }

    private void pushDToStack() {
        loadStackPointerToA();
        output.println("M=D");
        incrementStackPointer();
    }

    private void loadStackPointerToA() {
        output.println("@SP");
        output.println("A=M");
    }

    private void writeCompareLogic(String jumpCommand) {
        popStackToD();
        decrementStackPointer();
        loadStackPointerToA();
        output.println("D=M-D");
        output.println("@LABEL" + labelCount);
        output.println("D;"+jumpCommand);
        loadStackPointerToA();
        output.println("M=0");
        output.println("@ENDLABEL" + labelCount);
        output.println("0;JMP");
        output.println("(LABEL" + labelCount + ")");
        loadStackPointerToA();
        output.println("M=-1");
        output.println("(ENDLABEL" + labelCount + ")");
        incrementStackPointer();
        labelCount++;
    }

    private void loadSegment(String segment, int index) {
        output.println("@" + segment);
        output.println("D=M");
        output.println("@"+String.valueOf(index));
        output.println("A=D+A");
    }
    
    public void close() {
        output.close();
    }
}