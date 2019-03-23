let Memento = function(state) {
	this.state = state
}

Memento.prototype = {
	getState: function() {
		return this.state
	}
}

let CareTaker = function() {
	this.mementos = []	
}

CareTaker.prototype = {
	save: function(memento_obj) {
		this.mementos.push(memento_obj)
		return (this.mementos.length-1)
	},
	restore: function(memento_index) {
		return this.mementos[memento_index]
	}
}

let Originator = function() {
	this.mem = null
}

Originator.prototype = {
	setMemento: function(state){
		this.mem = new Memento(state)
		console.log("State is set to:",this.mem.getState())
	},
	restoreMemento: function(new_mem){
		console.log("State is reverted back from: "+this.mem.getState()+" to "+new_mem.getState());
		this.mem = new_mem
	},
	returnMemento: function(){
		return this.mem
	}
}

let main = () => {
	originator = new Originator()
	caretaker = new CareTaker()
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
}

main()
