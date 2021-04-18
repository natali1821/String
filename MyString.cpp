#include "MyString.h"

MyString::MyString(const char* rawString) {
	if (rawString == 0) {
		this->_size = 0;
		this->_data = nullptr;
	}
	else {
		this->_size = strlen(rawString);
		this->_data = new char[this->_size + 1];
		strcpy(this->_data, rawString);
	}
}

MyString::MyString(const MyString& other) {
	if (other._data == nullptr) {
		this->_size = 0;
		this->_data = nullptr;
	}
	else {
		this->_size = other._size;
		this->_data = new char[this->_size + 1];
		strcpy(this->_data, other._data );
	}
}

MyString::MyString(MyString&& other) noexcept {
	this->_size = other.size();
	this->_data = other._data;
	other._size = 0;
	other._data = nullptr;
}

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		this->_size = other.size();
		delete[] this->_data;
		this->_data = new char[_size + 1];
		strcpy(this->_data, other._data);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept{
	if (this != &other) {
		this->_size = other.size();
		this->_data = other._data;
		other._size = 0;
		other._data = nullptr;
	}
	return *this;
}

MyString::~MyString() {
	delete[] this->_data;
	_data = nullptr;
}

void MyString::append(const MyString& appendedString) {
	this->insert(this->size(), appendedString);
}

void MyString::insert(unsigned int pos, const MyString& insertedString) {
	//assert(pos <= this->size());
	if (pos <= this->size()) {
		int sizeTmp = this->_size + insertedString.size();
		char* tmp = new char[sizeTmp + 1];
		for (int i = 0; i < pos; ++i) {
			tmp[i] = this->_data[i];
		}
		for (int i = 0; i < insertedString.size(); ++i) {
			tmp[i + pos] = insertedString._data[i];
		}
		for (int i = pos + insertedString.size(); i < sizeTmp; ++i) {
			tmp[i] = this->_data[i - insertedString.size()];
		}
		tmp[sizeTmp] = '\0';
		delete[] this->_data;
		this->_data = tmp;
		this->_size = sizeTmp;
	}
	else {
		throw InsertException(*this, pos);
	}

}

void MyString::clear() {
	delete[] this->_data;
	this->_data = nullptr;
	this->_size = 0;
}

void MyString::erase(unsigned int pos, unsigned int count){
	//assert(pos <= this->size());
	if (pos <= this->size()) {
		if (count > (this->_size - pos)) {
			count = this->_size - pos;
		}
		int sizeTmp = this->_size - count;
		char* tmp = new char[sizeTmp + 1];
		for (int i = 0; i < pos; ++i) {
			tmp[i] = this->_data[i];
		}
		for (int i = pos; i < sizeTmp; ++i) {
			tmp[i] = this->_data[count + i];
		}
		tmp[sizeTmp] = '\0';
		delete[] this->_data;
		this->_data = tmp;
		this->_size = sizeTmp;
	}
	else {
		throw EraseException(*this, pos);
	}
}

char& MyString::at(const unsigned int idx) {
	//assert(idx < size());
	if (idx < this->size()) {
		return _data[idx];
	}
	else {
		throw AtException(*this, idx);
	}
}

const char& MyString::at(const unsigned int idx) const {
	//assert(idx < size());
	if (idx < this->size()) {
		return _data[idx];
	}
	else {
		throw AtException(*this, idx);
	}
}

unsigned int MyString::size() const {
	return this->_size;
}

bool MyString::isEmpty() const{
	return (this->_size == 0);
}

const char* MyString::rawString() const {
	char* res = new char[this->size() + 1];
	strcpy(res, this->_data);
	return res;
}

unsigned int MyString::find(const MyString& substring, const unsigned int pos) {
	//assert(pos <= this->size());
	if (pos <= this->size()) {
		int i;
		for (int i = pos; i < this->size() - substring.size() + 1; i++) {
			bool flag = true;
			for (int j = 0; j < substring.size(); j++) {
				if (this->_data[j + i] != substring._data[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return i;
			}
		}
		return -1;
	}
	else {
		throw FindException(*this, pos);
	}
}

int MyString::compare(const MyString& comparableString) const {
	if (this->_size != comparableString._size) {
		return (this->_size - comparableString._size);
	}
	else {
		int i;
		for (i = 0; i < this->_size; ++i) {
			if (this->_data[i] != comparableString._data[i]) {
				break;
			}
		}
		return (this->_data[i] - comparableString._data[i]);
	}
}

char& MyString::operator[](const unsigned int idx) {
	return at(idx);
}

const char& MyString::operator[](const unsigned int idx) const {
	return at(idx);
}

MyString& MyString::operator+(const MyString& appendedString) {
	this->append(appendedString);
	return *this;
}

bool MyString::operator==(const MyString& comparableString) const {
	return (this->compare(comparableString) == 0);
}

bool MyString::operator!=(const MyString& comparableString) const {
	return !(this->compare(comparableString) == 0);
}

bool MyString::operator>(const MyString& comparableString) const {
	return (this->compare(comparableString) > 0);
}

bool MyString::operator<(const MyString& comparableString) const {
	return (this->compare(comparableString) < 0);
}

bool MyString::operator>=(const MyString& comparableString) const {
	return (this->compare(comparableString) >= 0);
}

bool MyString::operator<=(const MyString& comparableString) const {
	return (this->compare(comparableString) <= 0);
}
