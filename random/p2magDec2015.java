import java.math.*;

public class p2magDec2015 {
	private static void someTransaction() {
		doTransaction1();
		System.out.println();
		doTransaction2();
		System.out.println();
		doTransaction3();
	}

	private static void doTransaction1() {
		System.out.println(2.0 - 1.1);
	}

	private static void doTransaction2() {
		BigDecimal amount = new BigDecimal(2.0);
		BigDecimal debit = new BigDecimal(1.1);
		System.out.println(amount+ " " + debit);
		System.out.println(amount.subtract(debit));
	}

	private static void doTransaction3() {
		BigDecimal amount = new BigDecimal("2.0");
		BigDecimal debit = new BigDecimal("1.1");
		System.out.println(amount + " " + debit);
		System.out.println(amount.subtract(debit));
	}

	public static void main(String[] args) {
		someTransaction();
	}
}
