#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
template <typename KeyType>
class Pokemon {
private:
	KeyType key;
	string usName;
	string jpName;
public:

	Pokemon() {
		key = 0;
	}

	Pokemon(KeyType _key, string _usName, string _jpName) {
		this->key = _key;
		this->usName = _usName;
		this->jpName = _jpName;
	}

	Pokemon(const Pokemon<KeyType>& pokem) {
		this->key = pokem.key;
		this->usName = pokem.usName;
		this->jpName = pokem.jpName;
	}

	bool operator<(const Pokemon<KeyType> pokem) const {
		return this->key < pokem.key;
	}

	bool operator<(const KeyType _key) const {
		return this->key < _key;
	}

	bool operator>(const KeyType _key) const {
		return this->key > _key;
	}

	bool operator==(const KeyType _key) const {
		return this->key == _key;
	}


	bool operator>(const Pokemon<KeyType> pokem) const {
		return this->key > pokem.key;
	}

	bool operator==(const Pokemon<KeyType> pokem) const {
		return this->key == pokem.key;
	}


	void operator=(const Pokemon<KeyType>&pokem) {
		this->key = pokem.key;
		this->usName = pokem.usName;
		this->jpName = pokem.jpName;
	}

	friend ostream& operator << (ostream& out, const Pokemon<KeyType>& c) {
		out << "Pokedex number (id): " << c.key << endl;
		out << "US Name: " << c.usName << endl;
		out << "JP Name: " << c.jpName << endl;

		return out;
	}
	friend istream& operator >> (istream& in, Pokemon<KeyType>& c) {
		cout << "Pokedex number (id): "; in >> c.key;
		cout << "US Name: "; in >> c.usName;
		cout << "JP Name: "; in >> c.jpName;
		return in;
	}

};
