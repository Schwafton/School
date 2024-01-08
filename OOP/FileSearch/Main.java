
class Main {
  public static void main(String[] args) {
    System.out.println("Hello world!");
    FileSearch fileSearch = new FileSearch();
    String[] search = {"UserDB.txt", "afton"};
    fileSearch.FileSearch(search);
  }
}
