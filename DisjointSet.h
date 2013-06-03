/*
 * DisjointSet.h
 *
 *  Created on: Mar 18, 2013
 *      Author: valexiev
 */

#ifndef DISJOINTSET_H_
#define DISJOINTSET_H_

#include <vector>

using std::vector;

template<class T>
class DisjointSetNode {
	public:
		int rank;
		T data; //data of node;
		DisjointSetNode<T> *parent; //parent
		DisjointSetNode(T);
};
template<class T>
DisjointSetNode<T>::DisjointSetNode(T d){
	data = d;
	parent = this;
	rank = 0;
}

template<class T>
class DisjointSet {
    public:
        DisjointSet(const T &data);
        void unionSets(DisjointSet &ds);
        const T &getMarker();
        DisjointSetNode<T> * link(DisjointSetNode<T> *x, DisjointSetNode<T> *y);
        DisjointSetNode<T> * findSet(DisjointSetNode<T> * x);

        DisjointSetNode<T> * root;
};

template<class T>
const T& DisjointSet<T>::getMarker(){
	return findSet(root)->data;
}

template<class T>
DisjointSet<T>::DisjointSet(const T &data){

	root = new DisjointSetNode<T>(data);

}

template<class T>
void DisjointSet<T>::unionSets(DisjointSet &ds){

	root = link(findSet(root), findSet(ds.root));

}

template<class T>
DisjointSetNode<T> * DisjointSet<T>::link(DisjointSetNode<T> *x, DisjointSetNode<T> *y){

	if(x->rank > y->rank){
		y->parent = x;
		return x;
	}
	else{
		x->parent = y;
		if(x->rank == y->rank){
			y->rank = y->rank + 1;
		}
		return y;
	}
}

template<class T>
DisjointSetNode<T> * DisjointSet<T>::findSet(DisjointSetNode<T> * x){
	if(x != x->parent){
		x->parent = findSet(x->parent);
	}

	return x->parent;
}
#endif /* DISJOINTSET_H_ */
