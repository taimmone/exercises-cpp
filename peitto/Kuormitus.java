public class Kuormitus
{
  static class A
  {
    public String kuvaus;

    A(String nimi)
    {
      kuvaus = new String("A-olio " + nimi);
    }
    
    public String lueKuvaus()
    {
      return kuvaus;
    }

    public void kuka(A a)
    {
      System.out.println("Olen " + kuvaus + " ja parametrini on " +
                                  a.kuvaus + " [tai " + a.lueKuvaus() + "]");
    }
  }
  
  static class B extends A
  {
    public String kuvaus;

    B(String nimi)
    {
      super(nimi + "(B:n osana)");
      kuvaus = new String("B-olio " + nimi);
    }
    
    public String lueKuvaus()
    {
      return kuvaus;
    }
    
    public void kuka(B b)
    {
      System.out.println("Olen " + kuvaus + " ja parametrini on " +
                                  b.kuvaus + " [tai " + b.lueKuvaus() + "]");
    }
  }
  
  public static void main(String[] args)
  {
    A a = new A("a");
    B b = new B("b");
    a.kuka(a);
    a.kuka(b);
    b.kuka(a);
    b.kuka(b);
  }
}
