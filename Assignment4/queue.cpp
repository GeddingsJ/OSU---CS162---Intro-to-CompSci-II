#include "queue.h"

Queue :: Queue(){
	back = NULL;
	front = NULL;
}

/*func: addQ
 * desc: adds to the back of queue
 * para: creature pointer
 * input: new value
 * output: na
 */
void Queue :: addQ(Creature* newValue){
	Node *tempAdd = new Node;

	tempAdd -> value = newValue;
	tempAdd -> next = NULL;

	if(front == NULL){
		front = tempAdd;
	}else{
		back -> next = tempAdd;
	}

	back = tempAdd;
}

/*func: removeQ
 * desc: remove from front of queue
 * para: na
 * input: na
 * output: removed item
 */
Creature*  Queue :: removeQ(){
	if(front == NULL){
		cout << "Empty" << endl;
	}else{
		Creature* removed = front -> value;

		Node *temp = front -> next;
		delete front;
		front = temp;

		return removed;
	}
}
