template <typename T>
list_iterator<T>::list_iterator(list_node<T>* node) : m_node{ node } {

}


template <typename T>
T& list_iterator<T>::get_current() const {
	if (this->is_at_end()) {
		throw std::out_of_range("list_iterator is out of range");
	}
	
	return m_node->m_value;
}

template <typename T>
bool list_iterator<T>::is_at_end() const noexcept {
	return m_node == nullptr;
}

template <typename T>
void list_iterator<T>::to_next() {
	if (this->is_at_end()) {
		throw std::out_of_range("list_iterator is out of range");
	}

	m_node = m_node->m_next;
}
