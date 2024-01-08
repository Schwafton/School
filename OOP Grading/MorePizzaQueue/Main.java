class Main{
  public class PizzaQueue {
    static public PizzaQueue head;
    static public PizzaQueue tail;		   
    public String ingredients, address;
    public PizzaQueue next;
  
    public PizzaQueue()
    {
      ingredients = null;
      address = null;
      next = null;
    }
  
    public PizzaQueue(String setIngredients, String setAddress)
    {
      ingredients = setIngredients;
      address = setAddress;
      next = null;
    }
  
    static void enqueue(PizzaQueue thispizza)
    {
      if (head == null)
      {
        head = thispizza;
      }
      else
      {
        tail.next = thispizza;
      }
      tail = thispizza;
      return;
    }
  
    static PizzaQueue dequeue()
    {
      PizzaQueue pizzatodeliver = null;
      if (head != null)
      {
        pizzatodeliver = head;
        head = head.next;
      }
  
      if (head == null)
      {
        tail = null;
      }
      return pizzatodeliver;
    }
  
    static void deliver()
    {
      PizzaQueue thisPizza = dequeue();
      if (thisPizza == null)
      {
        System.out.println("no deliveries pending");
        return;
      }
      System.out.println("Deliver a pizza with " + thisPizza.ingredients + " to " + thisPizza.address);
    }
  
    public static void main(String[] args)
    {
      PizzaQueue za = new PizzaQueue("pepperoni", "1234 Bobcat Trail");
      
      enqueue(za);

      deliver();

    }
  }
}