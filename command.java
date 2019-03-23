public class command{
	static private interface Receivable {
		void command();
	}

	static private class Receiver_3 implements Receivable{
		public void command(){
			System.out.println("Command is triggered!");
		}
	}

	static private class Receiver implements Receivable{
		private Receivable rec = null;
		Receiver(Receivable rec){
			this.rec = rec;
		}

		public void command(){
			this.rec.command();
		}
	}	

	static private class Invoker{
		private Receivable rec = null;
		Invoker(Receivable rec){
			this.rec = rec;
		}

		public void command(){
			this.rec.command();
		}
	}

	public static void main(String[] args) {
		Receivable rec_3 = new Receiver_3();
		Receivable rec_2 = new Receiver(rec_3);
		Receiver rec = new Receiver(rec_2);
		Invoker inv = new Invoker(rec);
		inv.command();
	}
}
