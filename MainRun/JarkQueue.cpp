#include "stdafx.h"
#include "JarkQueue.h"


template<class T> JarkQueue<T>::JarkQueue()
{
}


template<class T> JarkQueue<T>::~JarkQueue()
{
}

template<class T>
bool JarkQueue<T>::isEmpty()
{
	return que.empty();
}


template<class T>
void JarkQueue<T>::Spasvopush(T cals)
{
	return que.push(cals);
}


template<class T>
T JarkQueue<T>::front()
{
	return que.front();
}

