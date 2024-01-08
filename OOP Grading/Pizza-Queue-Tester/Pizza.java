
public class Pizza {

    static public Pizza head;
    static public Pizza tail;
    public String ingredients;
    public String address;
    public Pizza next;

    public Pizza() {
        ingredients = null;
        address = null;
        next = null;
    }

    public Pizza(String getIngredients, String getAddress) {
        ingredients = getIngredients;
        address = getAddress;
        next = null;
    }
}