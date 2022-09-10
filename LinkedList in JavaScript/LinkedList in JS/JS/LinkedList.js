class Node{
    constructor(data, next = null){
        this.data = data;
        this.next = next;
    }

    // setters and getters
    setData(data){ this.data = data; }
    setNext(next){ this.next = next; }

    getData(){ return this.data; }
    getNext(){ return this.next; }
}


class LinkedList{
    constructor(){
        this.head = null;
        this.last = null;
        this.length = 0;
    }

    getLength(){ return this.length; }

    isEmpty(){ return this.length == 0; }
    insertAtLast(value){
        let newNode  = new Node(value);
        if(this.isEmpty()){
            this.head = newNode;
            this.last = newNode;
        }
        else{
            this.last.setNext(newNode);
            this.last = newNode;
        }
        this.length++;
    }


    insertAtBegin(value){
        let newNode  = new Node(value);
        if(this.isEmpty()){
            this.head = newNode;
            this.last = newNode;
        }
        else{
            newNode.setNext(this.head);
            this.head = newNode;
        }
        this.length++;
    }

    print(){
        let arrData = [];
        let temp = this.head;
        while(temp){
            arrData.push(temp.getData());
            temp = temp.getNext();
        }
        console.log(...arrData);
    }

    removeFromBegin(){
        if(this.isEmpty()){
            return false;
        }
        if(this.head.getNext() == null){
            this.head = null;
            this.last = null;
            this.length--;
            return true;
        }
        else{
            this.head  = this.head.getNext();
            this.length--;
            return true;
        }


    }

    removeFromLast(){
        if(this.isEmpty()){ return false; }
        if(this.head.getNext() == null){
            this.head = null;
            this.last = null;
            this.length--;
            return true;
        }
        else{
            let temp = this.head;
            let prev;
            while(temp.getNext() != null){
                prev = temp;
                temp = temp.getNext();
            }
            temp = null;
            prev.setNext(null);
            this.length--;
        }
    }

    getFirstNode(){ return this.head; }
    getLastNode(){ return this.last; }
}


let l1 = new LinkedList();
l1.insertAtLast(8);
l1.insertAtLast(10);
l1.insertAtLast(12);
l1.insertAtBegin(200);
// l1.removeFromBegin();
l1.removeFromLast();
l1.print();
// console.log(l1.getLength());


