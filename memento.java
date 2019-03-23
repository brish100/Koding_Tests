class memento{
	private static class Memento{
		private String state = null;

		public Memento(String state){
			this.state = state;
		}

		public String getState(){
			return state;
		}
	}

	private static class CareTaker{
		private Memento mementos[] = new Memento[1];

		public int save(Memento mem){
			Memento new_mementos[] = new Memento[mementos.length+1];
			for(int i=0;i<mementos.length;i++){
				new_mementos[i] = mementos[i];
			}
			new_mementos[mementos.length] = mem;
			mementos = new_mementos;
			return (mementos.length-1);
		}

		public Memento restore(int mem_index){
			return mementos[mem_index];
		}
	}

	private static class Originator{
		private Memento mem = null;

		public void setMemento(String state){
			mem = new Memento(state);
			System.out.println("State is set to: "+this.mem.getState());
		}

		public void restoreMemento(Memento new_mem){
			System.out.println("State is reverted back from: "+this.mem.getState()+" to "+new_mem.getState());
			this.mem = new_mem;
		}

		public Memento returnMemento(){
			return this.mem;
		}
	}

	public static void main(String[] args) {
		CareTaker caretaker = new CareTaker();
		Originator originator = new Originator();
		originator.setMemento("State1");
		int index_nr1 = caretaker.save(originator.returnMemento());
		originator.setMemento("State2");
		int index_nr2 = caretaker.save(originator.returnMemento());
		originator.setMemento("State3");
		int index_nr3 = caretaker.save(originator.returnMemento());
		originator.setMemento("State4");
		int index_nr4 = caretaker.save(originator.returnMemento());
		originator.restoreMemento(caretaker.restore(index_nr1));
		originator.restoreMemento(caretaker.restore(index_nr2));
		originator.restoreMemento(caretaker.restore(index_nr3));
		originator.restoreMemento(caretaker.restore(index_nr4));
	}
}
