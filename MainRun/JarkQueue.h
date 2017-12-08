#pragma once

#include <queue>
template<class T>
class JarkQueue
{
public:
	JarkQueue();
	~JarkQueue();
	T front();
	bool isEmpty();
	void Spasvopush(T cals);
	void pop();
public:
	queue<T> que;


};

template<class T>
void JarkQueue<T>::pop()
{
	que.pop();
}


