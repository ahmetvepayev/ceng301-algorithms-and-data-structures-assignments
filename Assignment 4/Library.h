#ifndef PA4_1_LIBRARY_H
#define PA4_1_LIBRARY_H
struct Book{
	Book(int givenId);
	int id;
	Book* left;
	Book* right;
};

class Library{
public:
	static void Insert(const int & givenId, Book* & bookPtr=root);
	static void Clear();
	static void Clear(Book* bookPtr);
	static int GetSmallestSubtreeRootId(const int & id1, const int & id2, Book* bookPtr=root);
private:
	static Book* root;
};
#endif