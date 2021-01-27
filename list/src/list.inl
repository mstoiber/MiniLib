#pragma once
#include <memory>
#include "list_iterator.h"

template <typename T>
list<T>::~list() noexcept {
	clear();
}

template <typename T>
void list<T>::add(T value) {
	list_node<T> *node = new list_node<T>{std::move(value)};
	if (m_tail != nullptr) {
		m_tail->m_next = node;
	}
	else {
		m_head = node;
	}
	m_tail = node;
	
	m_size++;
}

template <typename T>
void list<T>::clear() noexcept {
	auto n = m_head;
	
	while (n != nullptr) {
		auto next = n->m_next;
		delete n;
		n = next;
	}
	m_size = 0;
	m_head = nullptr;
	m_tail = nullptr;
}

template <typename T>
bool list<T>::contains(T const& value) const noexcept {
	for (auto n = m_head; n != nullptr; n = n->m_next) {
		if (n->m_value == value) {
			return true;
		}
	}
	return false;
}

template <typename T>
void list<T>::remove(T const& value) noexcept {

}

template <typename T>
std::size_t list<T>::size() const noexcept {
	return m_size;
}

template <typename T>
std::unique_ptr <ml5::iterator <T>> list<T>::make_iterator() {
	return std::make_unique<list_iterator<T>>(m_head);
}