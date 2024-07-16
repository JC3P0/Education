public class Parser {
    private String dest; //destination instruction
    private String comp; //computation instruction
    private String jump; //jump instruction
    private String bit; //16-bit address

    //constructor
    public Parser() {
        dest = "null";
        jump = "null";
    }

    public boolean parseCheck(String line) {
        //remove whitespace before and after line
        line = line.trim();

        //validate if line is empty
        if (!line.isEmpty()) {
            //validate if line is a comment
            if (line.charAt(0) != '/') {
                //A-instruction
                if (line.contains("@")) { 
                    bit = line.split("@")[1].trim(); 
                }
                //C-instruction
                else { 
                    //contains dest, comp or jump instruction
                    if (line.contains("=")) { 
                        String[] segment = line.split("=");
                        dest = segment[0];
                        //validate jump
                        if (segment[1].contains(";")) {
                            jumpCheck(segment[1]);
                        } else {
                            //remove comments and whitespace
                            comp = segment[1].split("/")[0].trim(); 
                        }
                    } else if (line.contains("+") || line.contains("-")) { 
                        //validate jump
                        if (line.contains(";")) {
                            jumpCheck(line);
                        } else {
                            //remove comments and whitespace
                            comp = line.split("/")[0].trim();
                        }
                    } else if (line.contains(";")) {
                        jumpCheck(line);
                    } else {
                        //remove comments and whitespace
                        jump = line.split("/")[0].trim();
                    }
                }
                return true;
            }
        }
        return false;
    } 

     private void jumpCheck(String str) {
        String[] parts = str.split(";");
        comp = parts[0].trim();
        jump =  parts[1].split("/")[0].trim();
    }

    public String dest() {
        return dest;
    }

    public String comp() {
        return comp;
    }

    public String jump() {
        return jump;
    }

    public String bit() {
        return bit;
    }
}