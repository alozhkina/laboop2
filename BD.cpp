#include "BD.h"

BD::BD(const BD& other) {//copy
	kolvo = other.kolvo;
	cap = other.cap;

	pp = new Pair * [cap];
	for (int i = 0; i < kolvo; i++) {
		pp[i] = new Pair;
		*(pp[i]) = *(other.pp[i]);
	}
};

INF& BD::operator [] (const MyString& name) {
	for (int i = 0; i < kolvo; i++) {
		if (pp[i]->Key() == name) {
			return pp[i]->form;
		}
	}
	if (kolvo >= cap) {
		cap += buf;
		Pair** tmp = new Pair * [cap];
		for (int i = 0; i < kolvo; i++) {
			tmp[i] = pp[i];
		}

		delete[] pp;
		pp = tmp;
	}

	pp[kolvo] = new Pair(name, INF());
	return pp[kolvo++]->form;
};

std::ostream& operator<<(std::ostream& out, const INF& form) {
	out << "Sex: " << pereg(form.sex) << "\nAge: " << form.age << "\nSalary: " << form.salary <<
		"\nJob: " << form.job << "\n";
	return out;
};

std::ostream& operator<<(std::ostream& out, const BD& bd) {
	INF form;
	MyString Key;
	std::cout << "\nStaff:\n";
	for (int i = 0; i < bd.kolvo; i++) {
		Key = bd.pp[i]->Key();
		form = bd.pp[i]->Gform();
		out << i + 1 << ". Name: " << Key << "\n" << form << "\n";
	}
	out << "\n";
	return out;
};

void BD::delet(const MyString& str) {
	bool flag = false;
	int no;
	for (int i = 0; i < kolvo; i++) {
		if (pp[i]->Key() == str) {
			flag = true;
			no = i;
			break;
		}
	}
	if (!flag)  return;

	flag = false;
	kolvo--;
	Resize(no, flag);

}
void BD::Resize(int keyNum, bool flag) {
	Pair** tmp = new Pair * [cap]; // ���� ����� �������
	for (int i = 0; i < kolvo + 1; i++) {
		if (i == keyNum) {
			flag = true;
			delete pp[i];
			continue;
		}
		tmp[i - flag] = pp[i];
	}

	delete[] pp;
	pp = tmp;
}


void BD::Job() const {
	INF form;
	std::cout << "\nJob:\n";
	for (int i = 0; i < kolvo; i++) {
		form = this->pp[i]->Gform();
		std::cout << i + 1 << ") " << form.job << "\n";
	}
}

void BD::Salary() const {
	INF form;
	std::cout << "\nSalaries:\n";
	for (int i = 0; i < kolvo; i++) {
		form = this->pp[i]->Gform();
		std::cout << i + 1 << ") " << form.salary << "\n";
	}
}

void BD::Age() const {
	INF form;
	std::cout << "\nAges:\n";
	for (int i = 0; i < kolvo; i++) {
		form = this->pp[i]->Gform();
		std::cout << i + 1 << ") " << form.age << "\n";
	}
}

void BD::Sex() const {
	INF form;
	std::cout << "\nSex:\n";
	for (int i = 0; i < kolvo; i++) {
		form = this->pp[i]->Gform();
		std::cout << i + 1 << ") " << pereg(form.sex) << "\n";
	}
}

void BD::Names() const {
	MyString Key;
	std::cout << "\nNames:\n";
	for (int i = 0; i < kolvo; i++) {
		Key = this->pp[i]->Key();
		std::cout << i + 1 << ") " << Key << "\n";
	}
};

BD::BD(BD&& bd) {
	pp = bd.pp;
	bd.pp = nullptr;
	cap = bd.cap;
	kolvo = bd.kolvo;
	bd.kolvo = bd.cap = 0;
};

BD& BD::operator=(const BD& bd) {
	if (pp == bd.pp) return *this;
	kolvo = bd.kolvo;
	cap = bd.cap;
	for (int i = 0; i < kolvo; i++) {
		if (pp[i] != nullptr) delete pp[i];
	}
	if (pp != nullptr) delete[] pp;//���������

	pp = new Pair * [cap];
	for (int i = 0; i < kolvo; i++) {
		pp[i] = new Pair;
		*(pp[i]) = *(bd.pp[i]);

	}
	return *this;
};

BD& BD::operator = (BD&& other) noexcept {
	kolvo = other.kolvo;
	cap = other.cap;

	delete[] pp;
	pp = other.pp;

	other.pp = nullptr;
	other.kolvo = other.cap = 0;

	return *this;
}