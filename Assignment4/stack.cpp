#include "stack.h"
/*func: add
 * desc: add to the stack
 * para: creature pointer
 * input: value to add
 * output: na
 */
void Stack :: add(Creature* newValue){
	sNode *temp = new sNode();
	temp -> value = newValue;
	temp -> next = top;
	top = temp;
	count++;
}

/*func: remove
 * desc: remove from top of stack
 * para: na
 * input: na
 * output: removed item
 */
Creature* Stack :: remove(){
	if(top == NULL){
		cout << "Stack is empty" << endl;
	}else{
		Creature* removed = top -> value;
		
		sNode *temp = top -> next;
		delete top;
		top = temp;

		count--;

		return removed;
	}
}
