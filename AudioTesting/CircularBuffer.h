#pragma once
/*
template <class T>
class CircularBuffer {
public:
	CircularBuffer(const int &bufferSize);
	void push(T value);
	T pop();

private:
	int m_bufferSize;
	T m_buffer[];
	int m_headIndex;
	int m_tailIndex;
	~CircularBuffer();
};

template <class T>
CircularBuffer::CircularBuffer(const int &bufferSize)
{
	m_bufferSize = bufferSize;
	m_buffer = new T[bufferSize];
	m_headIndex = 0;
	m_tailIndex = 0;
}

template <class T>
CircularBuffer::~CircularBuffer() {
	delete m_buffer[];
}

template <class T>
void CircularBuffer::push(T value) {
	m_buffer[m_tailIndex] = T value;

	if (m_headIndex == m_bufferSize-1) m_headIndex = 0;
	else m_headIndex++;

	return;
}

template <class T>
T CircularBuffer::pop() {
	int popIndex = m_tailIndex;

	if (m_tailIndex == m_bufferSize-1) m_tailIndex = 0;
	else m_tailIndex++;
	
	return m_buffer[popIndex];
}

*/