import java.lang.String;

public class polymorphism {
	public class Colour {
		public void say() {
			System.out.println("I'm a generic colour");
		}
	}

	public class Purple extends Colour {
		@Override
		public void say() {
			System.out.println("I'm purple");
		}
	}

	public static void main (String[] args) {
		polymorphism me = new polymorphism();
		Colour colour = me.new Purple();
		colour.say();
	}
}
