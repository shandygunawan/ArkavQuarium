#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
	private :
		T element;
		Node<T> *prev;
		Node<T> *next;
	public :
		//Ctor
		Node(T);
		friend class LinkedList<T>; 
};

template <class T>
Node<T>::Node(T elem){
	element = elem;
	prev = 0;
	next = 0;
}

#endif
