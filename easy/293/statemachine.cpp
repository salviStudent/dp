#include <vector>
#include <string>
#include <iostream>

using namespace std;

class smachine
{
public:
  smachine();
  void updateState();
  void printState()
  {
    if(machineState == "done")
      cout << "Boom";
    else
      cout << "Bomb defused";
  };
  void logic(string nextState);
  
private:
  string machineState = "empty";
  vector<string> listOfStates; 
};


smachine::smachine()
{
  while(true)
    {
      cout << "Enter colors: ";
      string input;
      getline(cin, input);
      if (!input.empty())
	listOfStates.push_back(input);
      else
	{
	  break;
	}
    }
  updateState();
}

void smachine::logic( const string nextState)
{
  if(machineState == "done")
    return;
  else if(machineState == "white" &&
	  (nextState =="white" || nextState == "black"))
    machineState = "done";
  else if(machineState == "red" && nextState != "green")
    machineState = "done";
  else if(machineState =="black" &&
	  (nextState == "white" || nextState == "green"  ||
	   nextState == "orange"))
    machineState = "done";
  else if((machineState == "orange" || machineState =="purple") &&
	  (nextState != "red" || nextState != "black"))
    machineState = "done";
  else if(machineState == "green" &&
	  (nextState != "orange" && nextState != "white"))
    machineState = "done";
  else
    machineState = nextState;
}

void smachine::updateState()
{
  for(auto const& value: listOfStates)
    logic(value);
}

int main()
{
  smachine test;
  test.printState();
}
