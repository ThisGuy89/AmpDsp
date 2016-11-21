#pragma once
#include <Stk.h>
using namespace std;
const int bufferSize = 5000;

class audioBufferTest
{
public:
	audioBufferTest() {
		index = 0;
		for (int i = 0; i < bufferSize; i++) buffer[i] = 0.0;
	}
	void push(stk::StkFloat val) {
		if (index == bufferSize - 1) index = 0;
		buffer[index++] = val;
	}
	void printAllValues() {
		for (int i = 0; i < bufferSize; i++) 
			std::cout << buffer[i] << endl;
	}
	stk::StkFloat getCurrent() {
		return buffer[index];
	}

	void resetCursor() {
		index = 0;
	}

	stk::StkFloat pop() {
		if (index == bufferSize - 1) {
			index = 0;
		}
		return buffer[index++];
	}

private:
	int index;
	stk::StkFloat buffer[bufferSize];
};


