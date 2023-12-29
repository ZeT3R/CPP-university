//
// Created by Sergey on 30.11.2020.
//

#ifndef LAB3_TREE_H
#define LAB3_TREE_H

#include <mutex>


template <class T>
class Tree{
public:

    struct Root{

        T value;
        Root* left;
        Root* right;
        explicit Root(const T& val);
    };

    typedef Tree<T>::Root* rootpointer;

	Tree() noexcept;

	Tree(const Tree<T>& copy);

	Tree(Tree<T>&& move) noexcept;

    ~Tree();

	void add(const T& val);

	void add(const Tree<T>& copy);

	bool find(const T& val) noexcept;

    void deleteSubTree(const T& val);

	Tree<T> returnSubTree(const T& val);

	void deleteElem(const T& val);

	void clear() noexcept;



	template <class T1>
	friend std::ostream& operator<< (std::ostream& out, const Tree<T1>& tree);

	void lkp(std::ostream& out = std::cout, const char& razdel = ' ') noexcept;

    void lpk(std::ostream& out = std::cout, const char& razdel = ' ') noexcept;


protected:
    std::mutex mutex;
    rootpointer classroot;


private:

    void recurrent_add(rootpointer& root, const T& val);
    static rootpointer recurrent_copy(const rootpointer& copy);
	void recurrent_addtree(rootpointer& root, const rootpointer& adding);
	static void recurrent_delete(rootpointer& root) noexcept;
	static void recurrent_lkp(const rootpointer& root, std::ostream& out, const char& razdel) noexcept;
	static void recurrent_lpk(const rootpointer& root, std::ostream& out, const char& razdel) noexcept;
	rootpointer& recursive_search(rootpointer& root, const T& val) noexcept;
};


template<class T>
inline Tree<T>::Tree() noexcept{
    classroot = nullptr;
}


template<class T>
inline Tree<T>::Tree(const Tree<T>& copy){
    classroot = recurrent_copy(copy.classroot);
}


template<class T>
inline Tree<T>::Tree(Tree<T>&& move) noexcept{
    classroot = move.classroot;
    move.classroot = nullptr;
}


template<class T>
inline Tree<T>::~Tree(){
    recurrent_delete(classroot);
}


template<class T>
inline Tree<T>::Root::Root(const T& val) : value(val){
    left = nullptr;
    right = nullptr;
}


template<class T>
inline void Tree<T>::add(const T& val){
	std::lock_guard<std::mutex> lock_guard(mutex);
    recurrent_add(classroot, val);
}


template<class T>
inline void Tree<T>::add(const Tree<T>& copy){
	std::lock_guard<std::mutex> lock_guard(mutex);
    recurrent_addtree(classroot, copy.classroot);
}


template<class T>
inline bool Tree<T>::find(const T& val) noexcept{
	std::lock_guard<std::mutex> lock_guard(mutex);
	return recursive_search(this->classroot, val) != nullptr;
}


template<class T>
inline void Tree<T>::deleteSubTree(const T& val){
    std::lock_guard<std::mutex> lock_guard(mutex);
    rootpointer& find = recursive_search(classroot, val);
    if (find == nullptr)
        throw std::logic_error("Element was not found");
    recurrent_delete(find);
}


template<class T>
inline Tree<T> Tree<T>::returnSubTree(const T& val){
	Tree<T> subTreeReturn;
	std::lock_guard<std::mutex> lock_guard(mutex);
    subTreeReturn.classroot = recurrent_copy(recursive_search(classroot, val));
	return subTreeReturn;
}


