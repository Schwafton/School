class Main{
 /* public static void display(Pizza head) {
      Pizza thispizza = head;
      System.out.println("\ndelivery queue: ");
      while (thispizza != null) {
        System.out.println(thispizza.ingrediants + " " + thispizza.address);
        thispizza = thispizza.next;
      }
      System.out.println("\n");
  }*/
public static void main(String[] args) {
enqueue(new pizza("pepperoni", "1234 Bobcat Trail"));
enqueue(new pizza("sausage", "2345 University Drive"));
deliver();
enqueue(new pizza("extra cheese", "3456 Rickster Road"));
enqueue(new pizza("everything", "4567 King Court"));
enqueue(new pizza("coffee beans", "5678 Java Circle"));
deliver();
deliver();
deliver();
deliver();
deliver();
}
}