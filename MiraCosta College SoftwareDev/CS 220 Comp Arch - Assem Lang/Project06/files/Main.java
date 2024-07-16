class Main {
  public static void main(String[] args) {
    String filename = "Rect.asm";
    Assembler assembly = new Assembler();
    assembly.preAssemble(filename);
    assembly.assemble(filename);
  }
}