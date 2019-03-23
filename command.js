let Receiver_3 = function () {
    //Empty
};

Receiver_3.prototype = {
    command: function () {
        console.log("Command is triggered!")
    }
};

let Receiver = function (rec_2) {
    this.rec_2 = rec_2;
};

Receiver.prototype = {
    command: function () {
        this.rec_2.command();
    }
};

let Invoker = function (rec) {
    this.rec = rec;
}

Invoker.prototype = {
    command: function () {
        this.rec.command();
    }
};

let main = () => {
    let rec_3 = new Receiver_3();
    let rec_2 = new Receiver(rec_3);
    let rec = new Receiver(rec_2);
    let inv = new Invoker(rec);
    inv.command();
}

main()
