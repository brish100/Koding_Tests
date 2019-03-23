class Memento:
	def __init__(self, state):
		self.state = state

	def getState(self):
		return self.state

class CareTaker:
	def __init__(self):
		self.mementos = []

	def save(self, memento):
		self.mementos.append(memento)
		return (len(self.mementos)-1)

	def restore(self, memento_index):
		return self.mementos[memento_index]

class Originator:
	def __init__(self):
		self.mem = None

	def setMemento(self, state):
		self.mem = Memento(state)
		print("State is set to:",self.mem.getState())

	def restoreMemento(self, memento):
		print("State is reverted back from:",self.mem.getState(),"to",memento.getState())
		self.mem = memento

	def returnMemento(self):
		return self.mem

def main():
	originator = Originator()
	caretaker = CareTaker()
	originator.setMemento("State1")
	index_nr1 = caretaker.save(originator.returnMemento())
	originator.setMemento("State2")
	index_nr2 = caretaker.save(originator.returnMemento())
	originator.setMemento("State3")
	index_nr3 = caretaker.save(originator.returnMemento())
	originator.setMemento("State4")
	index_nr4 = caretaker.save(originator.returnMemento())
	originator.restoreMemento(caretaker.restore(index_nr1))
	originator.restoreMemento(caretaker.restore(index_nr2))
	originator.restoreMemento(caretaker.restore(index_nr3))
	originator.restoreMemento(caretaker.restore(index_nr4))

if __name__ == '__main__':
	main()
