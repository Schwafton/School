
class Main {
  public static void main(String[] args) {
    
    Pizza first = null;
    Pizza last = null;

    enqueue(new Pizza("pepperoni", "1234 Bobcat Trail"));
    enqueue(new Pizza("sausage", "2345 University Drive"));
    deliver();
    enqueue(new Pizza("extra cheese", "3456 Rickster Road"));
    enqueue(new Pizza("everything", "4567 King Court"));
    enqueue(new Pizza("coffee beans", "5678 Java Circle"));
    deliver();
    deliver();
    deliver();
    deliver();
    deliver();
  }
}