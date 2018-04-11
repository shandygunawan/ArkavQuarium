#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>

using namespace std;

template <class T> class LinkedList;

template<class T>
class Node {
	private :
		T element;
		Node<T> *prev;
		Node<T> *next;
	public :
		//ctor dengan 1 parameter
		Node(T& );
		friend class LinkedList<T>;
};


template <class T>
class LinkedList{
	private :
		Node<T>* First;
	public :
		LinkedList(); //ctor
		
		LinkedList(const LinkedList& L); //cctor

		/* METHOD */
		int find(T);
		// find the index of given element in the list

		bool isEmpty() const;
		// check if the list is empty

		bool isOneElmt() const;
		// check if the list only has one element

		void add(T&);
		// add an element as the last element of the list

		void remove(T&);
		// remove the given element from the list

		T& get(int idx);
		// get the element with i-th index of the list
		
		int getSize();
		// get LinkedList size
		
		Node<T>* getFirst();
		
		void printList();
};


template <class T>
Node<T>::Node(T& elem){
	element = elem;
	prev = 0;
	next = 0;
}

template <class T>
LinkedList<T>::LinkedList(){
	First = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& L) {
	if (L.isEmpty()){
		First = 0;
	} else {
		Node<T>* toAdd = new Node<T> (L.First->element);
		First = toAdd;
		Node<T>* iter = L.First->next;
		
		while ( iter!=L.First){
			this->add(iter->element);
			iter = iter->next;
		}
	}
	
	
	
}

template <class T>
// find the index of given element in the list
int LinkedList<T>::find(T wanted){
	
	if (isEmpty()){
		return -1;
	} else {
		// wanted element is first in the list
		if (First->element == wanted){
			return 1;
		}

		// wanted element is not the first in the list
		int i = 2;
		bool found = false;
		Node<T>* iter = First->next;

		// iterate through list for the wanted element
		while( (iter != First) && (not(found)) ){
			if(iter->element == wanted) {
				found = true;
			} else {
				iter = iter->next;
				i++;
			}
		}

		if(found == false) {
			// return -1 if the wanted element is not found
			return -1;
		} else {
			// return the index of the wanted element
			return i;
		}
	}
}

template <class T>
// check if the list is empty
bool LinkedList<T>::isEmpty() const {
	
	return (First==NULL);
	
}

template <class T>
// check if the list only has one element
bool LinkedList<T>::isOneElmt() const{
	return (First != NULL && First->next == First);
}

template <class T>
// add an element as the last element of the list
void LinkedList<T>::add(T& elem){
	
	Node<T>* toAdd = new Node<T> (elem);
	
	if(isEmpty()) {
		// list is empty
		
		First = toAdd;
		
		First->next = First;
		First->prev = First;
	}
	else if(isOneElmt()) {
		// list only has one element
		First->next = toAdd;
		First->prev = toAdd;
		
		toAdd->prev = First;
		toAdd->next = First;
	}
	else {
		// list has more than one element
		(First->prev)->next = toAdd;
		
		toAdd->prev = First->prev;
		toAdd->next = First;
		
		First->prev = toAdd;
		
	}
}

template <class T>
// remove the given element from the list
void LinkedList<T>::remove(T& elem){
	if (isEmpty()){
		
	} else {
		int idx = find(elem);
		
		// the element is found in the list
		if(idx != -1) { //if element T found in LinkedList
			if (isOneElmt()){
				delete First;
				First = NULL;
			} else {
				// iterate until idx-th element
				if (idx==1){
					(First->prev)->next = First->next;
					(First->next)->prev = First->prev;
					First = First->next;
					
				} else {
					Node<T> *iter = First;
					
					for(int i = 1; i < idx; i++) {
						iter = iter->next;
					} 
					
					//Link element before removed element to element after removed element
					(iter->prev)->next = iter->next;
					(iter->next)->prev = iter->prev;
					
					delete iter;	
				}
			}
		}
	}
}

template <class T>
T& LinkedList<T>::get(int idx){
	if ((idx<0)||(idx>getSize())){
		throw "No_Such_Element_Error";
	} else {
		//iterate until idx-th element
		Node<T>* iter = First;
		for (int i=1; i<idx; i++) {
			iter = iter->next;
		}
		//return element
		return iter->element;
	}
}

template <class T>
int LinkedList<T>::getSize(){
	if (isEmpty()){
		return 0;
	} else {
		int it = 1;
		Node<T>* iter = First;
		iter = iter->next;
		while (iter!=First){
			it++;
			iter = iter->next;
		}
		// return size
		return it;
	}
}

template <class T>
Node<T>* LinkedList<T>::getFirst(){
	return First;
}

template <class T>
void LinkedList<T>::printList(){
	if (isEmpty()){
		cout << "kosong" <<endl;
	} else {
		First->element.Speak();
		
		Node<T>* iter = First->next;

		while (iter != First) {
			iter->element.Speak();
			iter = iter->next;
		}
	}
}

#endif