template<class T>
inline void Tree<T>::deleteElem(const T& val) {
    std::lock_guard<std::mutex> lock_guard(mutex);
    rootpointer &deleting_elem = recursive_search(classroot, val);
    rootpointer deleting_memory = deleting_elem;

    if (classroot->value == val) {

        if (deleting_elem->left == nullptr && deleting_elem->right == nullptr){
            deleting_elem = nullptr;
        }

        else if (deleting_elem->left == nullptr) {
            deleting_elem = deleting_elem->right;
        }
        else if (deleting_elem->right == nullptr) {
            deleting_elem = deleting_elem->left;
        }


    } else {
        if (deleting_elem != nullptr) {
            if (deleting_elem->right == nullptr) {
                deleting_elem = deleting_elem->left;
            } else {
                if (deleting_elem->right->left == nullptr) {
                    deleting_elem->right->left = deleting_elem->left;
                    deleting_elem = deleting_elem->right;
                } else {
                    rootpointer &last_left_elem = deleting_elem->right->left;
                    while (last_left_elem->left != nullptr)
                        last_left_elem = last_left_elem->left;

                    last_left_elem->left = deleting_elem->left;
                    last_left_elem->right = deleting_elem->right;
                    deleting_elem = last_left_elem;
                    last_left_elem = nullptr;
                }
            }
        }
    }
	delete deleting_memory;
}


template<class T>
inline void Tree<T>::clear() noexcept{
	std::lock_guard<std::mutex> lock_guard(mutex);
    recurrent_delete(classroot);
}


template<class T>
inline void Tree<T>::lkp(std::ostream& out, const char& razdel) noexcept{
	std::lock_guard<std::mutex> lock_guard(mutex);
    recurrent_lkp(classroot, out, razdel);
}


template<class T>
inline void Tree<T>::lpk(std::ostream& out, const char& razdel) noexcept{
	std::lock_guard<std::mutex> lock_guard(mutex);
    recurrent_lpk(classroot, out, razdel);
}



template<class T>
void Tree<T>::recurrent_add(rootpointer& root, const T& val){
    if (root == nullptr){
        root = new Root(val);
        if (root == nullptr)
            throw std::logic_error("Memory error");
    }
    else if(val < root->value) {
        recurrent_add(root->left, val);
    }
    else{
        recurrent_add(root->right, val);
    }

}


template<class T>
typename Tree<T>::rootpointer Tree<T>::recurrent_copy(const Tree<T>::rootpointer& copy){
	Tree<T>::rootpointer returnroot;
	if (copy != nullptr){
        returnroot = new Root(copy->value);
		if (returnroot == nullptr)
			throw std::logic_error("Memory error");
        returnroot->left = recurrent_copy(copy->left);
        returnroot->right = recurrent_copy(copy->right);
	}
	else
        returnroot = nullptr;

	return returnroot;
}


template<class T>
inline void Tree<T>::recurrent_addtree(rootpointer& root, const rootpointer& adding){
	if (adding != nullptr){
        recurrent_addtree(root, adding->left);
        recurrent_addtree(root, adding->right);
        recurrent_add(root, adding->value);
	}
}


template<class T>
void Tree<T>::recurrent_delete(rootpointer& root) noexcept{
	if (root != nullptr){
        recurrent_delete(root->left);
        recurrent_delete(root->right);
		delete root;
		root = nullptr;
	}
}


template<class T>
void Tree<T>::recurrent_lkp(const rootpointer& root, std::ostream& out, const char& razdel) noexcept{
	if (root != nullptr){
        recurrent_lkp(root->left, out, razdel);
		out << root->value << razdel;
        recurrent_lkp(root->right, out, razdel);
	}
}


template<class T>
inline void Tree<T>::recurrent_lpk(const rootpointer& root, std::ostream& out, const char& razdel) noexcept{
	if (root != nullptr){
        recurrent_lpk(root->left, out, razdel);
        recurrent_lpk(root->right, out, razdel);
		out << root->value << razdel;
	}
}


template<class T>
typename Tree<T>::rootpointer& Tree<T>::recursive_search(typename Tree<T>::rootpointer& root, const T& val) noexcept{
	if ((root == nullptr) || (root->value == val))
			return root;
	else if(val < root->value){
	    return recursive_search(root->left, val);
	}
	else{
	    return recursive_search(root->right, val);

	}

}


template<class T1>
inline std::ostream& operator<<(std::ostream& out, const Tree<T1>& tree){
    Tree<T1>::recurrent_lkp(tree.classroot, out, ' ');
	return out;
}

#endif //LAB3_TREE_H
