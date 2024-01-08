class pizza {
  public String ingrediants;
  public String address;
  public pizza next;
  
  public pizza(String ingrediants, String address) {
    this.address = address;
    this.ingrediants = ingrediants;
    next = null;
  }
}