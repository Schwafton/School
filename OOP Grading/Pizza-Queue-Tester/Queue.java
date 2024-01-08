
public class Queue {
    static void enqueue(Pizza thisPizza) {
        if (thisPizza.head == null) {
            thisPizza.head = thisPizza;
        } else {
            thisPizza.tail.next = thisPizza;
        }
            thisPizza.tail = thisPizza;
    }
    public static Pizza dequeue() {

        Pizza pizzaToDeliver = null;

        if (pizzaToDeliver.head != null) {
            pizzaToDeliver = pizzaToDeliver.head;
            pizzaToDeliver.head = pizzaToDeliver.head.next;
        } else {
            pizzaToDeliver.tail = null;
        }
        return pizzaToDeliver;
    }

    static void deliver() {

        Pizza thisPizza = dequeue();

        if (thisPizza == null) {
            System.out.println("No deliveries pending\n");
            return;
        } else {
            System.out.println("Deliver a pizza with " + thisPizza.ingredients
                    + " to " + thisPizza.address + "\n");
        }
    }
}
