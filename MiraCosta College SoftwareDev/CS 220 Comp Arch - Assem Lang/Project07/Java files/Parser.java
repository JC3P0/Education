public class Parser {
    
    private String currentLine;
    private String currentCommand;

    //constructor
    public Parser(String line) {
        this.currentLine = line;
    }

    public CommandType commandType() {
        currentCommand = currentLine;
        //only gathers info before the space " "
        String command = currentCommand.split(" ")[0];

        //return command types
        if (currentCommand.contains("/")){
            return CommandType.C_COMMENT;
        }
        switch (command) {
            case "push":
                return CommandType.C_PUSH;
            case "pop":
                return CommandType.C_POP;
            default:
                return CommandType.C_ARITHMETIC;
        }
    }

    public String arg1() {
        if (commandType() == CommandType.C_ARITHMETIC) {
            return currentCommand;
        }
        return currentCommand.split(" ")[1];
    }

    //returns index value
    public int arg2() {
        if (commandType() == CommandType.C_PUSH
                || commandType() == CommandType.C_POP
                || commandType() == CommandType.C_FUNCTION
                || commandType() == CommandType.C_CALL) {
            return Integer.valueOf(currentCommand.split(" ")[2]);
        }
        return 0;
    }
}