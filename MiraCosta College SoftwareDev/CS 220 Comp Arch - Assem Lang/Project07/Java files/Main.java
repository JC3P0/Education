class Main {
  public static void main(String[] args) {
    String fileName = "StaticTest.vm";
    VMTranslator VMTobj = new VMTranslator(fileName);
    VMTobj.translate();
  }
}