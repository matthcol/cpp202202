template<class InputIterator>
void displayIterable(InputIterator first, InputIterator last) {
	std::cout << std::distance(first, last) << "/[ ";
	if (first != last) {
		// display the first element
		std::cout << *first;
		++first;
	}
	while (first != last) {
		// display one element
		std::cout << ", " << *first ;
		// adavance the iterator
		++first;
	}
	std::cout << " ]" << std::endl;
}