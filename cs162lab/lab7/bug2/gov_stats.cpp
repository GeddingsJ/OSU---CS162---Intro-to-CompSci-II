#include "nation.h"
#include "state.h"
#include <iostream>
using namespace std;

int main() {
   int which_state;
   string state_name = "oregon";
   state s[50];
   
   cout << "Which state do you want to set the pop? (1-50):";
   cin >> which_state;
   s[which_state].set_pop(300000);

//setname is never used and needs a string
   s[which_state].set_name(state_name);

   s[which_state].display_pop();

   return 0;
}
